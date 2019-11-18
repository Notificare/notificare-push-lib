//
//  NotificareURL.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 3/1/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <WebKit/WKWebsiteDataStore.h>
#import "NotificareNotification.h"
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"

NS_ASSUME_NONNULL_BEGIN

@interface NotificareURL : UIViewController <NotificationType,WKNavigationDelegate,WKUIDelegate,WKScriptMessageHandler>

@property (nonatomic, strong) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) WKWebView *webView;
@property (strong, nonatomic) UIBarButtonItem *actionsButton;

-(id)handleNotification;
-(id)presentNotification;

@end

NS_ASSUME_NONNULL_END

