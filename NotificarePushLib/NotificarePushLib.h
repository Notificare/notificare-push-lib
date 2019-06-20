//
//  NotificarePushLib.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
//
//

/* Utils */
#import "NotificareDefinitions.h"

/* Models */
#import "NotificareNotification.h"
#import "NotificareUser.h"
#import "NotificareUserPreference.h"
#import "NotificareSegment.h"
#import "NotificareRegion.h"
#import "NotificareBeacon.h"
#import "NotificareProduct.h"
#import "NotificareDevice.h"
#import "NotificareDeviceInbox.h"
#import "NotificarePass.h"
#import "NotificationType.h"
#import "NotificareAttachment.h"
#import "NotificareContent.h"
#import "NotificareAction.h"
#import "NotificareAsset.h"
#import "NotificareScannable.h"
#import "NotificareUserData.h"
#import "NotificareDeviceDnD.h"
#import "NotificareLocation.h"
#import "NotificareVisit.h"
#import "NotificareHeading.h"
#import "NotificareSystemNotification.h"


/* Main Classes */
#import "NotificareLogging.h"
#import "NotificareCrashReport.h"
#import "NotificareAppConfig.h"
#import "NotificareNetworkWrapper.h"
#import "NotificareEventLogger.h"
#import "NotificareAppDelegateSurrogate.h"
#import "NotificareDeviceManager.h"
#import "Notificare.h"
#import "NotificareActions.h"
#import "NotificarePush.h"
#import "NotificareMonetize.h"
#import "NotificareInboxManager.h"
#import "NotificareStorage.h"
#import "NotificareAuth.h"
#import "NotificareGeo.h"
#import "NotificareScannables.h"
#import "NotificareLoyalty.h"

/* Libraries */
#import "NotificareNXOAuth2.h"
#import "NotificareNetworkHost.h"


NS_ASSUME_NONNULL_BEGIN
/**
 * Blocks definitions
 */
typedef void (^NotificareCompletionBlock)(id _Nullable response , NSError * _Nullable error);

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

/*
 * Device Delegates
 */

/*!
 * @brief Optional. This delegate method will be triggered when a device is registered for the first time or updated.
 * @param device A NotificareDevice object containing the device registered or updated
 */
- (void)notificarePushLib:(NotificarePushLib *)library didRegisterDevice:(NotificareDevice *)device;

/*!
 * @brief Optional. This delegate method will be triggered when a device could not register for notifications with APNS in response to the registerForNotifications method.
 * @param error A NSError object containing the error
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterForNotificationsWithError:(NSError *)error;

/*
 * Push Delegates
 */
/*!
 * @brief Optional. This delegate method will be triggered when changes to notification settings occur.
 * @param granted A boolean representing if users granted authorization to post user notifications
 */
- (void)notificarePushLib:(NotificarePushLib *)library didChangeNotificationSettings:(BOOL)granted;
/*!
 * @brief Optional. This delegate method will be triggered when a launch URL key is detected.
 * @param launchURL A NSURL object containing the url received on launch
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveLaunchURL:(NSURL *)launchURL;
/*!
 * @brief Optional. This delegate method will be triggered when a remote notification is received in the background.
 * @param notification A NotificareNotification object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveRemoteNotificationInBackground:(NotificareNotification *)notification withController:(id _Nullable)controller;
/*!
 * @brief Optional. This delegate method will be triggered when a remote notification is received in the foreground.
 * @param notification A NotificareNotification object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveRemoteNotificationInForeground:(NotificareNotification *)notification withController:(id _Nullable)controller;

/*!
 * @brief Optional. This delegate method will be triggered when a system (silent) remote notification is received in the background.
 * @param notification A NotificareNotification object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveSystemNotificationInBackground:(NotificareSystemNotification *)notification;

/*!
 * @brief Optional. This delegate method will be triggered when a system (silent) remote notification is received in the foreground.
 * @param notification A NotificareNotification object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveSystemNotificationInForeground:(NotificareSystemNotification *)notification;

/*!
 * @brief Optional. This delegate method will be triggered when a remote or local notification is received from an unrecognizable source.
 * @param notification A NSDictionary object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveUnknownNotification:(NSDictionary *)notification;

/*!
 * @brief Optional. This delegate method will be triggered when a remote or local action in a notification is received from an unrecognizable source.
 * @param notification A NSDictionary object containing the notification received
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveUnknownAction:(NSDictionary *)action forNotification:(NSDictionary *)notification;

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
 * @param action A NotificareAction object that represents the notification
 */
