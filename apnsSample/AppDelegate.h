//
//  AppDelegate.h
//

#import <UIKit/UIKit.h>
#import <PushKit/PushKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, PKPushRegistryDelegate>

@property (strong, nonatomic) UIWindow *window;
//@property (readonly, nonatomic) NSString *deviceTokenString;

+ (AppDelegate *)sharedInstance;

@end

