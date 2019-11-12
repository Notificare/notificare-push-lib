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
#import "NotificareAction.h"
#import "NotificareNotification.h"


NS_ASSUME_NONNULL_BEGIN

@interface NotificareMail : NSObject <ActionType,MFMailComposeViewControllerDelegate>

@property (nonatomic, strong) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareAction * action;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * _Nullable rootViewController;
@property (strong, nonatomic) MFMailComposeViewController *messageComposer;

-(void)executeAction;

@end
NS_ASSUME_NONNULL_END
