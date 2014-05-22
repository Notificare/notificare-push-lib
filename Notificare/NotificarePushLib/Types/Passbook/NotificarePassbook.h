//
//  Passbook.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassKit/PassKit.h>
#import "Notification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"

#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

#import "Notification.h"
#import "Action.h"
#import "Content.h"
#import "Attachment.h"


@interface NotificarePassbook : NSObject <NotificationType,PKAddPassesViewControllerDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) Notification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) PKPassLibrary * passLib;
@property (strong, nonatomic) PKPass * pass;
@property (strong, nonatomic) UIButton * button;


-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
