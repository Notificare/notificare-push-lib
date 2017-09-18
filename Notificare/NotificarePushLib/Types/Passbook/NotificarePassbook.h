//
//  Passbook.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

#if DO_NOT_USE_PASSKIT == 1
#else
#import <PassKit/PassKit.h>
#endif

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


#if DO_NOT_USE_PASSKIT == 1
@interface NotificarePassbook : NSObject <NotificationType, UIWebViewDelegate>
#else
@interface NotificarePassbook : NSObject <NotificationType,PKAddPassesViewControllerDelegate, UIWebViewDelegate>
#endif


@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;

#if DO_NOT_USE_PASSKIT == 1
#else
@property (strong, nonatomic) PKPassLibrary * passLib;
@property (strong, nonatomic) PKPass * pass;
#endif

@property (strong, nonatomic) UIButton * button;
@property (strong, nonatomic) UIViewController * originalView;
@property (strong, nonatomic) UIWebView * webView;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
