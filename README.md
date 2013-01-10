Notificare Push Library
===================

Notificare Push Library implements the power of smart notifications provided by the Notificare platform.

Before you start, please ensure that your app has been enabled for Apple Push Notifications service. This has to be done through the developer portal.

Once you have enabled push notifications, please create a Notificare account on the following  URL:

http://notifica.re/sign-up

After validating your account, please sign in and click the applications tab. Create an application (we strongly advise to create an application for development and production) and use the keys in the Notificare.plist that you can find in this project. 

Drag the files in this project to your Xcode project. Go to your targets and click the Build Phases separator. In the Link Binaries with Libraries area add the following frameworks:

- libicucore.dylib
- UIKit.framework
- Foundation.framework
- CoreGraphics.framework
- PassKit.framework
- SystemConfiguration.framework
- Security.framework
- CFNetwork.framework

Then access the Build Settings tab and search for Other Linker Flags, add the following:

	-all_load

After these steps you can start implementing the Notificare Library.

In your AppDelegate.h start by importing the library by using:

``` objective-c

#import "NotificarePushLib.h"
```

And then in your interface include the delegate NotificarePushLibDelegate.

Then in your AppDelegate.m in the method didFinishLaunchingWithOptions add the following:

``` objective-c

[[NotificarePushLib shared] launch];

[[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];
    
if([launchOptions objectForKey:@"UIApplicationLaunchOptionsRemoteNotificationKey"]){

	[[NotificarePushLib shared] openNotification:[launchOptions objectForKey:@"UIApplicationLaunchOptionsRemoteNotificationKey"]];
}
```


And finally add the following delegate methods:

``` objective-c

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    
	[[NotificarePushLib shared] registerDevice:deviceToken];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error{
    
	NSLog(@"%@",error);
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

	[[NotificarePushLib shared] openNotification:userInfo];
}
```

If you wish to use web sockets instead of APN's in your AppDelegate.m, anywhere you might find convenient, include the following:


``` objective-c

[[NotificarePushLib shared] registerForWebsockets];
[[NotificarePushLib shared] setDelegate:self];
```

This will open a connection with the web sockets server and generate an UUID for your device. In order to actually register this device implement the following delegates:

``` objective-c

-(void)notificarePushLib:(NotificarePushLib *)library didRegisterForWebsocketsNotifications:(NSString *)token{

	[[NotificarePushLib shared] registerDeviceForWebsockets:token];
}

-(void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterWebsocketNotifications:(NSError *)error{

	NSLog(@"%@",error);
}
```

Finally just implement the delegate that actually receives the web sockets message, by doing the following:

``` objective-c

-(void)notificarePushLib:(NotificarePushLib *)library didReceiveWebsocketNotification:(NSDictionary *)info{
    
	[[NotificarePushLib shared] openNotification:info];
}
```





