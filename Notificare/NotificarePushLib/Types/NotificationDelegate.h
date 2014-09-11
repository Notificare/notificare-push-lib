//
//  NotificationDelegate.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/25/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareNotification.h"
#import "NotificationType.h"

@protocol NotificationType;
@protocol NotificationDelegate <NSObject>

@optional

- (void)notificationType:(id<NotificationType>)type didOpenNotification:(NotificareNotification *)notification;
- (void)notificationType:(id<NotificationType>)type didCloseNotification:(NotificareNotification *)notification;
- (void)notificationType:(id<NotificationType>)type didFailToOpenNotification:(NotificareNotification *)notification;
- (void)notificationType:(id<NotificationType>)type log:(NSDictionary *)info;
- (void)notificationType:(id<NotificationType>)type onPreferencesChanged:(NSDictionary *)info;
- (void)notificationType:(id<NotificationType>)type didUpdateBadge:(int)badge;

@end
