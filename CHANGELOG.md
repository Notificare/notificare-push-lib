Changelog
=========
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
