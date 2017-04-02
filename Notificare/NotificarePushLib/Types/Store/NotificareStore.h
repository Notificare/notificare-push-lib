//
//  NotificareStore.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
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


@interface NotificareStore : NSObject <NotificationType,SKStoreProductViewControllerDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIViewController * originalView;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
