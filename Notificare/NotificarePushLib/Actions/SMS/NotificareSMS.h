//
//  NotificareSMS.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import "ActionType.h"
#import "ActionDelegate.h"
#import "NotificareEngine.h"
#import "NotificareAction.h"
#import "NotificareNotification.h"

@interface NotificareSMS : NSObject <ActionType,MFMessageComposeViewControllerDelegate>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) NotificareAction * action;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) MFMessageComposeViewController *messageComposer;


-(void)executeAction;

@end
