//
//  Image.h
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

NS_ASSUME_NONNULL_BEGIN

@interface NotificareImage : UIViewController <NotificationType,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (nonatomic, strong) UICollectionView * collectionView;
@property (strong, nonatomic) NSMutableArray *imageList;
@property (strong, nonatomic) UIBarButtonItem * actionsButton;

-(id)handleNotification;

@end

NS_ASSUME_NONNULL_END

