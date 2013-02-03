//
//  WebView.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Notification.h"
#import "Action.h"
#import "Content.h"
#import "Attachment.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"

@interface NotificareWebView : NSObject <NotificationType,UIWebViewDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) Notification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;



-(void)openNotification;

@end
