//
//  NotificareTelephone.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionType.h"
#import "ActionDelegate.h"
#import "NotificareAction.h"
#import "NotificareNotification.h"

NS_ASSUME_NONNULL_BEGIN

@interface NotificareTelephone : NSObject <ActionType>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareAction * action;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * _Nullable rootViewController;

-(void)executeAction;

@end
NS_ASSUME_NONNULL_END
