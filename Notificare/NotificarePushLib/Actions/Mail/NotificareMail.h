//
//  NotificareMail.h
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
#import "Action.h"
#import "Notification.h"
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

@interface NotificareMail : NSObject <ActionType,MFMailComposeViewControllerDelegate>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) Action * action;
@property (strong, nonatomic) Notification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) MFMailComposeViewController *mailComposer;

-(void)executeAction;

@end
