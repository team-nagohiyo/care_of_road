#import <UIKit/UIKit.h>

//UnityAds
#import <UnityAds/UnityAds.h>

@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate ,UnityAdsDelegate> {
    UIWindow *window;
}

@property(nonatomic, readonly) RootViewController* viewController;

@end

