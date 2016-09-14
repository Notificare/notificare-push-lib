//
//  NotificareActions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "NotificareNotification.h"
#import "ActionType.h"
#import "NotificareAction.h"

@class NotificareActions;

@protocol NotificareActionsDelegate

@optional

- (void)notificareActions:(NotificareActions *)library willExecuteAction:(NotificareNotification *)notification;
- (void)notificareActions:(NotificareActions *)library didExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library shouldPerformSelectorWithURL:(NSURL *)url;
- (void)notificareActions:(NotificareActions *)library didNotExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library didFailToExecuteAction:(NSError *)error;

@end


@interface NotificareActions : NSObject <ActionDelegate>

@property (strong, nonatomic) id<NotificareActionsDelegate> actionsDelegate;
@property (strong, nonatomic) id <ActionType> type;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * originalView;


- (void)handleAction:(NotificareAction *)action;


@end