- (void)notificarePushLib:(NotificarePushLib *)library willExecuteAction:(NotificareAction *)action;
/*!
 * @brief Optional. This delegate method will be triggered when the action is executed.
 * @param action A NotificareAction object that represents the user selectable action
 */
- (void)notificarePushLib:(NotificarePushLib *)library didExecuteAction:(NotificareAction *)action;
/*!
 * @brief Optional. This delegate method will be triggered when the user clicks an action of type Custom. you should use it to perform a method in your own code.
 * @param url A NSURL object
 * @code -(void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelectorWithURL:(NSURL *)url{
 [self performSelector:[url host] withObject:[url path]]
 }
 */
- (void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelectorWithURL:(NSURL *)url inAction:(NotificareAction *)action;
/*!
 * @brief Optional. This delegate method will be triggered when the action was cancelled.
 * @param action A NotificareAction object that represents the user selectable action
 */
- (void)notificarePushLib:(NotificarePushLib *)library didNotExecuteAction:(NotificareAction *)action;
/*!
 * @brief Optional. This delegate method will be triggered when the user selectable action fails to be executed.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToExecuteAction:(NotificareAction *)action withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered when a Wallet pass it received. If not implemented or not supported by the device it will not be triggered and instead we will present the user a web version of the pass.
 * @param pass A NotificarePass object that should be handled by the PKAddPassesViewController
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceivePass:(NSURL *)pass inNotification:(NotificareNotification*)notification;
/*!
 * @brief Optional. This delegate method will be triggered when the user clicks from Instant Tuning and Notification Settings and it should take users to the in-app settings screen.
 * @param notification A NotificareNotification object
 * @code -(void)notificarePushLib:(NotificarePushLib *)library shouldOpenSettings:(NotificareNotification * _Nullable)notification{
    //Handle deep link to settings view
 }
 */
- (void)notificarePushLib:(NotificarePushLib *)library shouldOpenSettings:(NotificareNotification* _Nullable)notification;
/*
 * Inbox Delegates
 */

/*!
 * @brief Optional. This delegate method will be triggered when the inbox is loaded, notifications arrive or is updated. This delegate will only be triggered if application has useInbox ON. It will contain the recently received messages if any. Use this delegate to refresh your list of messages.
 * @param items A NSArray of NotificareDeviceInbox objects
 */
- (void)notificarePushLib:(NotificarePushLib *)library didLoadInbox:(NSArray<NotificareDeviceInbox*>*)items;

/*!
 * @brief Optional. This delegate method will be triggered when the inbox is loaded, notifications arrive or is updated. This delegate will only be triggered if application has autoBadge ON. Use this delegate to refresh your UI.
 * @param badge A int number
 */
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateBadge:(int)badge;


/*
 * Location Services Delegates
 */
/*!
 * @brief Optional. This delegate method will be triggered when it fails to start location updates.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToStartLocationServiceWithError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered as response to a start location updates.
 * @param status A NSDictionary object that contains information about the location services' status
 */
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveLocationServiceAuthorizationStatus:(NotificareGeoAuthorizationStatus)status;
/*!
 * @brief Optional. This delegate method will be triggered every time a new location update is received.
 * @param locations A NSArray that contains a list of NotificareLocation objects
 */
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateLocations:(NSArray<NotificareLocation*> *)locations;
/*!
 * @brief Optional. This delegate method will be triggered every time a region fails to be monitored.
 * @param region A NotificareRegion or NotificareBeacon object
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library monitoringDidFailForRegion:(id)region withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered every time a region starts to be monitored.
 * @param region A NotificareRegion or NotificareBeacon object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didStartMonitoringForRegion:(id)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a region starts to be monitored.
 * @constant state A NotificareRegionState constant that represents the state of the region
 * @param region A NotificareRegion or NotificareBeacon object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didDetermineState:(NotificareRegionState)state forRegion:(id)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a device enters a monitored region.
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didEnterRegion:(id)region;
/*!
 * @brief Optional. This delegate method will be triggered every time a device exits a monitored region.
 * @param region A CLRegion object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didExitRegion:(id)region;
/*!
 * @brief Optional. This delegate method will be triggered whenever Core Location fails to range beacons for a region.
 * @param region A NotificareBeacon object
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library rangingBeaconsDidFailForRegion:(NotificareBeacon *)region withError:(NSError *)error;
/*!
 * @brief Optional. This delegate method will be triggered every time a region is ranging for beacons.
 * @param beacons A NSArray containing the list of NotificareBeacon found in range
 * @param region A NotificareBeacon object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didRangeBeacons:(NSArray<NotificareBeacon *> *)beacons inRegion:(NotificareBeacon *)region;
/*!
* @brief Optional. This delegate method will be triggered every time the heading updates. Requires the use of the Heading API. This can be set in the options object in the Notificare.plist
* @param heading A NotificareHeading object
*/
- (void)notificarePushLib:(NotificarePushLib *)library didUpdateHeading:(NotificareHeading*)heading;
/*!
 * @brief Optional. This delegate method will be triggered every time a visit is received. Requires the use of the Visits API. This can be set in the options object in the Notificare.plist
 * @param visit A NotificareVisit object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didVisit:(NotificareVisit*)visit;

/*
 * Users & Authentication Delegates
 */

/*!
 * @brief Optional. This delegate method will be triggered every time a user authenticates. Use it to update UI.
 * @param info A NSDictionary containing the user data
 */
- (void)notificarePushLib:(NotificarePushLib *)library didChangeAccountState:(NSDictionary *)info;
/*!
 * @brief Optional. This delegate method will be triggered every time user logs out. Use it to update UI.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRenewAccountSessionWithError:(NSError * _Nullable)error;
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

/*
 * In-App Purchase Delegates
 */

/*!
 * @brief Optional. This delegate method will be triggered soon the product's store is loaded. Use it to update UI.
 * @param products A NSArray containing the list of products
 */
- (void)notificarePushLib:(NotificarePushLib *)library didLoadStore:(NSArray<NotificareProduct *> *)products;
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

/*
 * Scannables Delegates
 */
/*!
 * @brief Optional. This delegate method will be triggered whenever a QR Code Scanner built-in component starts.
 * @param scanner A UIViewController object
 */
-(void)notificarePushLib:(NotificarePushLib *)library didStartQRCodeScanner:(UIViewController*)scanner;
/*!
 * @brief Optional. This delegate method will be triggered whenever a Scannable Session invalidates.
 * @param error A NSError object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didInvalidateScannableSessionWithError:(NSError *)error;

/*!
 * @brief Optional. This delegate method will be triggered whenever a Scannable Session detects an object.
 * @param scannable A NotificareScannable object
 */
- (void)notificarePushLib:(NotificarePushLib *)library didDetectScannable:(NotificareScannable *)scannable;

@required

/*!
 * @brief Required. This delegate method will be triggered whenever the library is ready. Only after this delegate has been triggered you will be able to call any other method or receive any delegate from this library.
 * @param application A NotificareApplication object containing information about this app's information
 * @code - (void)notificarePushLib:(NotificarePushLib *)library onReady:(NotificareApplication *)application{
     [[NotificarePushLib shared] registerForNotifications];
 }
 */
- (void)notificarePushLib:(NotificarePushLib *)library onReady:(NotificareApplication *)application;

@end


@interface NotificarePushLib : NSObject <UIApplicationDelegate, NotificareDeviceManagerDelegate, NotificarePushDelegate, NotificareMonetizeDelegate, NotificareInboxManagerDelegate, NotificareAuthDelegate, NotificareGeoDelegate, NotificareScannablesDelegate>

/*!
 *  @abstract Protocol of NotificarePushLib class that handles events
 *  @property NotificarePushLibDelegate
 *
 */
@property (nonatomic, assign) id <NotificarePushLibDelegate> delegate;

/*!
 *  @abstract Authorization Options for iOS 10 and higher
 *  @discussion
 *  A UNAuthorizationOptions holds constants indicating which authorization options should be used. Possible values are: UNAuthorizationOptionAlert, UNAuthorizationOptionSound, UNAuthorizationOptionBadge, UNAuthorizationOptionCarPlay, UNAuthorizationOptionProvisional, UNAuthorizationOptionProvidesAppNotificationSettings and UNAuthorizationOptionCriticalAlert. If none is provided it will default to UNAuthorizationOptionAlert, UNAuthorizationOptionSound, UNAuthorizationOptionBadge.
 *  @property presentationOptions
 *
 */
@property (nonatomic,assign) UNAuthorizationOptions authorizationOptions NS_AVAILABLE_IOS(10.0);

/*!
 *  @abstract Presentation Options for iOS 10 and higher
 *  @discussion
 *  A UNNotificationPresentationOptions holds constants indicating how to handle notifications when app is active. Possible values are: UNNotificationPresentationOptionAlert, UNNotificationPresentationOptionBadge, UNNotificationPresentationOptionSound or UNNotificationPresentationOptionNone. If none is provided it will default to UNNotificationPresentationOptionNone.
 *  @property presentationOptions
 *
 */
@property (nonatomic,assign) UNNotificationPresentationOptions presentationOptions NS_AVAILABLE_IOS(10.0);

/*!
 *  @abstract Category Options for iOS 10 and higher
 *  @discussion
 *  A UNNotificationCategoryOptions holds constants indicating how to handle notifications' categories should behave. Possible values are: UNNotificationCategoryOptionCustomDismissAction, UNNotificationCategoryOptionHiddenPreviewsShowTitle, UNNotificationCategoryOptionHiddenPreviewsShowSubtitle, UNNotificationCategoryOptionAllowInCarPlay and UNNotificationCategoryOptionNone. If none is provided it will default to UNNotificationCategoryOptionCustomDismissAction + UNNotificationCategoryOptionHiddenPreviewsShowTitle in iOS 11 and UNNotificationCategoryOptionCustomDismissAction in iOS 10.
 *  @property categoryOptions
 *
 */
@property (nonatomic,assign) UNNotificationCategoryOptions categoryOptions NS_AVAILABLE_IOS(10.0);
/*!
 *  @abstract User Notification Center for iOS 10 and higher
 *  @discussion
 *    A UNUserNotificationCenter object holds a reference to the device notification center.
 *  @property userNotificationCenter
 *
 */
@property (nonatomic,assign) UNUserNotificationCenter *userNotificationCenter NS_AVAILABLE_IOS(10.0);

/*!
 *  @abstract The shared singleton implementation
 *
 *  @discussion
 *    Returns the operation's method type
 *
 */
+(NotificarePushLib*)shared;

/*!
 *  @abstract Initializer
 *  @property key The App key
 *  @property secret The App secret
 
 *  @discussion
 *  Initializes the NotificarePushLib, should be the first method to be invoked in your App Delegate. In this method you can override the app keys defined in Notificare.plist.
 */
-(void)initializeWithKey:(NSString * _Nullable)key andSecret:(NSString * _Nullable)secret;

/*!
 *  @abstract Initial setup
 *
 *  @discussion
 *  Launches the NotificarePushLib with the initialized coniguration. This method should be invoked whenever you want to start using the library. In response to this method the onReady delegate will be triggered.
 */
- (void)launch;

/*!
 *  @abstract The App
 *  @property application
 *
 *  @discussion
 *  A NotificareApplication object representing the Application
 *
 */
@property (strong, nonatomic) NotificareApplication * application;

/*!
 *  @abstract The Inbox Manager
 *  @property inboxManager
 *
 *  @discussion
 *  A NotificareInboxManager class that handles the inbox items
 *
 */
@property (strong, nonatomic) NotificareInboxManager * inboxManager;

/*!
 *  @abstract The Auth Manager
 *  @property authManager
 *
 *  @discussion
 *  A NotificareAuth class that handles authentication using OAuth2
 *
 */
@property (strong, nonatomic) NotificareAuth * authManager;

/*!
 *  @abstract Handle URL Schemes
 *  @property url
 *  @property options
 *
 *  @discussion
 *  Handles additional functionality to a URL Schemes interaction. Should be used in -(BOOL)application:openURL:options:
 *
 */
-(void)handleOpenURL:(NSURL *)url withOptions:(NSDictionary * _Nullable)options;

/*!
 *  @abstract Register For Notifications
 *
 *  @discussion
 *  Register the device for remote push notifications. Make sure you only invoke this method after the onReady delegate.
 */
- (void)registerForNotifications;

/*!
 *  @abstract Unregister For Notifications
 *
 *  @discussion
 *  Unregister the device for remote push notifications. Make sure you only invoke this method after the onReady delegate.
 */
- (void)unregisterForNotifications;

/*!
 *  @abstract Check if Remote Notifications are ON
 *
 *  @discussion
 *  Use this method to quickly identify if the user has a valid APNS token
 *  @return A Boolean indicating if an APNS token has been requested and registered
 */
-(BOOL)remoteNotificationsEnabled;
/*!
 *  @abstract Check if User allowed Alerts, Badges and Sounds
 *
 *  @discussion
 *  Use this method to quickly identify if the user has allowed alerts, badge and sounds
 *  @return A Boolean indicating if the user has allowed alerts, badge and sounds
 */
-(BOOL)allowedUIEnabled;
/*!
 *  @abstract Check if Remote Notification is from Notificare
 *
 *  @discussion
 *  Use this method to quickly identify if the a notification is from Notificare
 *  @return A Boolean indicating if the a notification is from Notificare
 */
-(BOOL)isNotificationFromNotificare:(NSDictionary*)userInfo;
/*!
 *  @abstract The device
 *
 *  @discussion
 *  Access the registered device if any
 */
- (NotificareDevice *)myDevice;

/*!
 * @brief This method should be used to register the device token with Notificare. Make sure you only invoke this method after the onReady delegate.
 * @param userID A NSString representing the userID. It should be unique.
 * @param username A NSString representing the username.
 */
- (void)registerDevice:(NSString * _Nullable)userID withUsername:(NSString * _Nullable)username completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 * @abstract Preferred Language
 *
 * @discussion
 * Use this method to retrieve the current preferred language. If none was set before this completion block will return nil.
*  @return A NSString or nil indicating if a preferred langauge has been set
 */
- (NSString* _Nullable)preferredLanguage;

/*!
 * @abstract Update Preferred Language
 *
 * @discussion
 *  This method should be used to override the system language for this device. Make sure you only invoke this method after the didRegisterDevice delegate. If never invoked, the [NSLocale preferredLanguages] will be used.
 * @param language A NSString representing the language (ISO 639-1) and region (ISO 3166-2) (e.g. en-US).
 */
- (void)updatePreferredLanguage:(NSString * _Nullable)language completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Get all tags
 *
 *  @discussion
 *  Get all the tags a device has been added to the device. Make sure you only invoke this method after the onReady delegate.
 */
- (void)fetchTags:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Add one or more tags to the device
 *
 *  @discussion
 *  Add one or more tags to a device. This method uses blocks that returns success or failure for this operation. Make sure you only invoke this method after the onReady delegate.
 *  @param tags A NSArray that contains a list of tags to be added to the device
 */
- (void)addTags:(NSArray *)tags completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Add a tag to the device
 *
 *  @discussion
 *  Add one tag to a device. This method uses blocks that returns success or failure for this operation. Make sure you only invoke this method after the onReady delegate.
 *  @param tag A NSString that represents the tag to be added to the device
 */
- (void)addTag:(NSString *)tag completionHandler:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Remove one or more tags from the device
 *
 *  @discussion
 *  Remove one or more tags from a device. This method uses blocks that returns success or failure for this operation. Make sure you only invoke this method after the onReady delegate.
 *  @param tags A NSArray with a list of tags to be removed from the device
 */
- (void)removeTags:(NSArray *)tags completionHandler:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Remove a tag to the device
 *
 *  @discussion
 *  Remove a tag from a device. This method uses blocks that returns success or failure for this operation. Make sure you only invoke this method after the onReady delegate.
 *  @param tag A NSString that represents the tag to be removed from the device
 */
- (void)removeTag:(NSString *)tag completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Remove all tags from the device
 *
 *  @discussion
 *  Remove all tags from a device. This method uses blocks that returns success or failure for this operation. Make sure you only invoke this method after the onReady delegate.
 */
- (void)clearTags:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Fetch User Data
 *
 *  @discussion
 *  Invoke this method to retrieve an NSArray of NotificareUserData objects associated with this device. Make sure you only invoke this method after the onReady delegate.
 */
- (void)fetchUserData:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Update User Data
 *
 *  @discussion
 *  Invoke this method to update User Data Fields associated with this device. Only fields added to the application will be considered. Make sure you only invoke this method after the onReady delegate.
 *  @param fields A NSArray of NotificareUserData objects to be updated
 */
- (void)updateUserData:(NSArray<NotificareUserData *> *)fields completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Fetch Do Not Disturb Times
 *
 *  @discussion
 *  Retrieves the NotificareDeviceDnD object with the do not disturb times for a device. Make sure you only invoke this method after the onReady delegate.
 */
- (void)fetchDoNotDisturb:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Update Do Not Disturb Times
 *
 *  @discussion
 *  Updates the device do not disturb times
 *  @param dnd A NotificareDeviceDnD object that represents the DnD for this device. Make sure you only invoke this method after the onReady delegate.
 */
- (void)updateDoNotDisturb:(NotificareDeviceDnD *)dnd completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Clear Do Not Disturb Times
 *
 *  @discussion
 *  Clears the device do not disturb times. Make sure you only invoke this method after the onReady delegate.
 */
- (void)clearDoNotDisturb:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Get a NotificareNotification object
 *
 *  @discussion
 *  Helper method to get a NotificareNotification object on-demand. Make sure you only invoke this method after the onReady delegate.
 *  @param notification A NSString/NotificareDeviceInbox/NSDictionary object
 */
- (void)fetchNotification:(id)notification completionHandler:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Get a controller for a NotificareNotification object
 *
 *  @discussion
 *  Helper method to get a controller for a NotificareNotification object on-demand.
 *  @param notification A NotificareNotification object
 */
- (id)controllerForNotification:(NotificareNotification *)notification;
/*!
 *  @abstract Clear a Private Notification
 *
 *  @discussion
 *  This method will remove any data from a private notification (private notification are messages sent to a user or device). Invoking this method on any other notification will result in an error. Make sure you only invoke this method after the onReady delegate.
 *  @param notification A NotificareNotification object
 */
- (void)clearPrivateNotification:(NotificareNotification *)notification completionHandler:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Reply to a Notification
 *
 *  @discussion
 *  This method will reply to a notification's action. This is usually done by the notification itself but with this method it can be requested on-demand. Make sure you only invoke this method after the onReady delegate.
 *  @param notification A NotificareNotification object
 *  @param action A NotificareAction object
 *  @param data A NSDictionary object
 */
- (void)reply:(NotificareNotification *)notification forAction:(NotificareAction *)action andData:(NSDictionary * _Nullable)data completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Present a Notification
 *
 *  @discussion
 *  This helper method will handle a notification presentation given your own navigation controller and the controller received from us. This is usually done in response to the didReceiveNotificationInBackground or from the completion block of the openInboxItem.
 *  @param notification A NotificareNotification object
 *  @param navigationController A UINavigationController object
 *  @param controller A UIAlertController or UIViewController object
 */
-(void)presentNotification:(NotificareNotification*)notification inNavigationController:(UINavigationController*)navigationController withController:(id)controller;

/*!
 *  @abstract Present an Inbox Item
 *
 *  @discussion
 *  This helper method will handle an inbox item presentation given your own navigation controller and the controller received from us. This is usually done in response to the completion block of the openInboxItem method.
 *  @param inboxItem A NotificareDeviceInbox object
 *  @param navigationController A UINavigationController object
 *  @param controller A UIAlertController or UIViewController object
 */
-(void)presentInboxItem:(NotificareDeviceInbox*)inboxItem inNavigationController:(UINavigationController*)navigationController withController:(id)controller;

/*!
 *  @abstract Present a Wallet pass
 *
 *  @discussion
 *  This helper method will handle a Wallet pass presentation given your own navigation controller and a PKAddPassesViewController. This is usually done in response to the didReceivePass delegate.
 *  @param notification A NotificareNotification object
 *  @param navigationController A UINavigationController object
 *  @param controller A UIAlertController or UIViewController object
 */
-(void)presentWalletPass:(NotificareNotification*)notification inNavigationController:(UINavigationController*)navigationController withController:(id)controller;

/*!
 *  @abstract Fetch an Asset Group
 *
 *  @discussion
 *  Retrieves a list of assets from a specific group
 *  @param group A NSString that indentifies the group name
 */
-(void)fetchAssets:(NSString*)group completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Fetch a Pass with Serial
 *
 *  @discussion
 *  Retrieves a Pass object using the auto-generated serial
 *  @param serial A NSString that indentifies the pass serial
 */
-(void)fetchPassWithSerial:(NSString*)serial completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Fetch a Pass with Barcode
 *
 *  @discussion
 *  Retrieves a Pass object using the custom barcode
 *  @param barcode A NSString that indentifies the pass barcode
 */
-(void)fetchPassWithBarcode:(NSString*)barcode completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Get all Products
 *
 *  @discussion
 *  Use this method to get a list of all the NotificareProduct objects that you created in both iTunes Connect and Notificare dashboard.
 */
- (void)fetchProducts:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Get purchased Products
 *
 *  @discussion
 *  Use this method to get a list of all the non-consumable product identifiers that this AppleID has purchased.
 */
- (void)fetchPurchasedProducts:(NotificareCompletionBlock)completionBlock;
/*!
 *  @abstract Product
 *
 *  @discussion
 *  Use this method to get specific NotificareProduct object by providing a product identifier (SKU).
 *  @param productIdentifier A NSString that represents the product identifier
 */
- (void)fetchProduct:(NSString *)productIdentifier completionHandler:(NotificareCompletionBlock)completionBlock;
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
- (void)pauseDownloads:(NSArray<SKDownload *> *)downloads;
/*!
 *  @abstract Cancel Download
 *
 *  @discussion
 *  Use this method to cancel one or more active downloads.
 *  @param downloads A NSArray of SKDownload objects
 */
- (void)cancelDownloads:(NSArray<SKDownload *>  *)downloads;
/*!
 *  @abstract Resume Download
 *
 *  @discussion
 *  Use this method to resume one or more paused downloads.
 *  @param downloads A NSArray of SKDownload objects
 */
- (void)resumeDownloads:(NSArray<SKDownload *>  *)downloads;
/*!
 *  @abstract Downloaded Content Path
 *
 *  @discussion
 *  Retrieve the path for the download content of a product using its SKU.
 *  @param productIdentifier A NSString representing the product's ideintifier
 *  @return A NSString representing the path to the product's content
 */
- (NSString *)contentPathForProduct:(NSString *)productIdentifier;

/*!
 *  @abstract Start Location Updates
 *
 *  @discussion
 *  Starts the location manager for geo-targeting, geo-fencing and beacons. It will prompt the user with a permission dialog for location services if the user allows location services, this dialog will never be shown. Since iOS8 the key NSLocationAlwaysUsageDescription in your app's info.plist is required. For app's supporting older versions, use NSLocationUsageDescription key too. These keys should contain a text explaining why your app requires locations updates. After iOS 11 you should also use NSLocationAlwaysAndWhenInUseUsageDescription and NSLocationWhenInUseUsageDescription keys.
 */
-(void)startLocationUpdates;
/*!
 *  @abstract Check if Location Updates are ON
 *
 *  @discussion
 *  Use this method to quickly identify if the user has allowed location services
 *  @return A Boolean indicating if location services are on or off
 */
-(BOOL)locationServicesEnabled;
/*!
 *  @abstract Stop Location Updates
 *
 *  @discussion
 *  Stops the location manager from collecting location updates
 */
-(void)stopLocationUpdates;

/*!
 *  @abstract Start a Scannable Session for a QRCode
 *
 *  @discussion
 *  Uses a built-in component that allows scanning QR Codes
 *  @param navigationController A UINavigationController provided by you where the scanner should be pushed or presented.
 *  @param asModal A Boolean that indicates if the view should be push or presented.
 */
-(void)startScannableSessionWithQRCode:(UINavigationController*)navigationController asModal:(BOOL)asModal;
/*!
 *  @abstract Fetch a Scannable object
 *
 *  @discussion
 *  Requests a Scannable object from the server that matches a certain payload
 *  @param message A NSString retrieved from a NFCNDEFReaderSession or from the camera app
 */
-(void)fetchScannable:(NSString *)message;
/*!
 *  @abstract Parse URI Payload
 *
 *  @discussion
 *  This is a helper method to parse a payload of a NFC tag and retrieve its encoded URL
 *  @param data A NSData object from a tag payload
 */
- (nullable NSString *)parseURIPayload:(NSData*)data;

/*!
 *  @abstract Open a scannable
 *
 *  @discussion
 *  Fetches a scannable object with a notification (if any) and returns a controller ready to be presented
 *  @param scannable A NotificareScannable object
 */
- (void)openScannable:(NotificareScannable *)scannable completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Present a Scannable
 *
 *  @discussion
 *  This helper method will handle a scannable presentation given your own navigation controller and the controller received from us. This is usually done in response to the completion block of the openScannable method.
 *  @param scannable A NotificareScannable object
 *  @param navigationController A UINavigationController object
 *  @param controller A UIAlertController or UIViewController object
 */
-(void)presentScannable:(NotificareScannable*)scannable inNavigationController:(UINavigationController*)navigationController withController:(id)controller;

/*!
 *  @abstract Fetch Rich Content Attachments
 *
 *  @discussion
 *  Helper method to retrieve the attachment of a rich content notification
 *  @param notification A NSDictionary holding the APNS payload
 */
- (void)fetchAttachment:(NSDictionary *)notification completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Log an event
 *
 *  @discussion
 *  Helper method to log a Notificare event
 *  @param event A NSString representing the event type (please check all macro definitions starting with kNotificareEvent)
 *  @param data A NSDictionary object containing extraneous data for an event (optional)
 */
- (void)logEvent:(NSString *)event withData:(NSDictionary* _Nullable)data completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 *  @abstract Log a custom event
 *
 *  @discussion
 *  Helper method to log a custom event
 *  @param event A NSString representing the event name
 *  @param data A NSDictionary object containing arbitrary data for an event (optional)
 */
- (void)logCustomEvent:(NSString *)event withData:(NSDictionary* _Nullable)data completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 * @abstract Basic request method for Push API
 *
 * @discussion
 * Creates and executes a Push API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param bodyJSON The JSON payload for the request's body
 */
- (void)doPushHostOperation:(NSString *)HTTPMethod path:(NSString *)path URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams bodyJSON:(id _Nullable)bodyJSON completionHandler:(NotificareCompletionBlock)completionBlock;

/*!
 * @abstract Basic request method for Cloud API
 *
 * @discussion
 * Creates and executes a Cloud API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param customHeaders Key/value pairs for optional custom HTTPS headers
 * @param bodyJSON The JSON payload for the request's body
 */
- (void)doCloudHostOperation:(NSString *)HTTPMethod path:(NSString *)path URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams customHeaders:(NSDictionary<NSString *, NSString *> * _Nullable)customHeaders bodyJSON:(id _Nullable)bodyJSON completionHandler:(NotificareCompletionBlock)completionBlock;


/**
 * Non-Managed Methods
 * To be implemented in case you need to disable App Delegate Proxy. This is done by setting the property (boolean) DISABLE_APP_DELEGATE_PROXY to YES in the Notificare.plist under OPTIONS.
 */

/*!
 * @abstract Handle Launch Options
 *
 * @discussion
 * When the App Delegate Proxy is disabled this method must be implemented in order to handle launch options. Implement this method after launching the library in the application:didFinishLaunchingWithOptions.
 * @param launchOptions The NSDictionary object provided by the application launch
 */
- (void)didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;
/*!
 * @abstract Handle Device registration
 *
 * @discussion
 * When the App Delegate Proxy is disabled this method must be implemented in order to handle device registration. Must be used in the delegate method application:didRegisterForRemoteNotificationsWithDeviceToken.
 * @param deviceToken The NSData object provided by the app delegate method application:didRegisterForRemoteNotificationsWithDeviceToken
 */
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken;
/*!
 * @abstract Handle Remote Notifications
 *
 * @discussion
 * When the App Delegate Proxy is disabled this method must be implemented in order to handle remote notifications. Must be used in the delegate method application:didReceiveRemoteNotification.
 * @param userInfo The NSDictionary object provided by the app delegate method application:didReceiveRemoteNotification
 */
- (void)didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo completionHandler:(NotificareCompletionBlock)completionBlock;
/*!
 * @abstract Handle User Notification Settings (iOS 9 and below)
 *
 * @discussion
 * When the App Delegate Proxy is disabled this method must be implemented in order to handle user notification settings. Must be used in the delegate method application:didRegisterUserNotificationSettings.
 * @param notificationSettings The UIUserNotificationSettings object provided by the app delegate method application:didRegisterUserNotificationSettings
 */
- (void)didRegisterUserNotificationSettings:(nonnull UIUserNotificationSettings *)notificationSettings NS_CLASS_DEPRECATED_IOS(8_0, 10_0, "Use UserNotifications Framework's UNNotificationSettings");
/*!
 * @abstract Handle Actions Settings (iOS 9 and below)
 *
 * @discussion
 * When the App Delegate Proxy is disabled this method must be implemented in order to handle actions. Must be used in the delegate method application:handleActionWithIdentifier:forRemoteNotification: or application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:.
 * @param identifier The NSString object provided by the app delegate method
 * @param userInfo The NSDictionary object provided by the app delegate method
 * @param responseInfo The NSDictionary object provided by the app delegate method
 */
- (void)handleActionWithIdentifier:(nullable NSString *)identifier forRemoteNotification:(nonnull NSDictionary *)userInfo withResponseInfo:(nullable NSDictionary *)responseInfo completionHandler:(NotificareCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
