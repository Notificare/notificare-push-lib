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
#import "SRWebSocket.h"
#import "Notification.h"
#import <CoreLocation/CoreLocation.h>
#import "NSString+Utils.h"


#define Suppressor(Selector) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Selector; \
_Pragma("clang diagnostic pop") \
} while (0)

typedef void (^SuccessBlock)(NSDictionary * info);
typedef void (^ErrorBlock)(NSError * error);

@class NotificarePushLib;

@protocol NotificarePushLibDelegate <NSObject>

@optional

- (void)notificarePushLib:(NotificarePushLib *)library didRegisterForWebsocketsNotifications:(NSString *)token;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveWebsocketNotification:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterWebsocketNotifications:(NSError *)error;
- (void)notificarePushLib:(NotificarePushLib *)library didCloseWebsocketConnection:(NSString *)reason;

- (BOOL)notificarePushLib:(NotificarePushLib *)library shouldHandleNotification:(NSDictionary *)info;

- (void)notificarePushLib:(NotificarePushLib *)library willOpenNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didOpenNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didCloseNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToOpenNotification:(Notification *)notification;

- (void)notificarePushLib:(NotificarePushLib *)library willExecuteAction:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library shouldPerformSelector:(NSString *)selector;
- (void)notificarePushLib:(NotificarePushLib *)library didNotExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToExecuteAction:(NSError *)error;


@end

@interface NotificarePushLib : NSObject <SRWebSocketDelegate,NotificareDelegate,NotificareActionsDelegate,CLLocationManagerDelegate>

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
 *  @abstract TAn array with notifications
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
- (void)registerForRemoteNotificationsTypes:(UIRemoteNotificationType)types;

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
 *  @seealso
 *  registerDevice:withUserID:
 */
- (void)registerDevice:(NSData *)token;
/*!
 *  @abstract Register Device with ID
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID;
/*!
 *  @abstract Register Device with ID and name
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  Adds another string that can be used to display name
 */
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID withUsername:(NSString *)username;


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
 *  @seealso
 *  registerDeviceForWebsockets:withUserID
 */
- (void)registerDeviceForWebsockets:(NSString *)token;
/*!
 *  @abstract Register Device with ID for WebSockets
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID;
/*!
 *  @abstract Register Device with ID
 *
 *  @discussion
 *  Registers the APNS token from Apple by creating a user profile with any string
 *  This allows the registrations of more than one device in one user profile
 *  You can also map this ID to your existing user ID if you eventually using any means of authentication
 *  @seealso
 *  registerDevice:withUserID:withUsername:
 */
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID withUsername:(NSString *)username;

/*!
 *  @abstract Unregister Device
 *
 *  @discussion
 *  This method allows you to prevent a device from receive notifications without having to remove it from the provider
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
 *  Starts a CLManager using significant changes updates
 */
-(void)startLocationUpdates;

/*!
 *  @abstract Update Device's Location
 *
 *  @discussion
 *  Fetches a notification's full payload. Usually used if you gonna handle the notifications yourself.
 */
- (void)updateLocation:(NSString*)device withLatitude:(float)latitude andLongitude:(float)longitude;

/*!
 *  @abstract Reply action
 *
 *  @discussion
 *  Register an action event manually. Usually needed when you handling notifications yourself and want to use the actions to register a certain user choice.
 */
- (void)reply:(NSString *)notification withLabel:(NSString *)label andData:(NSDictionary *)data;

//Add Tags to a device
- (void)getTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)addTags:(NSArray *)tags;
- (void)addTags:(NSArray *)tags completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;

//Remove Tag from a device
- (void)removeTag:(NSString *)tag;
- (void)removeTag:(NSString *)tag completionHandler:(SuccessBlock)info errorHandler:(ErrorBlock)error;
- (void)clearTags:(SuccessBlock)info errorHandler:(ErrorBlock)error;

@end

