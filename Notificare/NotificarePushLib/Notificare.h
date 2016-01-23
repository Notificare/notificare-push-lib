//
//  Notificare.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 12/11/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareActions.h"
#import "NotificationType.h"
#import "NotificareNotification.h"
#import "NotificareAttachment.h"
#import "NotificareContent.h"
#import "NotificareAction.h"

@class Notificare;

@protocol NotificareDelegate

@optional

- (void)notificare:(Notificare *)library willOpenNotification:(NotificareNotification *)info;
- (void)notificare:(Notificare *)library didOpenNotification:(NotificareNotification *)info;
- (void)notificare:(Notificare *)library didCloseNotification:(NotificareNotification *)info;
- (void)notificare:(Notificare *)library didFailToOpenNotification:(NotificareNotification *)info;
- (void)notificare:(Notificare *)library didClickURL:(NSURL *)url inNotification:(NotificareNotification *)notification;
- (void)notificare:(Notificare *)library log:(NSDictionary *)info;
- (void)notificare:(Notificare *)library onPreferencesChanged:(NSDictionary *)info;
- (void)notificare:(Notificare *)library didUpdateBadge:(int)badge;

@end


@interface Notificare : NSObject <NotificationDelegate>

@property (nonatomic, assign) id<NotificareDelegate> notificareDelegate;
@property (strong, nonatomic) NSDictionary * theNotification;
@property (strong, nonatomic) id <NotificationType> type;
@property (strong, nonatomic) NotificareActions * notificareActions;
@property (assign) BOOL displayMessage;

-(void)handleNotification:(NSDictionary*)notification;
-(void)handleNotificationObject:(NotificareNotification *)notification;
-(void)sendData:(NSArray *)data;

@end
