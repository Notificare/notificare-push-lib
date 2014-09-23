//
//  NotificarePushLib.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
//
//

#import "NotificareEngine.h"
#import "NSData+Hex.h"
#import "Notificare.h"
#import "NotificareActions.h"
#import "NotificareSRWebSocket.h"
#import "NotificareNotification.h"
#import <CoreLocation/CoreLocation.h>
#import "NSString+Utils.h"
#import "NotificareNXOAuth2.h"

#define Suppressor(Selector) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Selector; \
_Pragma("clang diagnostic pop") \
} while (0)

typedef void (^SuccessBlock)(NSDictionary * info);
typedef void (^ErrorBlock)(NSError * error);

typedef enum  {
    kNotificareErrorCodeBadRequest = 400,
    kNotificareErrorCodeUnauthorized = 401,
    kNotificareErrorCodeForbidden = 403,
    kNotificareErrorCodeNotFound = 404,
    kNotificareErrorCodeConflict = 409,
    kNotificareErrorCodeUnprocessableEntity = 422,
    kNotificareErrorCodeInternalServerError = 500,
    kNotificareErrorCodeGatewayTimeout = 504
} kNotificareErrorCode;

@class NotificarePushLib;

@protocol NotificarePushLibDelegate <NSObject>

@optional

- (void)notificarePushLib:(NotificarePushLib *)library onReady:(NSDictionary *)info;

- (void)notificarePushLib:(NotificarePushLib *)library didRegisterForWebsocketsNotifications:(NSString *)token;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveWebsocketNotification:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterWebsocketNotifications:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didCloseWebsocketConnection:(NSString *)reason;

- (BOOL)notificarePushLib:(NotificarePushLib *)library shouldHandleNotification:(NSDictionary *)info;

