//
//  WebView.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
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
#import "NSDictionary+FromPlist.h"
#import "NotificareEngine.h"

@interface NotificareUserPreferences : NSObject <NotificationType,UITableViewDelegate, UITableViewDataSource,UIActionSheetDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) UIActionSheet *actionSheet;
@property (strong, nonatomic) NSMutableArray *preferences;
@property (strong, nonatomic) NSMutableArray *categories;



-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
