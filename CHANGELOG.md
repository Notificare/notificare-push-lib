Changelog
=========
2.7-beta1 (2021-07-12)
- Built with iOS 15
- Added new method to handle lock screen media, interruption level and relevance score

2.6.1 (2021-06-10)
- Added protective checks for regions and beacons sessions

2.6.0 (2021-04-28)
- Built with iOS 14.5
- Added test device registration
- Fixed issue with handling validate and resetpassword from launch URL

2.5.2 (2021-03-17)
- Added protective checks for notification title when used in alert and view controllers 

2.5.1 (2021-02-15)
- Fixed issue with reply of type Email not being registered after mail sent
- Added correct mime type for video uploads
- Fixed issue with crash reporter that could potentially crash the app

2.5.0 (2020-12-18)
- Built with Xcode 12.3 with support for iOS 14.3

2.5-beta4 (2020-12-14)
- Use UNNotificationPresentationOptionBanner instead of UNNotificationPresentationOptionAlert in iOS14

2.5-beta3 (2020-12-07)
- Built with Xcode 12.2 with support for iOS 14.2

2.5-beta2 (2020-10-06)
- Added protective checks for notification objects when handling notifications
- Enforce NSString casting when createing managed model inbox objects
- Added silent warning when failing to load managed models into persistent store

2.5-beta1 (2020-10-25)
- Added alternative methods for a non-managed UNUserNotificationCenter
- Added DnD data in device's object
- Added completion handler when updating a temporary device

2.4.0 (2020-09-16)
- Built with Xcode 12 GM seed

2.4-beta7 (2020-09-02)
- Added target content identifier to notification model
- Use notification title (when present) in UIAlertController or UIViewController instead of app name

2.4-beta6 (2020-08-25)
- Added fetchLink to manually retrieve the underlying iOS URL in a Dynamic Link
- Added support for Notificare's Dynamic Links in notification of type Deep Link

2.4-beta5 (2020-08-20)
- Added new method for continueUserActivity for UIScene and SwiftUI based apps
- Added better error logging for requestTemporaryFullAccuracyAuthorizationWithPurposeKey

2.4-beta4 (2020-08-14)
- Assigned authorization status and accuracy authorization as soon as possible

2.4-beta3 (2020-08-12)
- Marked locationServicesAuthStatus and locationServicesAccuracyAuth as nullable

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
