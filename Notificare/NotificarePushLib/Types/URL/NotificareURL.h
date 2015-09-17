//
//  NotificareURL.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 3/1/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareNotification.h"
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificareAttachment.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"
#import <SafariServices/SafariServices.h>

@interface NotificareURL : NSObject <NotificationType,UIWebViewDelegate,UIActionSheetDelegate,SFSafariViewControllerDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UIWebView * webView;
@property (strong, nonatomic) SFSafariViewController * safariViewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) UIBarButtonItem * backButton;
@property (strong, nonatomic) UIBarButtonItem * forwardButton;
@property (strong, nonatomic) UIBarButtonItem * refreshButton;
@property (strong, nonatomic) UIToolbar * toolbar;
@property (strong, nonatomic) UIActionSheet *actionSheet;
@property (strong, nonatomic) UIActivityIndicatorView *activityIndicator;



-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end

