//
//  NotificarePushLib.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
//
//

#import "Notificare.h"
#import "NotificareEngine.h"
#import "NSData+Hex.h"
#import "NotificareActions.h"
#import "NotificareSRWebSocket.h"
#import "NotificareNotification.h"
#import <CoreLocation/CoreLocation.h>
#import <StoreKit/StoreKit.h>
#import "NotificareNXOAuth2.h"
#import "NotificareUser.h"
#import "NotificareUserPreference.h"
#import "NotificareSegment.h"
#import "NotificareBeacon.h"
#import "NotificareProduct.h"
#import "NotificareDevice.h"
#import "NotificareDeviceInbox.h"


/**
 * We will surpress warnings with this macro in order to be able to execute methods triggered by an action
 * This will be called by the surpressor
 */
#define Suppressor(Selector) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Selector; \
_Pragma("clang diagnostic pop") \
} while (0)


/**
 * Blocks definitions
 * Current blocks used by this library's methods
 */
typedef void (^SuccessDeviceInboxBlock)(NotificareDeviceInbox * inbox);
typedef void (^SuccessNotificationBlock)(NotificareNotification * notification);
typedef void (^SuccessProductBlock)(NotificareProduct * product);
typedef void (^SuccessArrayBlock)(NSArray * info);
typedef void (^SuccessBlock)(NSDictionary * info);
typedef void (^ErrorBlock)(NSError * error);

/*!
 * @typedef kNotificareErrorCode
 * @brief A list of NotificarePushLib HTTP error codes
 * @constant kNotificareErrorCodeBadRequest Request could not be accepted the resource does not exist
 * @constant kNotificareErrorCodeUnauthorized Request failed due to authentication credentials, please check your App Keys
 * @constant kNotificareErrorCodeForbidden Request could not be accepted because of you do not have access to this resource
 * @constant kNotificareErrorCodeNotFound Request failed because resource could not be found
 * @constant kNotificareErrorCodeConflict Request failed due to duplicated resources
 * @constant kNotificareErrorCodeUnprocessableEntity Request failed due to unprocessable parameters
 * @constant kNotificareErrorCodeInternalServerError Request failed due to a server error
 * @constant kNotificareErrorCodeGatewayTimeout Request failed due to a network timeout
 */
typedef enum  {
    kNotificareErrorCodeBadRequest = 400,
    kNotificareErrorCodeUnauthorized = 401,
    kNotificareErrorCodeForbidden = 403,
    kNotificareErrorCodeNotFound = 404,
    kNotificareErrorCodeConflict = 409,
    kNotificareErrorCodeUnprocessableEntity = 422,
    kNotificareErrorCodeInternalServerError = 500,
    kNotificareErrorCodeBadGateway = 502,
    kNotificareErrorCodeServiceUnavailable = 503,
    kNotificareErrorCodeGatewayTimeout = 504
} kNotificareErrorCode;

/*!
 * @brief The NotificarePushLib class
 */
@class NotificarePushLib;

/**
 * Main class protocol delegates
 * Optional delegates of NotificarePushLib, these should be implmented or not according to your implementation.
 */
@protocol NotificarePushLibDelegate <NSObject>

@optional

/*!
 * @brief Optional. This delegate method will be triggered after a register for websockets
 * @param uuid A NSString representing the device UUID
 */
- (void)notificarePushLib:(NotificarePushLib *)library didRegisterForWebsocketsNotifications:(NSString *)uuid;
/*!
 * @brief Optional. This delegate method will be triggered when a websocket notification is received.
 * @param info A NSDictionary containing notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveWebsocketNotification:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered whenever a websocket connection fails to register a device.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterWebsocketNotifications:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered when the websocket connection is closed.
 * @param reason A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didCloseWebsocketConnection:(NSString *)reason;
/*!
 * @brief Optional. This delegate method should return a boolean that represents if you wish for the library to handle the notification.
 * @param info A NSDictionary representing the notification
 * @return A boolean indicating if developer wishes the library to handle the notification
 */
- (BOOL)notificarePushLib:(NotificarePushLib *)library shouldHandleNotification:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered every time the badge updates. Use it to update your UI.
 * @param badge An integer that represents the number of unread messages in the inbox
 */
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateBadge:(int)badge;
/*!
 * @brief Optional. This delegate method will be triggered just before the notification opens.
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library willOpenNotification:(NotificareNotification *)notification;
/*!
 * @brief Optional. This delegate method will be triggered when the notification opens.
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library didOpenNotification:(NotificareNotification *)notification;
/*!
 * @brief Optional. This delegate method will be triggered when the notification closes.
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library didCloseNotification:(NotificareNotification *)notification;
/*!
 * @brief Optional. This delegate method will be triggered when the it fails to open the notification.
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToOpenNotification:(NotificareNotification *)notification;
/*!
 * @brief Optional. This delegate method will be triggered when a user interacts with clickable content or events in WebView
 * @param url A NSURL object that represents the URL clicked
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library didClickURL:(NSURL *)url inNotification:(NotificareNotification *)notification;

/*!
 * @brief Optional. This delegate method will be triggered just before the action will is executed.
 * @param notification A NotificareNotification object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library willExecuteAction:(NotificareNotification *)notification;
/*!
 * @brief Optional. This delegate method will be triggered when the action is executed.
 * @param info A NSDictionary object that represents the user selectable action
 */
