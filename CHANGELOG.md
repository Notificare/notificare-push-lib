Changelog
=========
2.4-beta2 (2020-07-24)
- Make sure you immediatly update device properties after authorization changes 
- Free up location updates after changing to while in use or reduced accuracy 
- Added requestTemporaryFullAccuracyAuthorizationWithPurposeKey method 
- Fixed some comments in interface file

2.4-beta1 (2020-07-21)
- Built with iOS 14 SDK
- Added new events for unknown notifications in background and foreground
- Adopted changes for Location Services in iOS 14
- Small adjustment in app store recommendation to avoid object sorting issue
- Added markAllAsRead in InboxManager
- Added helper method for universal links

2.3.2 (2020-06-19)
- Added CoreMedia framework

2.3.1 (2020-06-18)
- Hot fix that solves a potential crash in unlaunch method 

2.3.0 (2020-06-17)
- Added new unlaunch method
- Added possibility to send notification not shown in the inbox
- Added possibility to expire inbox items
- Added new property type in NotificareDeviceInbox model
- Added new properties in Notificare.plist under OPTIONS for Light/Dark mode
- Minor bug fixes and improvements
- Deprecated didChangeAccountState and didFailToRenewAccountSessionWithError delegates
- Deprecated [[[NotificarePushLib shared] authManager] logoutAccount]
- Using CoreServices.framework when available
- Built against iOS 13.5 SDK

2.2.6 (2020-02-19)
- Removed background tasks from app close event and geo location with polygons

2.2.5 (2020-02-13)
- Moved notification open event to viewDidLoad in UIViewController notification types
- Added increase/restore brightness on web passes view

2.2.4 (2019-11-18)
- Fixed issue for notification types without UI being presented without user interaction while app was in foreground/background
- Refactored how notification lifecycle events are triggered
- Fixed issue with sort of images in notification of type Images
- Refactored Rate notification type to account with review limits

2.2.3 (2019-11-08)
- Fixed issue with handling non-main frame HTML elements in WebPage and HTML notification types
- Added support for JS alert, confirm and prompt in WebPage and HTML notification types 
- Hide actions button when notificareOpenAction and notificareOpenActions query params are used in WebPage and HTML notification types 
- Prevent navigation when known parameters are used in WebPage and HTML notification types
- Added strong references to Notificare and NotificareActions delegates

2.2.2 (2019-10-23)
- Added static_framework = true in podspec

2.2.1 (2019-10-17)
- Built with iOS13.1 SDK
- Fixed issue with actions of type Response when only Open Camera is checked
- Fixed issue with Callback toolbar tint style
- Added OPTIONS property override for the actions button

2.2.0 (2019-09-12)
- Built with iOS13 SDK (Update to Xcode 11 to use this version)
- Added DISABLE_LOCATION_SERVICES property under OPTIONS in Notificare.plist
- Added clearDeviceLocation
- Adopted new Core Location API for beacons

2.1.6 (2019-09-09)
- Hotfix to prevent launchOptions crash

2.1.5 (2019-08-22)
- Bump version in definitions file

2.1.4 (2019-08-22)
- Added protective check when no country code can be retrieved
- Run launchOptions in main thread for safety

2.1.3 (2019-08-06)
- Optimized launch options to be execute after onReady (if applicable)

2.1.2 (2019-07-18)
- Added delay when executing didReceiveLaunchURL

2.1.1 (2019-06-20)
- Fixed issue with asset URL when no file is used
- Made handleOptions accept nullable options

2.1.0 (2019-04-29)
- Added helper method to retrieve controller for notification
- Added new delegate method didChangeNotificationSettings
- Added handling presentation options via a push notification

2.0.1 (2019-03-19)
- Fixed issue with surrogate delegate

2.0.0 (2018-09-13)
- Initial 2.0.0 beta release
