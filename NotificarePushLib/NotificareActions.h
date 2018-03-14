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

- (void)notificareActions:(NotificareActions *)library willExecuteAction:(NotificareAction *)action;
- (void)notificareActions:(NotificareActions *)library didExecuteAction:(NotificareAction *)action;
- (void)notificareActions:(NotificareActions *)library shouldPerformSelectorWithURL:(NSURL *)url inAction:(NotificareAction *)action;
- (void)notificareActions:(NotificareActions *)library didNotExecuteAction:(NotificareAction *)action;
- (void)notificareActions:(NotificareActions *)library didFailToExecuteAction:(NotificareAction *)action withError:(NSError *)error;

@end


@interface NotificareActions : NSObject <ActionDelegate>

@property (strong, nonatomic) id<NotificareActionsDelegate> actionsDelegate;
@property (strong, nonatomic) id <ActionType> type;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;


- (void)handleAction:(NotificareAction *)action;


@end
