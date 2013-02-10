//
//  NotificarePushLib.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "NotificareEngine.h"
#import "NSData+Hex.h"
#import "Notificare.h"
#import "NotificareActions.h"
#import "SRWebSocket.h"
#import "Notification.h"


@class NotificarePushLib;

@protocol NotificarePushLibDelegate <NSObject>

@optional

- (void)notificarePushLib:(NotificarePushLib *)library didRegisterForWebsocketsNotifications:(NSData *)token;
- (void)notificarePushLib:(NotificarePushLib *)library didReceiveWebsocketNotification:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToRegisterWebsocketNotifications:(NSError *)error;

- (BOOL)notificarePushLib:(NotificarePushLib *)library shouldHandleNotification:(NSDictionary *)info;

- (void)notificarePushLib:(NotificarePushLib *)library willOpenNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didOpenNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didCloseNotification:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToOpenNotification:(Notification *)notification;

- (void)notificarePushLib:(NotificarePushLib *)library willExecuteAction:(Notification *)notification;
- (void)notificarePushLib:(NotificarePushLib *)library didExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didNotExecuteAction:(NSDictionary *)info;
- (void)notificarePushLib:(NotificarePushLib *)library didFailToExecuteAction:(NSError *)error;


@end

@interface NotificarePushLib : NSObject <SRWebSocketDelegate,NotificareDelegate,NotificareActionsDelegate>

/*!
 The delegate to call on results
 */
@property (nonatomic, assign) id <NotificarePushLibDelegate> delegate;


/*!
 *  @abstract The Noticare engine
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
 *  @abstract The shared singleton implementation
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
+(NotificarePushLib*)shared;

/*!
 *  @abstract The internal request object's method type
 *
 *  @discussion
 *  This method sets the notificare singleton  
 */
- (void)launch;

//Register device for apns
- (void)registerDevice:(NSData *)token;
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID;
- (void)registerDevice:(NSData *)token withUserID:(NSString *)userID withUsername:(NSString *)username;

//Register Device for websockets
- (void)registerDeviceForWebsockets:(NSString *)token;
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID;
- (void)registerDeviceForWebsockets:(NSString *)token withUserID:(NSString *)userID withUsername:(NSString *)username;

//Register Channel
-(void)registerForWebsockets;
-(void)unregisterForWebsockets;


//Handle Badges & Tray
- (void)updateBadge:(NSNumber *)badge;
- (void)cleanTray;

//Handle incoming push notifications
- (void)openNotification:(NSDictionary *)notification;

@end

