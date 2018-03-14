//
//  ActionDelegate.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareNotification.h"
#import "NotificareAction.h"
#import "ActionType.h"

@protocol ActionType;
@protocol ActionDelegate <NSObject>

@optional

- (void)actionType:(id<ActionType>)type willExecuteAction:(NotificareAction *)action;
- (void)actionType:(id<ActionType>)type didExecuteAction:(NotificareAction *)action;
- (void)actionType:(id<ActionType>)type didNotExecuteAction:(NotificareAction *)action;
- (void)actionType:(id<ActionType>)type shouldPerformSelectorWithURL:(NSURL *)url inAction:(NotificareAction *)action;
- (void)actionType:(id<ActionType>)type didFailToExecuteAction:(NotificareAction *)action withError:(NSError *)error;

@end
