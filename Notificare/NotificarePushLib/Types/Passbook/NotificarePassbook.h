//
//  Passbook.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassKit/PassKit.h>
#import "NotificareNotification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"

#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

#import "NotificareNotification.h"
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificareAttachment.h"


@interface NotificarePassbook : NSObject <NotificationType,PKAddPassesViewControllerDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) PKPassLibrary * passLib;
@property (strong, nonatomic) PKPass * pass;
@property (strong, nonatomic) UIButton * button;
@property (strong, nonatomic) UIViewController * originalView;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