- (void)notificarePushLib:(NotificarePushLib *)library didExecuteAction:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered when the action to be executed will require that you execute a selector method in your own code.
 * @param selector A NSString that represents the method to be called
 * @code -(void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelectorWithURL:(NSURL *)url{
 [self performSelector:[url host] withObject:[url path]]
 }
 */
- (void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelectorWithURL:(NSURL *)url;
/*!
 * @brief Optional. This delegate method will be triggered when the action was cancelled.
 * @param info A NSDictionary object that represents the user selectable action
 */
- (void)notificarePushLib:(NotificarePushLib *)library didNotExecuteAction:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered when the user selectable action fails to be executed.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToExecuteAction:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered when it fails to start location updates.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToStartLocationServiceWithError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered as response to a start location updates.
 * @param status A NSDictionary object that contains information about the location services' status
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveLocationServiceAuthorizationStatus:(NSDictionary *)status;
/*!
 * @brief Optional. This delegate method will be triggered every time a new location update is received.
 * @param locations A NSArray that contains a list of CLLocation objects
 */
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateLocations:(NSArray *)locations;
/*!
 * @brief Optional. This delegate method will be triggered every time a region fails to be monitored.
 * @param region A CLRegion object
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered every time a region starts to be monitored.
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didStartMonitoringForRegion:(CLRegion *)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a region starts to be monitored.
 * @constant state A CLRegionState constant that represents the state of the region
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a device enters a monitored region.
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didEnterRegion:(CLRegion *)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a device exits a monitored region.
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didExitRegion:(CLRegion *)region;
/*!
 * @brief Optional. This delegate method will be triggered whenever Core Location fails to range beacons for a region.
 * @param region A CLBeaconRegion object
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered every time a region is ranging for beacons.
 * @param beacons A NSArray containing the list of beacons found in range
 * @param region A CLBeaconRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a user authenticates. Use it to update UI.
 * @param info A NSDictionary containing the user data
 */
- (void)notificarePushLib:(NotificarePushLib *)library didChangeAccountNotification:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered every time user logs out. Use it to update UI.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRequestAccessNotification:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered in response to a user click in the activation email link.
 * @param token A NSString containing the token for this operation
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveActivationToken:(NSString *)token;
/*!
 * @brief Optional. This delegate method will be triggered in response to a user click in the reset password email link.
 * @param token A NSString containing the token for this operation
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveResetPasswordToken:(NSString *)token;
/*!
 * @brief Optional. This delegate method will be triggered soon the product's store is loaded. Use it to update UI.
 * @param products A NSArray containing the list of products
 */
- (void)notificarePushLib:(NotificarePushLib *)library didLoadStore:(NSArray *)products;
/*!
 * @brief Optional. This delegate method will be triggered every time the store fails to load. We will automatically retry to load the store.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToLoadStore:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered when a transaction is completed.
 * @param transaction A SKPaymentTransaction object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didCompleteProductTransaction:(SKPaymentTransaction *)transaction;
/*!
 * @brief Optional. This delegate method will be triggered when a transaction is restored.
 * @param transaction A SKPaymentTransaction object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didRestoreProductTransaction:(SKPaymentTransaction *)transaction;
/*!
 * @brief Optional. This delegate method will be triggered when a transaction fails.
 * @param transaction A SKPaymentTransaction object
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailProductTransaction:(SKPaymentTransaction *)transaction withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered when a transaction's content starts downloading.
 * @param transaction A SKPaymentTransaction object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didStartDownloadContent:(SKPaymentTransaction *)transaction;
/*!
 * @brief Optional. This delegate method will be triggered when a download is paused.
 * @param download A SKDownload object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didPauseDownloadContent:(SKDownload *)download;
/*!
 * @brief Optional. This delegate method will be triggered when a download is cancelled.
 * @param download A SKDownload object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didCancelDownloadContent:(SKDownload *)download;
/*!
 * @brief Optional. This delegate method will be triggered whenever a download progress is updated.
 * @param download A SKDownload object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveProgressDownloadContent:(SKDownload *)download;
/*!
 * @brief Optional. This delegate method will be triggered whenever a download fails.
 * @param download A SKDownload object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailDownloadContent:(SKDownload *)download;
/*!
 * @brief Optional. This delegate method will be triggered whenever a download progress is finished.
 * @param download A SKDownload object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFinishDownloadContent:(SKDownload *)download;

@required

/*!
 * @brief Required. This delegate method will be triggered whenever the library is ready. Use it to register for notifications.
 * @param info A NSDictionary object containing information about this app's services
 * @code - (void)notificarePushLib:(NotificarePushLib *)library onReady:(NSDictionary *)info{
     [[NotificarePushLib shared] registerForNotifications];
 }
 */
- (void)notificarePushLib:(NotificarePushLib *)library onReady:(NSDictionary *)info;

@end


@interface NotificarePushLib : NSObject <NotificareSRWebSocketDelegate,NotificareDelegate,NotificareActionsDelegate,CLLocationManagerDelegate, SKProductsRequestDelegate, SKPaymentTransactionObserver>

/*!
 *  @abstract Protocol of NotificarePushLib class that handles events
 *  @property NotificarePushLibDelegate
 *
 */
@property (nonatomic, assign) id <NotificarePushLibDelegate> delegate;


/*!
 *  @abstract The Noticare network requests class
 *  @property NotificareEngine
 *
 */
@property (strong, nonatomic) NotificareEngine * notificareEngine;

/*!
 *  @abstract The Notificare Object
 *  @property Notificare
 *
 *  @discussion
 *	A Notificare Object class
 *
 */

@property (strong, nonatomic) Notificare * notificare;
/*!
 *  @abstract The latest Notificare Object
 *  @property Notificare
 *
 *  @discussion
 *	The latest Notificare Object class. Responsible of presenting the notification to the user.
 *
 */
@property (strong, nonatomic) Notificare * currentNotificare;
/*!
 *  @abstract The NoticareActions requests class
 *  @property NotificareEngine
 *
 *  @discussion
 *	A NotificareActions object class. Responsible of handling the user selectable actions that might be included in each notification.
 *
 */
@property (strong, nonatomic) NotificareActions * notificareActions;


/*!
 *  @abstract the apiID key
 *  @property apiID
 *
 *  @discussion
 *	A NSString representing the Application Key
 *
 */
@property (strong, nonatomic) NSString * apiID;
/*!
  *  @abstract The apiSecret key
  *  @property apiSecret
  *
  *  @discussion
  *  A NSString representing the Application Secret
  *
  */
@property (strong, nonatomic) NSString * apiSecret;

/*!
 *  @abstract Get the device properties
 *
 *  @discussion
 *	A NotificareDevice object containing all information about the device properties like the device token, language, location, etc.
 *
 */
@property (strong, nonatomic) NotificareDevice * myDevice;
/*!
 *  @abstract The device Token
 *
 *  @discussion
 *	A NSString representing the device token
 *
 */
@property (strong, nonatomic) NSString * deviceToken __attribute__((deprecated("use myDevice instead.")));


/*!
 *  @abstract The raw device Token
 *
 *  @discussion
 *	A NSData object representing the device token
 *
 */
@property (strong, nonatomic) NSData * deviceTokenData __attribute__((deprecated("use myDevice instead.")));

/*!
 *  @abstract The device UUID
 *
 *  @discussion
 *	A NSString representing the device's websockets UUID
 *
 */
@property (strong, nonatomic) NSString * deviceUUID __attribute__((deprecated("use myDevice instead.")));

/*!
 *  @abstract The Notificare device string
 *
 *  @discussion
 *	A NSString representing the device model
 *
 */
@property (strong, nonatomic) NSString * device __attribute__((deprecated("use myDevice instead.")));

/*!
 *  @abstract The userID
 *
 *  @discussion
 *	A NSString representing the userID
 *
 */
@property (strong, nonatomic) NSString * userID __attribute__((deprecated("use myDevice or user instead.")));

/*!
 *  @abstract The oAuth account
 *
 *  @discussion
 *	A NotificareNXOAuth2Account object representing the current account in the keychain
 *
 */
@property (strong, nonatomic) NotificareNXOAuth2Account * account;

/*!
 *  @abstract The Notificare User object
 *
 *  @discussion
 *	A NotificareUser object representing the current user
 *
 */
@property (strong, nonatomic) NotificareUser * user;


/*!
 *  @abstract The username
 *
 *  @discussion
 *	A NSString representing the current user's username
 *
 */
@property (strong, nonatomic) NSString * username __attribute__((deprecated("use myDevice or user instead.")));


/*!
 *  @abstract Boolean for checking if notification is open
 *
 */
@property (assign) BOOL isOpen;

/*!
 *  @abstract Boolean for checking if position is being currently being updated
 *
 */
@property (assign) BOOL isFixingGPS;


/*!
 *  @abstract Boolean that states if rich content message should present an alert
 *
 */
@property (assign) BOOL displayMessage;

/*!
 *  @abstract CLRegion Object for the current Fence
 *
 */
@property (strong, nonatomic) CLRegion * currentFence __attribute__((deprecated("use currentRegions instead.")));

/*!
 *  @abstract NSMutableArray containing the region IDs as a NSString
 *
 */
@property (strong, nonatomic) NSMutableArray * currentRegions;
/*!
 *  @abstract NSMutableArray containing the the beacon IDs as a NSString
 *
 */
@property (strong, nonatomic) NSMutableArray * currentBeacons;
/*!
 *  @abstract An NSMutableArray with notification objects to be displayed
 *
 *  @discussion
 *	Use this method to access the current queue of messages to be shown to the user.
 *
 */
@property (strong, nonatomic) NSMutableArray * notificationQueue;

/*!
 *  @abstract Active notification
 *
 *  @discussion
 *	Use this to access the current notification object as it received from APNS
 *
 */
@property (strong, nonatomic) NSDictionary * activeNotification;

/*!
 *  @abstract Location Manager
 *
 *  @discussion
 *	Core Location Manager that handles significant change updates and location services
 *
 */
@property (strong, nonatomic) CLLocationManager *locationManager;

/*!
 *  @abstract Last Locations
 *
 *  @discussion
 *	A mutable array that holds lasts GPS readings from Core Location
 *
 */
@property (strong, nonatomic) NSMutableArray *lastLocations;

/*!
 *  @abstract Region Session Data
 *
 *  @discussion
 *	A mutable array that holds the enter/exit sessions data for a fence
 *
 */
@property (strong, nonatomic) NSMutableArray * regionSessions;


/*!
 *  @abstract Beacon Session Data
 *
 *  @discussion
 *	A mutable dictionary that holds hold the range time in each of the beacons in range
 *
 */
@property (strong, nonatomic) NSMutableDictionary * beaconSession;

/*!
 *  @abstract Beacon Region
 *
 *  @discussion
 *	A CLBeaconRegion currently in range
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
 *	A BOOL to flag when a iBeacon region is ranging
 */
 
@property (nonatomic, assign) BOOL ranging;

/*!
 *  @abstract Beacons
 *
 *  @discussion
 *	Returns Beacons being monitored
 *
 */
@property (strong, nonatomic) NSMutableArray * beacons;



/*!
 *  @abstract Beacons
 *
 *  @discussion
 *	Returns an array of beacons that were triggered by entry
 *
 */
@property (strong, nonatomic) NSMutableArray * stateBeacons;


/*!
 *  @abstract Application info
 *
 *  @discussion
 *	Returns application's object for public use
 *
 */
@property (strong, nonatomic) NSDictionary * applicationInfo;

/*!
 *  @abstract Geo-fences
 *
 *  @discussion
 *	Returns regions objects being monitored
 *
 */
@property (strong, nonatomic) NSMutableArray * geofences;



/*!
 *  @abstract Log of entries in a region
 *
 *  @discussion
 *	Returns an array of regions that were triggered by a user entry
 *
 */
@property (strong, nonatomic) NSMutableArray * stateEntries;



/*!
 *  @abstract In-App Billing
 *
 *  @discussion
 *	Properties for the In-App Billing add-on
 *
 */
@property (strong, nonatomic) NSMutableSet * productIdentifiers;
@property (strong, nonatomic) NSMutableArray * products;
@property (strong, nonatomic) NSMutableArray * pendingTransactions;
@property (strong, nonatomic) NSMutableSet * purchasedProducts;
@property (strong, nonatomic) SKProductsRequest * storeRequest;

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
 *  Initializes the NotificarePushLib, should be the first method to be invoked in your App Delegate
 */
- (void)launch;

/*!
 *  @abstract Register for APNS + User Notifications
 *
 *  @discussion
 *  This method will register a device for remote notifications and user notifications. Should only be invoked after the delegate method onReady is triggered.
 */
- (void)registerForNotifications;

/*!
 *  @abstract Unregister for APNS + User Notifications
 *
 *  @discussion
 *  This method will unregister a device for remote notifications and user notifications. Should only be invoked after the delegate method onReady is triggered.
 */
-(void)unregisterForNotifications;

/*!
 *  @abstract Register for User Notifications
 *
 *  @discussion
 *  Available since iOS 8. This method will prompt the user to accept badges, alerts and sounds. Should only be invoked after the delegate method onReady is triggered. Once the user accepts it, the delegate - (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings will be triggered.
 */
- (void)registerUserNotifications;

/*!
 *  @abstract Unregister for User Notifications
 *
 *  @discussion
 *  Available since iOS 8. This method will disable Alerts, Badges or Sounds.
 */
-(void)unregisterUserNotifications;

/*!
 *  @abstract Check if device is registered with APNS
 *
 *  @discussion
 *  Use this method to quickly identify if the device has been registered with APNS
 *  @return A Boolean indicating if device has been registered with APNS
 */
-(BOOL)checkRemoteNotifications;

/*!
 *  @abstract Handle launching options
 *
 *  @discussion
 *  Handles notifications opened when app is inactive. This should be implemented in the didFinishLaunchingWithOptions: method of your App Delegate
 *  @param options A NSDictionary provided by the delegate didFinishLaunchingWithOptions:
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
/*!
 * @brief This method should be used to register the device token with Notificare. Should only be invoked on the didRegisterForRemoteNotificationsWithDeviceToken delegate.
 * @param token A NSData object representing the device's token
 * @code [[NotificarePushLib shared] registerDevice:deviceToken completionHandler:^(NSDictionary *info) {
    [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
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
/*!
 * @brief This method should be used to register the device token with Notificare. Should only be invoked on the didRegisterForRemoteNotificationsWithDeviceToken delegate.
 * @param token A NSData object representing the device's token
 * @param userID A NSString representing the userID. It should be unique.
 * @code [[NotificarePushLib shared] registerDevice:deviceToken withUserID:@"uniqueID" completionHandler:^(NSDictionary *info) {
    [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
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
/*!
 * @brief This method should be used to register the device token with Notificare. Should only be invoked on the didRegisterForRemoteNotificationsWithDeviceToken delegate.
 * @param token A NSData object representing the device's token
 * @param userID A NSString representing the userID. It should be unique.
 * @param username A NSString representing the username.
 * @code [[NotificarePushLib shared] registerDevice:deviceToken withUserID:@"uniqueID" withUsername:@"name" completionHandler:^(NSDictionary *info) {
    [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
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
- (void)registerDeviceForWebsockets:(NSString *)uuid __attribute__((deprecated("use registerDeviceForWebsockets:completionHandler:errorHandler: instead.")));
/*!
 * @brief This method should be used to register the device UUID with Notificare. Should only be invoked on the didRegisterForWebsocketsNotifications delegate.
 * @param uuid A NSData object representing the device's UUID
 * @code [[NotificarePushLib shared] registerDeviceForWebsockets:uuid completionHandler:^(NSDictionary *info) {
 [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
- (void)registerDeviceForWebsockets:(NSString *)uuid completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
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
- (void)registerDeviceForWebsockets:(NSString *)uuid withUserID:(NSString *)userID __attribute__((deprecated("use registerDeviceForWebsockets:withUserID:completionHandler:errorHandler: instead.")));
/*!
 * @brief This method should be used to register the device UUID with Notificare. Should only be invoked on the didRegisterForWebsocketsNotifications delegate.
 * @param uuid A NSData object representing the device's UUID
 * @param userID A NSString representing the userID. It should be unique.
 * @code [[NotificarePushLib shared] registerDeviceForWebsockets:uuid withUserID:@"uniqueID" completionHandler:^(NSDictionary *info) {
 [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
- (void)registerDeviceForWebsockets:(NSString *)uuid withUserID:(NSString *)userID completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
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
- (void)registerDeviceForWebsockets:(NSString *)uuid withUserID:(NSString *)userID withUsername:(NSString *)username __attribute__((deprecated("use registerDeviceForWebsockets:withUserID:withUsername:completionHandler:errorHandler: instead.")));
/*!
 * @brief This method should be used to register the device UUID with Notificare. Should only be invoked on the didRegisterForWebsocketsNotifications delegate.
 * @param uuid A NSData object representing the device's UUID
 * @param userID A NSString representing the userID. It should be unique.
 * @param username A NSString representing the username.
 * @code [[NotificarePushLib shared] registerDeviceForWebsockets:uuid withUserID:@"uniqueID" withUsername:@"name" completionHandler:^(NSDictionary *info) {
 [[NotificarePushLib shared] startLocationUpdates];
 } errorHandler:^(NSError *error) {
 }];
 */
- (void)registerDeviceForWebsockets:(NSString *)uuid withUserID:(NSString *)userID withUsername:(NSString *)username completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

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
 *  Update app badge, accepts a NSNumber. If you are using the inbox with remote notifications as a background mode, this will be managed for you.
 *  @param badge A NSNumber that represents badge number.
 */
- (void)updateBadge:(NSNumber *)badge;

/*!
 *  @abstract Open notification
 *
 *  @discussion
 *  Displays the notification. Usually used in the delegate didReceiveRemoteNotification: delegate.
 *  @param notificationID A NSString that represents the notification ID
 */
- (void)openNotification:(NSDictionary *)notification;
/*!
 *  @abstract Log Open notification
 *
 *  @discussion
 *  Logs the open notification manually. This should be used when you don't use the openNotification.
 *  @param notification A NSDictionary object usually the result of getNotification: or Apple's userInfo dictionary provided in didReceiveRemoteNotification:.
 */
- (void)logOpenNotification:(NSDictionary *)notification;
/*!
 *  @abstract Log Influenced Open notification
 *
 *  @discussion
 *  Logs the influenced open notification manually. This should be used when you don't use the handleOptions.
 *  @param notification A NSDictionary object usually the result of getNotification: or Apple's userInfo dictionary provided in handleOptions:.
 */
- (void)logInfluencedOpenNotification:(NSDictionary *)notification;
/*!
 *  @abstract Get Notification
 *
 *  @discussion
 *  Get the server's notification object. Usually used if you going to handle the notifications yourself.
 *  @param notificationID A NSString that represents the notification ID
 */
- (void)getNotification:(NSString *)notificationID completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Delete Notification
 *
 *  @discussion
 *  Deletes a notification. Should be used if you want to remove a notification from our system. Only applicable for private (sent to a single user or device) notifications. This can not be undone.
 *  @param notification A NSString that represents the notification ID
 */
- (void)clearNotification:(NSString *)notification;

/*!
 *  @abstract Start Location Updates
 *
 *  @discussion
 *  Starts the location manager for geo-targeting, geo-fencing and beacons. It will prompt the user with a permission dialog for location services if the user allows location services, this dialog will never be shown. Since iOS8 the key NSLocationAlwaysUsageDescription in your app's info.plist is required. For app's supporting older versions, use NSLocationUsageDescription key too. These keys should contain a text explaining why your app requires locations updates.
 */
-(void)startLocationUpdates;

/*!
 *  @abstract Check if Location Updates are ON
 *
 *  @discussion
 *  Use this method to quickly identify if the user has allowed location services
 *  @return A Boolean indicating if location services are on or off
 */
-(BOOL)checkLocationUpdates;

/*!
 *  @abstract Update Device's Location
 *
 *  @discussion
 *  Update the device's location manually
 *  @param latitude A float that represents the latitude of the device
 *  @param longitude A float that represents the longitude of the device
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
 *  @abstract Get all tags
 *
 *  @discussion
 *  Get all the tags a device has been added to
 */
- (void)getTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Add a tag to the device
 *
 *  @discussion
 *  Add one or more tags to a device.
 *  @param tag A NSArray that contains a list of tags to be added to the device
 */
- (void)addTags:(NSArray *)tags;
/*!
 *  @abstract Add a tag to the device
 *
 *  @discussion
 *  Add one or more tags to a device. This method uses blocks that returns success or failure for this operation.
 *  @param tag A NSArray that contains a list of tags to be added to the device
 */
- (void)addTags:(NSArray *)tags completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Remove a tag from the device
 *
 *  @discussion
 *  Remove a tag from a device.
 *  @param tag A NSString that represents the tag to be removed from the device
 */
- (void)removeTag:(NSString *)tag;
/*!
 *  @abstract Remove a tag to the device
 *
 *  @discussion
 *  Remove a tag from a device. This method uses blocks that returns success or failure for this operation.
 *  @param tag A NSString that represents the tag to be removed from the device
 */
- (void)removeTag:(NSString *)tag completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Remove all tags from the device
 *
 *  @discussion
 *  Remove all tags from a device. This method uses blocks that returns success or failure for this operation.
 */
- (void)clearTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Start monitoring beacons for region
 *
 *  @discussion
 *  Start monitoring beacons for a specific region using a NSUUID. This method is only needed if you are handling location services yourself.
 *  @param uuid A NSUUID that represents the number found in your beacons as the UUID
 */
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid;
/*!
 *  @abstract Start monitoring beacons for region
 *
 *  @discussion
 *  Start monitoring beacons for a specific region using a NSUUID and a NSNumber representing the major identifier found in the beacons. This method is only needed if you are handling location services yourself.
 *  @param uuid A NSUUID that represents the number found in your beacons as the UUID
 *  @param major A NSNumber that represents the number found in your beacons as the major
 */
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid andMajor:(NSNumber *)major;
/*!
 *  @abstract Start monitoring beacons for region
 *
 *  @discussion
 *  Start monitoring beacons for a specific region using a NSUUID, a NSNumber representing the major identifier and a NSNumber representing the minor identifier found in the beacons. This method is only needed if you are handling location services yourself.
 *  @param uuid A NSUUID that represents the number found in your beacons as the UUID
 *  @param major A NSNumber that represents the number found in your beacons as the major
 *  @param minor A NSNumber that represents the number found in your beacons as the minor
 */
- (void)startMonitoringBeaconRegion:(NSUUID *)uuid andMajor:(NSNumber *)major andMinor:(NSNumber *)minor;


/*!
 *  @abstract Open beacon content
 *
 *  @discussion
 *  Displays text or rich content attached to that beacon. Usually used in the delegate didRangeBeacons. This method is deprecated in favour of openNotificareBeacon method.
 *  @param beacon A NSDictionary that contains the content of the beacon
 */
- (void)openBeacon:(NSDictionary *)beacon  __attribute__((deprecated("use openNotificareBeacon: instead.")));
/*!
 *  @abstract Open beacon content
 *
 *  @discussion
 *  Displays the beacon's content. A NotificareBeacon object can be retrieved from the NSArray containing a list of beacons in the delegate didRangeBeacons:inRegion:.
 *  @param beacon A NotificareBeacon object that represents a beacon
 */
- (void)openNotificareBeacon:(NotificareBeacon *)beacon;
/*!
 *  @abstract Open beacons view
 *
 *  @discussion
 *  Presents the user with a built-in view with a list of beacons found in range
 */
- (void)openBeacons;

/*!
 *  @abstract Open User Preferences
 *
 *  @discussion
 *  Displays a settings built-in view where the user can add or remove the device to all the tags inserted in NotificareTags.plist and turn on and off location services
 */
- (void)openUserPreferences;


/*!
 *  @abstract Reply action
 *
 *  @discussion
 *  Register an action event manually. Usually needed when you handling notifications yourself and want to collect the user's answers
 *  @param notification A NSString that represents the notification ID
 *  @param label A NSString that represents the label of action button
 *  @param data A NSDictionary that contains any extra data (can be nil)
 */
- (void)reply:(NSString *)notification withLabel:(NSString *)label andData:(NSDictionary *)data;
/*!
 *  @abstract Handle action from iOS8 notifications
 *
 *  @discussion
 *  This method is only available since iOS8 and will handle the user's click in one of the action buttons available in notifications when shown in places like the notification center and lock screen. This method should be invoked in the handleActionWithIdentifier:forRemoteNotification:completionHandler delegate.
 *  @param action A NSString that represents the label of the action button
 *  @param notification A NSDictionary object that contains the notification
 *  @param data A NSDictionary that contains any extra data (can be nil)
 *  @code [[NotificarePushLib shared] handleAction:identifier forNotification:userInfo withData:nil completionHandler:^(NSDictionary *info) {
 completion();
 } errorHandler:^(NSError *error) {
 completion();
 }];
 */
- (void)handleAction:(NSString *)action forNotification:(NSDictionary *)notification withData:(NSDictionary *)data completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)errorBlock;

/*!
 *  @abstract Log a Custom Event
 *
 *  @discussion
 *  This method allows your app to store key metrics you might find useful. You can then visualize time based agreggations of this data.
 *  @param name A NSString that represents the event name
 *  @param data A NSDictionary object that contains any kind of data to be store (can be nil)
 */
- (void)logCustomEvent:(NSString *)name withData:(NSDictionary *)data completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Save Notification to Inbox
 *
 *  @discussion
 *  Save the incoming notifications to the Notificare Inbox. To be use in -application didReceiveRemoteNotification:fetchCompletionHandler:
 *  This method will require the background mode in your project capabilities to be set to remote notifications.
 *  @param notification A NSDictionary containing the notification object
 *  @param application A UIApplication object that references to this application
 */
- (void)saveToInbox:(NSDictionary *)notification forApplication:(UIApplication *)application completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock  __attribute__((deprecated("use handleNotification:forApplication: instead.")));
/*!
 *  @abstract Handle Notification
 *
 *  @discussion
 *  Handles all the events for a notification. To be use in -application didReceiveRemoteNotification:fetchCompletionHandler:
 *  This method will require the background mode in your project capabilities to be set to remote notifications.
 *  @param notification A NSDictionary containing the notification object
 *  @param application A UIApplication object that references to this application
 */
- (void)handleNotification:(NSDictionary *)notification forApplication:(UIApplication *)application completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Get inbox for device
 *
 *  @discussion
 *  Use this method to get a list of all inbox items for a device.
 */
- (void)fetchInbox:(NSDate *)sinceDate skip:(NSNumber *)skip limit:(NSNumber *)limit completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Open inbox item
 *
 *  @discussion
 *  Displays the inbox item. Should be used with a NotificareDeviceInbox item.
 *  @param inboxItem A NotificareDeviceInbox object
 */
- (void)openInboxItem:(NotificareDeviceInbox *)inboxItem;
/*!
 *  @abstract Remove Notification from Inbox
 *
 *  @discussion
 *  Remove a notification from the Inbox
 *  @param notification A NSDictionary containing the notification object
 */
- (void)removeFromInbox:(NSDictionary *)notification  __attribute__((deprecated("use removeFromInbox with blocks instead.")));
/*!
 *  @abstract Remove Inbox Item from Inbox
 *
 *  @discussion
 *  Remove an inbox item from the Inbox
 *  @param notification A NotificareDeviceInbox object
 */
- (void)removeFromInbox:(NotificareDeviceInbox *)inboxItem completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Mark Inbox Item as read
 *
 *  @discussion
 *  Mark an inbox item as read
 *  @param notification A NotificareDeviceInbox object
 */
- (void)markAsRead:(NotificareDeviceInbox *)inboxItem completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Remove All Notifications from Inbox
 *
 *  @discussion
 *  Remove all notifications from the Inbox
 */
- (void)clearInbox  __attribute__((deprecated("use clearInbox with blocks instead.")));
/*!
 *  @abstract Remove All Notifications from Inbox
 *
 *  @discussion
 *  Remove all notifications from the Inbox
 */
- (void)clearInbox:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;

/*!
 *  @abstract Open Inbox
 *
 *  @discussion
 *  Displays an inbox built-in view where the user can have access to all the notifications received in that device. Users can read and remove any notification in this inbox. This is stored locally in the device, so if the user uninstalls the app, these messages will be gone.
 *
 */
-(void)openInbox  __attribute__((deprecated("use Inbox methods instead.")));
/*!
 *  @abstract Inbox
 *
 *  @discussion
 *  At any point in your app you can access [[NotificarePushLib shared] myInbox] to retrieve the device's inbox.
 *  The returned value is a NSArray containing NSDictionary objects of you notifications.
 *  Use these method for a starting to build your own inbox. See also the delegate didUpdateBadge.
 *  @return A NSArray containing the list of messages in the inbox
 */
-(NSArray *)myInbox  __attribute__((deprecated("use fetchMyInbox with blocks instead.")));

/*!
 *  @abstract Badge
 *
 *  @discussion
 *  At any point in your app you can access [[NotificarePushLib shared] myBadge] to retrieve the device's badge number.
 *  @return An integer representing number of messages that are unread
 */
-(int)myBadge;

/*!
 *  @abstract Create Account
 *
 *  @discussion
 *  Use this method to create an account. According to the settings of your add-on module, this can trigger the recipient to receive
 *  email messages to activate this account or simply to welcome him/her to your app.
 *  @param params A NSDictionary containing the following keys: email, password and userName
 *  @code [[NotificarePushLib shared] createAccount:[[self email] text] withName:[[self name] text] andPassword:[[self password] text] completionHandler:^(NSDictionary *info) {
 
 } errorHandler:^(NSError *error) {
 
 }];
 */
- (void)createAccount:(NSString *)email withName:(NSString *)name andPassword:(NSString *)password completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Reset Password
 *
 *  @discussion
 *  Use this method to allow the user to reset his/her password. The token required by this application can only be retrieved if the
 *  delegate didReceiveResetPasswordToken: is implemented. Please implement that protocol delegate. Use the token provide by to complete this operation
 *  @param password A NSString representing the new password for this account
 */
- (void)resetPassword:(NSString *)password withToken:(NSString *)token completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Validate Account
 *
 *  @discussion
 *  Use this method to allow the user to activate his/her account. This will be exclusively triggered by the email received by the user. For this to work,
 *  make sure you implement the delegate didReceiveActivationToken: and call this method inside that delegate.
 */
- (void)validateAccount:(NSString *)token completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Send Password
 *
 *  @discussion
 *  Use this method to allow the user to request a new password for his/her account. This will trigger an email message that will allow the user to create
 *  a new password as described in resetPassword:withToken: methods explained above.
 *  @param token A NSString representing the email address for the account to be recovered
 */
- (void)sendPassword:(NSString *)email completionHandler:(SuccessBlock)result errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Login
 *
 *  @discussion
 *  Use this method to allow the user to authenticate in your application. Once successfully logged in the library will automatically add this account to the
 *  device's keychain. This will make sure the user data is store and encrypted and only accessible by that device. Also after this method being
 *  successfully completed you can use all the user related methods described below.
 *  @param username A NSString representing the email address used as username
 *  @param password A NSString representing the password for this account
 */
- (void)loginWithUsername:(NSString *)username andPassword:(NSString *)password completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Logout
 *
 *  @discussion
 *  Use this method should be log out any authenticated user. This method should also be used to allow the user to forget a device.
 */
- (void)logoutAccount;
/*!
 *  @abstract Logout
 *
 *  @discussion
 *  Use this helper method to check if the user is logged in or not. This is meant to help the app's UI display any user related method without having to
 *  request the full User Object.
 *  @return A Boolean indicating if user is logged in or not
 */
- (BOOL)isLoggedIn;
/*!
 *  @abstract Account Data
 *
 *  @discussion
 *  Use this method to access the user profile.
 */
- (void)fetchAccountDetails:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Access Token
 *
 *  @discussion
 *  Use this method to generate an access token for this user. This access token could be shared with 3rd parties and will be used by our Mail Push
 *  service to quickly send notifications to a user using an email message. Simply use the code generated as the user of the following host: CODE@push.notifica.re
 */
- (void)generateAccessToken:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Change Password
 *
 *  @discussion
 *  Use this method to allow an authenticated user to change his/her password. Preferebly the UI for this method should handle any validation or
 *  any matching password confirmation functionality before requesting this method.
 *  @param password A NSString representing the password
 */
- (void)changePassword:(NSString *)password completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Segments
 *
 *  @discussion
 *  List of all NotificareUserPreference objects. These objects will contain information about user selectable segments. Should be used to show the user's selectable segments defined for this application.
 */
- (void)fetchUserPreferences:(SuccessArrayBlock)info errorHandler:(ErrorBlock)error;

/*!
 *  @abstract Add User Segment
 *
 *  @discussion
 *  Use this method to allow an authenticated user to add himself/herself to a segment previously created and added to the user preferences. These are
 *  retrievable by the method described below.
 *  @param segment A NotificareSegment object
 *  @param preference A NotificareUserPreference object
 */
- (void)addSegment:(NotificareSegment *)segment toPreference:(NotificareUserPreference *)preference completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Remove User Segment
 *
 *  @discussion
 *  Use this method to allow an authenticated user to remove himself/herself from a segment previously created and added to the user preferences. These are
 *  retrievable by the method described below.
 *  @param segment A NotificareSegment object
 *  @param preference A NotificareUserPreference object
 */
- (void)removeSegment:(NotificareSegment *)segment fromPreference:(NotificareUserPreference *)preference completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)errorBlock;
/*!
 *  @abstract Check Account
 *
 *  @discussion
 *  Use this helper method to quickly check if an account with this email has been created.
 */
