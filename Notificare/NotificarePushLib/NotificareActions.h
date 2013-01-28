//
//  NotificareActions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "NotificareEngine.h"
#import "Notification.h"

@class NotificareActions;

@protocol NotificareActionsDelegate

@optional

- (void)notificareActions:(NotificareActions *)library willExecuteAction:(Notification *)notification;
- (void)notificareActions:(NotificareActions *)library didExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library didFailToExecuteAction:(NSError *)error;

@end


@interface NotificareActions : NSObject


@property (strong, nonatomic) id<NotificareActionsDelegate> actionsDelegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) Notification * notification;

- (void)executeBackgroundCall:(NSString *)url;


@end
