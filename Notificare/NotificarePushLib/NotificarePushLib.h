//
//  NotificarePushLib.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "NotificareEngine.h"
#import "MKNetworkKit.h"
#import "NSData+Hex.h"

@interface NotificarePushLib : NSObject

/*!
 *  @abstract The Noticare engine
 *  @property NotificareEngine
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
@property (strong, nonatomic) NotificareEngine *notificareEngine;
/*!
 *  @abstract The Noticare engine
 *  @property NotificareEngine
 *
 *  @discussion
 *	Returns the operation's method type
 *
 */
@property (strong, nonatomic) NSString * apiID;
/*!
  *  @abstract The Noticare engine
  *  @property NotificareEngine
  *
  *  @discussion
  *	Returns the operation's method type
  *
  */
@property (strong, nonatomic) NSString * apiSecret;

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

//Register device
- (void)registerDevice:(NSData *)token withAlias:(NSString *)alias;

//Handle Badges & Tray
- (void)updateBadge:(NSNumber *)badge;
- (void)cleanTray;

//Handle incoming push notifications
- (void)handleNotification:(NSDictionary *)notification;

//Handle Action
- (void)handleAction:(NSDictionary *)notification;


@end

