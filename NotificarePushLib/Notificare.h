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

- (void)notificare:(Notificare *)library willOpenNotification:(NotificareNotification *)notification;
- (void)notificare:(Notificare *)library didOpenNotification:(NotificareNotification *)notification;
- (void)notificare:(Notificare *)library didCloseNotification:(NotificareNotification *)notification;
- (void)notificare:(Notificare *)library didFailToOpenNotification:(NotificareNotification *)notification;
- (void)notificare:(Notificare *)library didClickURL:(NSURL *)url inNotification:(NotificareNotification *)notification;

@end


@interface Notificare : NSObject <NotificationDelegate>

@property (nonatomic, assign) id<NotificareDelegate> notificareDelegate;
@property (strong, nonatomic) id <NotificationType> type;
@property (strong, nonatomic) NotificareActions * notificareActions;
@property (assign) BOOL usePassKit;

-(id)handleNotification:(NotificareNotification *)notification;

@end
