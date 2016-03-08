Changelog
=========

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
