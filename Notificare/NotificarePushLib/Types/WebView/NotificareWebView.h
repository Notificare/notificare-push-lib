//
//  WebView.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Notification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"

@interface NotificareWebView : NSObject <NotificationType>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) Notification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIButton * button;


-(void)openNotification;

@end
