//
//  NotificationType.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/25/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificationDelegate.h"
#import "NotificareActions.h"


@protocol NotificationType <NSObject>

-(void)setDelegate:(id<NotificationDelegate>)delegate;
-(void)setNotification:(NotificareNotification *)notification;
-(void)setNotificareActions:(NotificareActions *)notificareActions;
-(void)openNotification;
-(void)sendData:(NSArray *)data;


@end
