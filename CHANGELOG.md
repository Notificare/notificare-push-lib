Changelog
=========
1.12.1 (2017-11-28)
- Add more protective checks for open/received/influenced events
- Add exponentials retries for received/influenced events
- Add more protective checks for coordinates in load nearest fences

1.12.0 (2017-10-30)
- Removed CoreNFC from included frameworks (Core NFC methods must now be implemented manually to avoid problems with Apple's approval process for clients not using CoreNFC features)

1.11.0 (2017-10-24)
- Introducing machine-readable object (extra) in asset groups items
- Added URL encoding for group name in fetchAssets
- Using singleton class app keys in reply upload file

1.10.1 (2017-10-16)
- Added handling of Launch Options URL key for other destinations other than reset password and validate

1.10.0 (2017-09-18)
- Built for iOS 11.0 SDK
- Removed support for WebSockets
- Added support for Scannables (NFC & QR Code scanner)
- Some fine tuning for geo-fencing with polygons
- Added pre-processor flag to exclude PassKit
- Added Registration event for first registration after install

1.9.10  (2017-07-10)
- Handle notificareCloseWindow query parameter for URL notification type when using UIWebView
- Handle itms URL scheme in Rate notification type for pre iOS 10.3
- Fixed issue with empty action target for actions of type Callback

1.9.9  (2017-04-24)
- Added CLOSE_WINDOW_QUERY_PARAMETER property in OPTIONS
- Handle notificareCloseWindow query parameter for WebViews
- Added new method for custom headers with Cloud API
- Added parameters for App Recommendation for campaign, provider, affiliates and advertisers tokens

1.9.8  (2017-04-02)
- Built for 10.3 SDK
- Added new App Rating built-in view in Rate notification type
- Added App Recommendation notification type
- Added register and unregister userIDs for OAuth2 accounts

1.9.7  (2017-03-17)
- Hotfix for device registration when using oauth2 library

1.9.6  (2017-02-14)
- Hotfix for notification center when setting keys manually
- Discard distant future departures from VISITS API

1.9.5  (2017-01-23)
- Hotfix for keyboard/camera actions in rich content views
- Hotfix for protective checks in refresh badge

1.9.4  (2017-01-20)
- Added check for refreshBadge configurations
- Added fallback for wallet passes in iPad
- Added configuration property for Visits and Heading API
- Added advanced geometry methods
- Removed headers from debug messages in network classes
- Changed device registration to cache token only for 1 day
- Protective checks for null deviceIDs

1.9.3  (2016-10-13)
- Hotfix for crashes related to unified logging in iOS8

1.9.2  (2016-09-30)
- Hotfix for crashes in initializing lib in iOS8 and below
- Added UNNotificationPresentationOptions to customize in-app alerts

1.9.1  (2016-09-23)
- Changed network lib property names so they don't clash with private apis
- Added system and systemType push for silent notifications

1.9.0  (2016-09-14)
- Built against SDK 10
- Removed MKNetWorkKit in favour of our own network library
- Fixed header docs
- Added new iOS10 notification center
- Added new iOS10 unified logging
- Added a new managed inbox with device storage in Core Data
- Added generic api endpoint for the Cloud API
- Added helper method for Notification Service Extensions
- Protective checks for notification's content
- Added allowedUI property of device
- Added new user data methods for rich device profiles
- Fixed issue with modal views when handling notifications
- Better app lifecycle event handling
- Several small bugfixes and performance improvements

1.8.4  (2016-07-21)
- Hotfix for PUT requests introduced in 1.8.3

1.8.3  (2016-07-14)
- Added nonnull and nullable properties in Models
- Added new methods for Do Not Disturb
- Fixed typos in header file
- Fixed an issue with timeAgo method

1.8.2  (2016-06-13)
- Fixed issue with last character of actions of type Response with Keyboard & Camera
- Added crash reports
- Added helper method for assets URLs
- Fixed issue with the triggers properties of beacon objects

1.8.1  (2016-05-18)
- Fixed language format to match all platforms
- Added userID and deviceID to fetchAssets
- Added check for empty key and metaData in fetchAssets

1.8.0  (2016-04-11)
- Added new API methods for Assets
- Added check for application state when loggin application Open log
- Changed Influenced event to be logged on notification open method
- Added new notification type None (new default when unknown namespace is provided)
- Added new notification type URLScheme
- Added new notification type Video
- Fixed issue with since date on fetchInbox in refreshBadge method
- Fixed race condition when logging appVersion

1.7.4  (2016-03-08)
- Fixed issue with OPTIONS > USE_SAFARI_VIEW property of Notificare.plist
- Fixed crash with retries of notification open logs

1.7.3  (2016-03-01)
- Fixed issue with requestStateForRegion for beacon regions with UUID + major

1.7.2  (2016-02-22)
- Removed unregisterUserNotifications in favour of [[UIApplication sharedApplication] unregisterForRemoteNotifications];

1.7.1  (2016-02-08)
- Added unregisterForNotifications and unregisterUserNotifications
- Check for null location in location manager
- Hotfix for lastRegisteredDate in unregisterDevice

1.7.0  (2016-01-23)
- Added new server-side inbox methods
- Deprecated device inbox methods
- Deprecated saveToInbox in favour of handleNotification
- Added plist OPTION keys USE_TEST_API, USE_SAFARI_VIEW and URL_SCHEMES
- Added delegate didClickURL:inNotification: for events inside UIWebViews
- Fixes for stop monitoring for individual beacons after exiting a region

1.6.5  (2015-12-18)
- Fixed issue with size of WebView controller in URL push
- Added attribute to keychain insert item to allow keychain to be accessed even when device is locked
- Fixed problem introduce in 1.6.3 with callback actions with no target that prevented replies
- Removed check for added passes allowing passes to be always open on a push notification even if already in Wallet
- Built against SDK 9.2

1.6.4  (2015-11-30)
- Fixes issue with Done button of SafariViewController that prevents future messages from appearing

1.6.3  (2015-11-28)
- Fixes crash when clicking actions in rich content push on iPad
- Better keyboard handling in keyboard actions
- Fixes a problem with opening rich content views when other views are initiated before UIWindow

1.6.2  (2015-11-02)
- Hotfix for event’s retries & reachability
- Added update user notifications settings on language change

1.6.1  (2015-10-27)
- Corrections in headerdocs
- Fixes for colours in SafariViewController navigation bar
- Added Localizable strings for action categories
- Added logInfluencedOpenNotification method
- Added clearInbox method
- Dropped support for iOS6
- Built against SDK 9.1

1.6.0  (2015-09-18)
- Changes in openNotification to prioritised messages previously loaded
- Added iOS9 Text Input in actions with keyboard
- Changed to SFSafariViewController for URL push (new SafariServices.framework needed)
- Enabled bitcode export (for App Thinning)
- Built against SDK 9 (please update to Xcode 7)


1.5.9   (2015-08-25)
- Several improvements on geofencing and beacons monitoring based on extensive field testing

1.5.8   (2015-08-08)
- Added management of new loaded fences on location updates
- Added clean up of current regions list to didDetermineState 
- Added check for empty image and fallback for text on send button
- Added retries with delay for triggers

1.5.7   (2015-08-04)
- Removed double check in didDetermineState
- Added new delegate for handling custom type actions

1.5.6   (2015-07-27)
- Clear session on didDetermineState for both beacons and regions

1.5.5   (2015-07-23)
- Added deviceID and userID to open/close application events
- Added deviceID and userID to upgrade application events
- Added country property of NotificareDevice
- Added reverse geocode query to calculate country at every location update 
- Added check in ranging beacons for current active fences
- Removed check in exit event
- Removed methods in state
- Added log last location on enter and exit events
- Built against iOS 8.4 SDK

1.5.4   (2015-06-13)
- Added hit test region for iOS7 and up
- Changed deprecated clear notification endpoint
- Added check for location services
- Added possibility to override the apiID and apiSecret
- Fixed bug in didReceiveLocationServiceAuthorizationStatus delegate that prevented it to be triggered always after startLocationUpdates

1.5.3   (2015-05-24)
- Added public method registerUserNotifications
- Added formatted payload for WebSockets notifications
- Fixed bug with empty beacon region when stop monitoring
- Removed Passbook Add event will be added by API
- Fixed bug with lastRegistered date

1.5.2   (2015-05-14)
- Double check for didExit regions on didDetermineState

1.5.1   (2015-05-01)
- Updated to iOS SDK 8.3
- Added last registered check in registerDevice
- Added old device in registerDevice when different

1.5.0   (2015-04-24)
- Fixes in saveToInbox related to messages received when in an inactive state
- Added new metric re.notifica.event.pass.Add when adding pass to Passbook
- Added -(NSArray *)myPasses method for a list of passes added to Passbook for this application
- Added queues for enter/exit triggers 
- Added support for silent push
- Added reload of UIUserNotificationSettings on silent push

1.4.3   (2015-02-27)
- Fix for geo triggered notifications when launching the app inside a region
- Added new Passbook view

1.4.2   (2015-02-21)
- Added new event log for passes added to passbook
- Added new error codes for gateway timeouts
- Added network errors check for retries 
- Added possibility to use less than two iOS8 actionable buttons  
- Added better cell refresh in inbox

1.4.1   (2015-02-11)
- Fix for local notification key in launch options dictionary
- Added checks for empty/nil values on register device
- Added start of monitoring of beacons in didDetermineState (inside) of a CLRegion

1.4.0   (2015-01-30)
- Added user defaults for device properties, current regions and current beacons
- Check for device properties when registering the device to prevent useless requests
- Added current regions and beacons list to prevent an enter before an exit
- Added better session handling for regions and beacons
- Added regions and beacon sessions to NSUserDefaults for better persistence
- Added retry on error for logs and triggers
- Fixes for unidentified or missing logs when app is inactive
- Fixes for duplicated or unnecessary logs
- Added new NotificareDevice model and myDevice property object, deprecated user/device related properties

1.3.2   (2015-01-22)
- Added exponential fallback for fetchApplicationInfo and openNotification
- End beacon session on will terminate
- Start Location updates with best accuracy  on ranging and while inside region
- Added check to prevent the same notification to be added to the queue 
- Allow more than one triggered message for the same notification Id in the inbox 
- Removed register device on every add/remove segment for OAuth2
- Removed OAuth2 metrics AddSegment/RemoveSegment
- Removed local notification for OAuth2 invalid grant error 
- Better fetchApplication handling on becoming active
- Added precompiled flag to ignore assertions
 
1.3.1   (2015-01-08)
- Reset account on new install
- Register device if account exists on launch
- Update inbox on same notification received
- Several minor changes for better region & beacon monitoring

1.3.0   (2015-01-05)
- added fix for invalid grant
- changed beacon session to a NSDictionary
- changed triggers to didEnterRegion and didExitRegion
- changed sendPassword, resetPassword and changePassword to accept a NSString
- Deprecated several methods
- Better headerdocs comments with sample code and discussion

1.2.3	(2014-12-15)
- added fallback for start for cordova

1.2.2	(2014-12-10)
- hide values in debug logs
- fall back for bundle display name
- added new metric event application upgrade

1.2.1	(2014-12-05)
- hot fix for mknetworkkit reachability problem

1.2.0	(2014-12-03)
- new artwork for iphone 6
- added new beacon properties
- updated MKNetworkKit library
- added in-app purchase
