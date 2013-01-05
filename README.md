Notificare Push Library
===================

Notificare Push Library implements the power of smart notifications provided by the Notificare platform.

Before you start, please ensure that your app has been enabled for Apple Push Notifications service. This has to be done through the developer portal.

Once you have enabled push notifications, please create a Notificare account on the following  URL:

http://notifica.re/sign-up

After validating your account, please sign in and click the applications tab. Create an application (we strongly advise to create an application for development and production) and use the keys in the Notificare.plist that you can find in this project. 

Drag the files in this project to your Xcode project. Go to your targets and click the Build Phases separator. In the Link Binaries with Libraries area add the following frameworks:

UIKit.framework
Foundation.framework
CoreGraphics.framework
PassKit.framework
SystemConfiguration.framework
Security.framework
CFNetwork.framework

Then access the Build Settings tab and search for Other Linker Flags, add the following:

-all_load

After these steps you can start implementing the Notificare Library.

In you AppDelegate.m start by importing the library by using:

#import "NotificarePushLib.h"

Then in didFinishLaunchingWithOptions add the following:

[[NotificarePushLib shared] launch];

[[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];
    
if([launchOptions objectForKey:@"UIApplicationLaunchOptionsRemoteNotificationKey"]){
	[[NotificarePushLib shared] openNotification:[launchOptions objectForKey:@"UIApplicationLaunchOptionsRemoteNotificationKey"]];
}


And finally add the following delegate methods:

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    
    [[NotificarePushLib shared] registerDevice:deviceToken];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    
    NSLog(@"%@",error);
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
   
    [[NotificarePushLib shared] openNotification:userInfo];
}



