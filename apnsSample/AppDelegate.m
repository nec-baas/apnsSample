//
//  AppDelegate.m
//

#import "AppDelegate.h"
#import "nebulaIosSdk/Nebula.h"
#import "Config.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

AppDelegate *_theInstance;

+ (AppDelegate *)sharedInstance {
    return _theInstance;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    _theInstance = self;

    // Nebula 初期化
    [NBCore setUpWithAppId:APP_ID appKey:APP_KEY tenantId:TENANT_ID];
    [NBCore setEndPointUri:ENDPOINT_URI];
    
    if (!VOIP_PUSH) {
        // APNS 用登録処理 (通常 Push)
        UIUserNotificationType type = UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound;
        UIUserNotificationSettings *setting = [UIUserNotificationSettings settingsForTypes:type categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:setting];
    }
    else {
        // PushKit 登録処理
        dispatch_queue_t mainQueue = dispatch_get_main_queue();
        PKPushRegistry *voipRegistry = [[PKPushRegistry alloc] initWithQueue:mainQueue];
        voipRegistry.delegate = self;
        voipRegistry.desiredPushTypes = [NSSet setWithObject:PKPushTypeVoIP];
    }

    return YES;
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
    [[UIApplication sharedApplication] registerForRemoteNotifications];
}

// デバイストークンの通知受領処理 (通常 Push)
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSLog(@"didRegisterForRemoteNotificationWithDeviceToken: %@", deviceToken);
    [self registerDeviceToken:deviceToken];
}

// デバイストークンの通知受領処理 (PushKit)
-(void)pushRegistry:(PKPushRegistry *)registry didUpdatePushCredentials:(PKPushCredentials *)credentials forType:(NSString *)type {
    NSLog(@"pushRegistry:didUpdatePushCredentials: %@", credentials.token);
    [self registerDeviceToken:credentials.token];
}

- (void)registerDeviceToken:(NSData *)deviceToken {
    // サーバへインスタレーション登録
    NBPushInstallation *installation = [NBPushInstallation currentInstallation];
    [installation setDeviceTokenFromData:deviceToken];

    // 購読チャネルの設定
    installation.channels = @[@"channel1"];

    // allowed senders の設定
    installation.allowedSenders = @[@"g:anonymous"];

    [installation saveInBackgroundWithBlock:^(NBPushInstallation *installation, NSError *error) {
        if (!error) {
            // 正常登録完了
            NSLog(@"register succeeded.");
        } else {
            // 登録エラー
            NSLog(@"register failed");
            [self showAlertWithTitle:@"Error" message:@"Register failed"];
        }
    }];
    
    // アプリ内の別コンポーネントに通知
    [[NSNotificationCenter defaultCenter] postNotificationName:@"didReceiveDeviceToken" object:nil];
}

// Push 受信(通常)
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [self didReceiveRemoteNotification:userInfo];
}

// Push 受信(PushKit)
-(void)pushRegistry:(PKPushRegistry *)registry didReceiveIncomingPushWithPayload:(PKPushPayload *)payload forType:(NSString *)type {
    [self didReceiveRemoteNotification:payload.dictionaryPayload];
}

// Push 受信
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo {
    for (id key in userInfo) {
        NSLog(@"key %@ : value %@", key, userInfo[key]);
    }

    NSDictionary *aps = userInfo[@"aps"];
    NSString *alert = aps[@"alert"][@"body"];
    //[self showAlertWithTitle:@"Push received" message:alert];
    
    // local 通知すべてキャンセル
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
    
    // local 通知を出す
    UILocalNotification *n = [UILocalNotification new];
    n.fireDate = [NSDate dateWithTimeIntervalSinceNow:0];
    n.timeZone = [NSTimeZone defaultTimeZone];
    n.alertBody = alert;
    n.soundName = UILocalNotificationDefaultSoundName;
    n.alertAction = @"OPEN";
    
    [[UIApplication sharedApplication] scheduleLocalNotification:n];
    
    // アプリ内の別コンポーネントに通知
    [[NSNotificationCenter defaultCenter] postNotificationName:@"didReceivePush" object:self userInfo:aps];
}

// AlertView 表示
- (void)showAlertWithTitle:(NSString *)title message:(NSString *)message
{
    [[[UIAlertView alloc] initWithTitle:title
                                message:message
                               delegate:nil
                      cancelButtonTitle:nil
                      otherButtonTitles:@"Dismiss", nil] show];
}

// NSData を hex string に変換
- (NSString *)hexString:(NSData *)data
{
    const unsigned char *bytes = (const unsigned char *)data.bytes;
    NSUInteger len = data.length;
    
    NSMutableString *s = [NSMutableString stringWithCapacity:len * 2];
    for (NSUInteger i = 0; i < len; i++) {
        [s appendString:[NSString stringWithFormat:@"%02x", (unsigned int)bytes[i]]];
    }
    return s;
}

- (void)applicationWillResignActive:(UIApplication *)application {
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
}

@end