- (void)checkAccount:(NSString *)user completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Handle Open URL Scheme
 *
 *  @discussion
 *  This method should be implemented in handleOpenURL: delegate method in your app's App Delegate.
 *  It will be responsible of handling all the clicks from email messages generated by the account creation, password management or access token processes.
 *  @param url A NSURL provided by the application delegate handleOpenURL:
 *  @code - (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {
	[[NotificarePushLib shared]  handleOpenURL:url];
    return YES;
 }
 */
- (void)handleOpenURL:(NSURL *)url;
/*!
 *  @abstract Get all Products
 *
 *  @discussion
 *  Use this method to get a list of all the NotificareProduct objects that you created in both iTunes Connect and Notificare dashboard.
 */
- (void)fetchProducts:(SuccessArrayBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Get purchased Products
 *
 *  @discussion
 *  Use this method to get a list of all the non-consumable product identifiers that this AppleID has purchased.
 */
- (void)fetchPurchasedProducts:(SuccessArrayBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Product
 *
 *  @discussion
 *  Use this method to get specific NotificareProduct object by providing a product identifier (SKU).
 *  @param productIdentifier A NSString that represents the product identifier
 */
- (void)fetchProduct:(NSString *)productIdentifier completionHandler:(SuccessProductBlock)info errorHandler:(ErrorBlock)error;
/*!
 *  @abstract Buy Product
 *
 *  @discussion
 *  Use this method to allow the user to buy a product. Use the NotificareProduct object retreived by the methods
 *  above to buy a product.
 *  @param product A NotificareProduct object
 */
- (void)buyProduct:(NotificareProduct *)product;
/*!
 *  @abstract Pause Download
 *
 *  @discussion
 *  Use this method to pause any active downloads.
 *  @param downloads A NSArray of SKDownload objects
 */
- (void)pauseDownloads:(NSArray *)downloads;
/*!
 *  @abstract Cancel Download
 *
 *  @discussion
 *  Use this method to cancel one or more active downloads.
 *  @param downloads A NSArray of SKDownload objects
 */
- (void)cancelDownloads:(NSArray *)downloads;
/*!
 *  @abstract Resume Download
 *
 *  @discussion
 *  Use this method to resume one or more paused downloads.
 *  @param downloads A NSArray of SKDownload objects
 */
- (void)resumeDownloads:(NSArray *)downloads;
/*!
 *  @abstract Downloaded Content Path
 *
 *  @discussion
 *  Retrieve the path for the download content of a product using its SKU.
 *  @param productIdentifier A NSString provided by the delegate didFinishLaunchingWithOptions:
 *  @return A NSString representing the path to the product's content
 */
- (NSString *)contentPathForProduct:(NSString *)productIdentifier;

/*!
 *  @abstract SDK Version
 *
 *  @discussion
 *  Retrieve the SDK version. Used by other frameworks to identify the native version.
 *  @return A NSString representing the path to the product's content
 */
- (NSString *)sdkVersion;
/*!
 *  @abstract Passes list
 *
 *  @discussion
 *  Retrieve a list of passes added to the Passbook app that this app can access
 *  @return A NSArray containing PKPasses objects
 */
-(NSArray *)myPasses;

@end

