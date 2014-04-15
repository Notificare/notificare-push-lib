//
//  Image.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <QuartzCore/QuartzCore.h>
#import "Notification.h"
#import "Action.h"
#import "Content.h"
#import "Attachment.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

@interface NotificareImage : NSObject <NotificationType,UIScrollViewDelegate,UIPageViewControllerDelegate,UIActionSheetDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (nonatomic, strong) Notification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) UIActionSheet *actionSheet;
@property (strong, nonatomic) UIScrollView *scrollView;
@property (strong, nonatomic) UIPageControl *pageControl;
@property (strong, nonatomic) NSMutableArray *imagesArray;
@property (assign, nonatomic) BOOL pageControlUsed;
@property (strong, nonatomic) UIActivityIndicatorView * activityIndicator;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