- (void)notificarePushLib:(NotificarePushLib *)library didUpdateBadge:(int)badge;
- (void)notificarePushLib:(NotificarePushLib *)library willOpenNotification:(NotificareNotification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didOpenNotification:(NotificareNotification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didCloseNotification:(NotificareNotification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToOpenNotification:(NotificareNotification *)notification;

- (void)notificarePushLib:(NotificarePushLib *)library willExecuteAction:(NotificareNotification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelector:(NSString *)selector;
- (void)notificarePushLib:(NotificarePushLib *)library didNotExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToExecuteAction:(NSError *)error;

- (void)notificarePushLib:(NotificarePushLib *)library didFailToStartLocationServiceWithError:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveLocationServiceAuthorizationStatus:(NSDictionary *)status;
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateLocations:(NSArray *)locations;
- (void)notificarePushLib:(NotificarePushLib *)library monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didStartMonitoringForRegion:(CLRegion *)region;
- (void)notificarePushLib:(NotificarePushLib *)library didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;
- (void)notificarePushLib:(NotificarePushLib *)library didEnterRegion:(CLRegion *)region;
- (void)notificarePushLib:(NotificarePushLib *)library didExitRegion:(CLRegion *)region;
- (void)notificarePushLib:(NotificarePushLib *)library rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;

- (void)notificarePushLib:(NotificarePushLib *)library didChangeAccountNotification:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRequestAccessNotification:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveActivationToken:(NSString *)token;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveResetPasswordToken:(NSString *)token;


@end

@interface NotificarePushLib : NSObject <NotificareSRWebSocketDelegate,NotificareDelegate,NotificareActionsDelegate,CLLocationManagerDelegate>

/*!
 *  @abstract Public delegate to handle Notificare events
 *  @property NotificarePushLibDelegate
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
@property (nonatomic, assign) id <NotificarePushLibDelegate> delegate;


/*!
 *  @abstract The Noticare network requests class
 *  @property NotificareEngine
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
@property (strong, nonatomic) NotificareEngine * notificareEngine;

@property (strong, nonatomic) Notificare * notificare;

@property (strong, nonatomic) Notificare * currentNotificare;

@property (strong, nonatomic) NotificareActions * notificareActions;


/*!
 *  @abstract the apiID key
 *  @property apiID
 *
 *  @discussion
 *	Returns the apiID
 *
 */
@property (strong, nonatomic) NSString * apiID;
/*!
  *  @abstract The apiSecret key
  *  @property apiSecret
  *
  *  @discussion
  *  Return the apiSecret
  *
  */
@property (strong, nonatomic) NSString * apiSecret;

/*!
 *  @abstract The device Token
 *
 *  @discussion
 *	Returns the device Token 
 *
 */
@property (strong, nonatomic) NSString * deviceToken;

/*!
 *  @abstract The raw device Token
 *
 *  @discussion
 *	Returns the raw device Token
 *
 */
@property (strong, nonatomic) NSData * deviceTokenData;

/*!
 *  @abstract The device UUID
 *
 *  @discussion
 *	Returns the device UUID
 *
 */
@property (strong, nonatomic) NSString * deviceUUID;

/*!
 *  @abstract The device
 *
 *  @discussion
 *	Returns the device 
 *
 */
@property (strong, nonatomic) NSString * device;

/*!
 *  @abstract The userID
 *
 *  @discussion
 *	Returns the userID
 *
 */
@property (strong, nonatomic) NSString * userID;

/*!
 *  @abstract The oAuth account
 *
 *  @discussion
 *	Returns the account object
 *
 */
@property (strong, nonatomic) NotificareNXOAuth2Account * account;


/*!
 *  @abstract The username
 *
 *  @discussion
 *	Returns the username
 *
 */
@property (strong, nonatomic) NSString * username;

/*!
 *  @abstract The notificationTypes
 *
 *  @discussion
 *	Returns the notificationTypes
 *
 */
@property (nonatomic, assign) UIRemoteNotificationType notificationTypes;

/*!
 *  @abstract Boolean for checking if notification is open
 *
 */
@property (assign) BOOL isOpen;

/*!
 *  @abstract Boolean for checking if position is being fixed
 *
 */
@property (assign) BOOL isFixingGPS;


/*!
 *  @abstract Boolean for checking if notification is open
 *
 */
@property (assign) BOOL displayMessage;

/*!
 *  @abstract CLRegion Object for the current Fence
 *
 */
@property (strong, nonatomic) CLRegion * currentFence;

/*!
 *  @abstract An array with notifications to be displayed
 *
 *  @discussion
 *	Returns all queued notifications
 *
 */
@property (strong, nonatomic) NSMutableArray * notificationQueue;

/*!
 *  @abstract Active notification
 *
 *  @discussion
 *	Returns the active notification
 *
 */
@property (strong, nonatomic) NSDictionary * activeNotification;

/*!
 *  @abstract Location Manager
 *
 *  @discussion
 *	Core Location Manager that handles significant change updates
 *
 */
@property (strong, nonatomic) CLLocationManager *locationManager;

/*!
 *  @abstract Last Locations
 *
 *  @discussion
 *	A mutable array that holds lasts readings from Core Location
 *
 */
@property (strong, nonatomic) NSMutableArray *lastLocations;

/*!
 *  @abstract Region Session Data
 *
 *  @discussion
 *	A mutable dictionary that holds hold the enter/exit time and location updates
 *
 */
@property (strong, nonatomic) NSMutableArray * regionSession;


/*!
 *  @abstract Beacon Session Data
 *
 *  @discussion
 *	A mutable dictionary that holds hold the range time in each of the beacons in range
 *
 */
@property (strong, nonatomic) NSMutableArray * beaconSession;

/*!
 *  @abstract Beacon Region
 *
 *  @discussion
 *	A iBeacon region with UUID loaded from plist
 *
 */
@property (strong, nonatomic) CLBeaconRegion *beaconRegion;

/*!
 *  @abstract shouldAllwaysLogBeacons flag
 *  @discussion
 *	A BOOL to flag the library to log all the beacons changes in range and location
 *  This will result in an increase on storage since it will save the location and proximity when beacons are ranging
 *  Leaving this option out will just log each beacon once if found in range.
 */

@property (nonatomic, assign) BOOL shouldAlwaysLogBeacons;

/*!
 *  @abstract Ranging flag
 *  @discussion
 *	A BOOL to flag when iBeacon is in range
 */
 
@property (nonatomic, assign) BOOL ranging;

/*!
 *  @abstract Application info
 *
 *  @discussion
 *	Returns application's public
 *
 */
@property (strong, nonatomic) NSDictionary * applicationInfo;

/*!
 *  @abstract Geo-fences
 *
 *  @discussion
 *	Returns Regions being monitored
 *
 */
@property (strong, nonatomic) NSMutableArray * geofences;


/*!
 *  @abstract Beacons
 *
 *  @discussion
 *	Returns Beacons being monitored
 *
 */
@property (strong, nonatomic) NSMutableArray * beacons;

/*!
 *  @abstract Log of entries in a region
 *
 *  @discussion
 *	Returns an array of regions that were triggered by entry
 *
 */
@property (strong, nonatomic) NSMutableArray * stateEntries;

/*!
 *  @abstract Beacons
 *
 *  @discussion
 *	Returns an array of beacons that were triggered by entry
 *
 */
@property (strong, nonatomic) NSMutableArray * stateBeacons;


/*!
 *  @abstract The shared singleton implementation
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
+(NotificarePushLib*)shared;

/*!
 *  @abstract Initial setup
 *
 *  @discussion
 *  Initializes, checks and retrieves memory data
 */
- (void)launch;

/*!
 *  @abstract Register for APNS
 *
 *  @discussion
 *  Registers for APNS
 */
- (void)registerForRemoteNotificationsTypes:(UIRemoteNotificationType)types __attribute__((deprecated("use registerForNotifications instead.")));;

/*!
 *  @abstract Register for APNS
 *
 *  @discussion
 *  Registers for User Notifications and Remote Notifications (since iOS8)
 */
- (void)registerForNotifications;

/*!
 *  @abstract Handle didFinishLaunchingWithOptions notifications
 *
 *  @discussion
 *  Handles notifications opened from the background
 */
- (void)handleOptions:(NSDictionary *)options;

/*!
 *  @abstract Register Device Anonymously
 *
 *  @discussion
 *  Registers the APNS token from Apple anonymously
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  @seealso
 *  registerDevice:withUserID:
 */


- (void)registerDevice:(NSData *)token __attribute__((deprecated("use registerDevice:completionHandler:errorHandler: instead.")));
- (void)registerDevice:(NSData *)token completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Register Device with ID
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID __attribute__((deprecated("use registerDevice:withUserID:completionHandler:errorHandler: instead.")));
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Register Device with ID and name
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  Adds another string that can be used to display name
 */
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID withUsername:(NSString *)username __attribute__((deprecated("use registerDevice:withUserID:withUsername:completionHandler:errorHandler: instead.")));
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID withUsername:(NSString *)username completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Register for WebSockets Notifications
 *
 *  @discussion
 *  Registers with the WebSockets server that will assign this device a token.
 *  It will trigger the didRegisterForWebsocketsNotifications with that token.
 *  @seealso
 *  unregisterForWebsockets:
 */
-(void)registerForWebsockets;
/*!
 *  @abstract Unregister for WebSockets Notifications
 *
 *  @discussion
 *  Closes the WebSockets channel
 */
-(void)unregisterForWebsockets;

/*!
 *  @abstract Register Device Anonymously for WebSockets
 *
 *  @discussion
 *  Registers the WebSockets token from Notificare anonymously
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  @seealso
 *  registerDeviceForWebsockets:withUserID
 */
- (void)registerDeviceForWebsockets:(NSString *)token __attribute__((deprecated("use registerDeviceForWebsockets:completionHandler:errorHandler: instead.")));
- (void)registerDeviceForWebsockets:(NSString *)token completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Register Device with ID for WebSockets
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID __attribute__((deprecated("use registerDeviceForWebsockets:withUserID:completionHandler:errorHandler: instead.")));
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Register Device with ID
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  Consider using the method with the completion and error blocks if you want to make sure that you create tags or start location updates
 *  only after successfully register a device token.
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID withUsername:(NSString *)username __attribute__((deprecated("use registerDeviceForWebsockets:withUserID:withUsername:completionHandler:errorHandler: instead.")));
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID withUsername:(NSString *)username completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Unregister Device
 *
 *  @discussion
 *  This method allows you to prevent Notificare from sending notifications
 *  If you also wish to remove the device from APNS also call [[UIApplication sharedApplication] unregisterForRemoteNotifications]
 */
- (void)unregisterDevice;


/*!
 *  @abstract Update Badge
 *
 *  @discussion
 *  Update app badge, accepts a NSNumber
 */
- (void)updateBadge:(NSNumber *)badge;

/*!
 *  @abstract Open notification
 *
 *  @discussion
 *  Displays text or rich content notifications. Usually used in the delegate didReceiveRemoteNotification
 *  @seealso
 *  getNotification:completionHandler:errorHandler:
 */
- (void)openNotification:(NSDictionary *)notification;

/*!
 *  @abstract Get Notification
 *
 *  @discussion
 *  Fetches a notification's full payload. Usually used if you gonna handle the notifications yourself.
 */
- (void)getNotification:(NSString *)notificationID completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Delete Notification
 *
 *  @discussion
 *  Deletes a notification. Should be used if you want to remove a notification from our system
 */
- (void)clearNotification:(NSString *)notification;

/*!
 *  @abstract Start Location Updates
 *
 *  @discussion
 *  Starts the location manager for geo-targeting, geo-fencing and beacons
 */
-(void)startLocationUpdates;

/*!
 *  @abstract Check if Location Updates are ON
 *
 *  @discussion
 *  Returns boolean for Location Service status
 */
-(BOOL)checkLocationUpdates;

/*!
 *  @abstract Update Device's Location
 *
 *  @discussion
 *  Update the device's location manually
 */
- (void)updateLocation:(NSString*)device withLatitude:(float)latitude andLongitude:(float)longitude;
/*!
 *  @abstract Stop Location Updates
 *
 *  @discussion
 *  Stops the location manager from collecting location updates
 */
-(void)stopLocationUpdates;

/*!
 *  @abstract Tags
 *
 *  @discussion
 *  Tags are used to easily categorize devices according to any kpi, point or area of 
 */
- (void)getTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)addTags:(NSArray *)tags;
- (void)addTags:(NSArray *)tags completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

//Remove Tag from a device
- (void)removeTag:(NSString *)tag;
- (void)removeTag:(NSString *)tag completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)clearTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;

//Manually start Beacons without a geofence
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid;
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid andMajor:(NSNumber *)major;
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid andMajor:(NSNumber *)major andMinor:(NSNumber *)minor;

/*!
 *  @abstract Open beacon content
 *
 *  @discussion
 *  Displays text or rich content attached to that beacon. Usually used in the delegate didRangeBeacons
 *  @seealso
 *  getNotification:completionHandler:errorHandler:
 */
- (void)openBeacon:(NSDictionary *)beacon;
- (void)openBeacons;
/*!
 *  @abstract Open User Preferences
 *
 *  @discussion
 *  Displays a view with for user control of notifications, location updates and key-value pairs inserted in NotificareTags.plist
 */
- (void)openUserPreferences;

/*!
 *  @abstract Reply action
 *
 *  @discussion
 *  Register an action event manually. Usually needed when you handling notifications yourself and want to use the actions to register a certain user choice.
 */
- (void)reply:(NSString *)notification withLabel:(NSString *)label andData:(NSDictionary *)data;
/*!
 *  @abstract Handle action from iOS8 notifications
 *
 *  @discussion
 *  Handles the action clicked from a notificaition in iOS 8
 */
- (void)handleAction:(NSString *)action forNotification:(NSDictionary *)notification withData:(NSDictionary *)data completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)errorBlock;

/*!
 *  @abstract Log a Custom Event
 *
 *  @discussion
 *  This method allows your app to store key metrics you might find useful. You can then visualize time based agreggations of this data.
 */
- (void)logCustomEvent:(NSString *)name withData:(NSDictionary *)data completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Save Notification to Inbox
 *
 *  @discussion
 *  Save the incoming notifications to the Notificare Inbox. To be use in -application didReceiveRemoteNotification:fetchCompletionHandler:
 */
- (void)saveToInbox:(NSDictionary *)notification forApplication:(UIApplication *)application completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Remove Notification from Inbox
 *
 *  @discussion
 *  Remove a notification from the Inbox
 */
- (void)removeFromInbox:(NSDictionary *)notification;

/*!
 *  @abstract Open Inbox
 *
 *  @discussion
 *  Opens the UI to present an Inbox with all the items received in the device. This window allows to also remove these records from the inbox.
 *
 */
-(void)openInbox;
/*!
 *  @abstract Inbox
 *
 *  @discussion
 *  At any point in your app you can access [[NotificarePushLib shared] myInbox] to retrieve the device's inbox.
 *  The returned value is a NSArray containing NSDictionary objects of you notifications.
 */
-(NSArray *)myInbox;

/*!
 *  @abstract Badge
 *
 *  @discussion
 *  At any point in your app you can access [[NotificarePushLib shared] myBadge] to retrieve the device's badge number.
 */
-(int)myBadge;

/*!
 *  @abstract OAuth2 Methods
 *
 *  @discussion
 *  When enabled in the dashboard (this feature is an add-on, activation done in your dashboard) you can allow your users to create, authenticate and manage their own user profiles.
 */

- (void)createAccount:(NSDictionary *)params completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
- (void)resetPassword:(NSDictionary *)params withToken:(NSString *)token completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
- (void)validateAccount:(NSString *)token completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
- (void)sendPassword:(NSDictionary *)params completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
- (void)loginWithUsername:(NSString *)username andPassword:(NSString *)password completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)fetchAccountDetails:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)generateEmailToken:(SuccessBlock)info errorHandler:(ErrorBlock)error __attribute__((deprecated("use generateAccessToken:completionHandler:errorHandler: instead.")));
- (void)generateAccessToken:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)changePassword:(NSDictionary *)params completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)checkAccount:(NSString *)user completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)handleOpenURL:(NSURL *)url;
- (void)logoutAccount;
- (BOOL)isLoggedIn;

@end

