//
//  NotificationDelegate.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/25/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Notification.h"
#import "NotificationType.h"

@protocol NotificationType;
@protocol NotificationDelegate <NSObject>

@optional

- (void)notificationType:(id<NotificationType>)type didOpenNotification:(Notification *)notification;
- (void)notificationType:(id<NotificationType>)type didCloseNotification:(Notification *)notification;
- (void)notificationType:(id<NotificationType>)type didFailToOpenNotification:(Notification *)notification;
- (void)notificationType:(id<NotificationType>)type log:(NSDictionary *)info;

@end
