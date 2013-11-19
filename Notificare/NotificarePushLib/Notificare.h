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
#import "Notification.h"
#import "Attachment.h"
#import "Content.h"
#import "Action.h"

@class Notificare;

@protocol NotificareDelegate

@optional

- (void)notificare:(Notificare *)library willOpenNotification:(Notification *)info;
- (void)notificare:(Notificare *)library didOpenNotification:(Notification *)info;
- (void)notificare:(Notificare *)library didCloseNotification:(Notification *)info;
- (void)notificare:(Notificare *)library didFailToOpenNotification:(Notification *)info;
- (void)notificare:(Notificare *)library log:(NSDictionary *)info;

@end


@interface Notificare : NSObject <NotificationDelegate>

@property (nonatomic, assign) id<NotificareDelegate> notificareDelegate;
@property (strong, nonatomic) NSDictionary * theNotification;
@property (strong, nonatomic) id <NotificationType> type;
@property (strong, nonatomic) NotificareActions * notificareActions;
@property (assign) BOOL displayMessage;

-(void)handleNotification:(NSDictionary*)notification;
-(void)handleNotificationObject:(Notification *)notification;

@end
