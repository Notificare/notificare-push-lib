//
//  NotificareNone.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 3/28/16.
//  Copyright (c) 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareContent.h"
#import "NotificareNotification.h"
#import "NotificareAction.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"

@interface NotificareNone : NSObject <NotificationType,UIAlertViewDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;

-(void)openNotification;
-(void)sendData:(NSArray *)data;

@end
