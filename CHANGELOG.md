Changelog
=========

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
