//
//  ActionDelegate.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Notification.h"
#import "ActionType.h"

@protocol ActionType;
@protocol ActionDelegate <NSObject>

@optional

- (void)actionType:(id<ActionType>)type willExecuteAction:(Notification *)notification;
- (void)actionType:(id<ActionType>)type didExecuteAction:(NSDictionary *)info;
- (void)actionType:(id<ActionType>)type didNotExecuteAction:(NSDictionary *)info;
- (void)actionType:(id<ActionType>)type shouldPerformSelector:(NSString *)selector;
- (void)actionType:(id<ActionType>)type didFailToExecuteAction:(NSError *)error;

@end
