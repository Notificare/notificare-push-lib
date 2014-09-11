//
//  ActionType.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareAction.h"
#import "ActionDelegate.h"


@protocol ActionType <NSObject>

-(void)setDelegate:(id<ActionDelegate>)delegate;
-(void)setAction:(NotificareAction *)action;
-(void)setNotification:(NotificareNotification *)notification;
-(void)executeAction;

@end
