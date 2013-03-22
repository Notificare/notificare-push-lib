//
//  NotificareActions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "NotificareEngine.h"
#import "Notification.h"
#import "ActionType.h"
#import "Action.h"

@class NotificareActions;

@protocol NotificareActionsDelegate

@optional

- (void)notificareActions:(NotificareActions *)library willExecuteAction:(Notification *)notification;
- (void)notificareActions:(NotificareActions *)library didExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library shouldPerformSelector:(NSString *)selector;
- (void)notificareActions:(NotificareActions *)library didNotExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library didFailToExecuteAction:(NSError *)error;

@end


@interface NotificareActions : NSObject <ActionDelegate>

@property (strong, nonatomic) id<NotificareActionsDelegate> actionsDelegate;
@property (strong, nonatomic) id <ActionType> type;
@property (strong, nonatomic) Notification * notification;


- (void)handleAction:(Action *)action;


@end
