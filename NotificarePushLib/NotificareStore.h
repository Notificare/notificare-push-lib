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
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"

NS_ASSUME_NONNULL_BEGIN

@interface NotificareStore : NSObject <NotificationType,SKStoreProductViewControllerDelegate>

@property (nonatomic, strong) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;

-(id)handleNotification;
-(id)presentNotification;

@end

NS_ASSUME_NONNULL_END
