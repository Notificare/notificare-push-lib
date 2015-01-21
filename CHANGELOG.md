Changelog
=========
1.3.2   (2015-01-22)
- Added exponential fallback for fetchApplicationInfo and openNotification
- End beacon session on will terminate
- Start Location updates with best accuracy  on ranging and while inside region
- Added check to prevent the same notification to be added to the queue 
- Allow more than one triggered message for the same notification Id in the inbox 
- Removed register device on every add/remove segment for OAuth2
- Removed OAuth2 metrics AddSegment/RemoveSegment
- Removed local notification for OAuth2 invalid grant error 
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
