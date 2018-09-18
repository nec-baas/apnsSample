//
//  ViewController.m
//

#import "ViewController.h"
#import "AppDelegate.h"
#import "nebulaIosSdk/Nebula.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *deviceTokenLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(didReceiveDeviceToken)
               name:@"didReceiveDeviceToken" object:nil];

    [nc addObserver:self selector:@selector(didReceivePush:) name:@"didReceivePush" object:nil];
}

- (void)didReceiveDeviceToken
{
    NBPushInstallation *installation = [NBPushInstallation currentInstallation];
    self.deviceTokenLabel.text = installation.deviceToken;
    
    //[self showAlertWithTitle:@"Got device token" message:token];
}

- (void)didReceivePush:(NSNotification *)notification
{
    NSDictionary *aps = notification.userInfo;

    NSString *alert = aps[@"alert"][@"body"];
    [self showAlertWithTitle:@"Push" message:alert];
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

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
