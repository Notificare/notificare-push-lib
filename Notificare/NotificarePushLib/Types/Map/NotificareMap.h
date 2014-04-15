//
//  Map.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Action.h"
#import "Content.h"
#import "Attachment.h"
#import "Notification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"
#import <MapKit/MapKit.h>
#import "NotificareLocation.h"
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

@interface NotificareMap : NSObject <NotificationType,MKMapViewDelegate,UIActionSheetDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) Notification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * viewController;
@property (strong, nonatomic) UINavigationController * navigationController;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;
@property (strong, nonatomic) UIActionSheet *actionSheet;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
