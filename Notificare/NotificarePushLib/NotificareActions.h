//
//  NotificareActions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "MKNetworkKit.h"
#import "NotificareEngine.h"

@class NotificareActions;

@protocol NotificareActionsDelegate

@optional

- (void)notificareActions:(NotificareActions *)library willExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library didExecuteAction:(NSDictionary *)info;
- (void)notificareActions:(NotificareActions *)library didFailToExecuteAction:(NSDictionary *)info;

@end


@interface NotificareActions : NSObject


@property (strong, nonatomic) id<NotificareActionsDelegate> actionsDelegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;



@end
