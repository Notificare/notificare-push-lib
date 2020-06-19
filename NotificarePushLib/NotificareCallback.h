//
//  NotificareCallback.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreServices/CoreServices.h>
#import <CoreMedia/CoreMedia.h>
#import "ActionType.h"
#import "ActionDelegate.h"
#import "NotificareAction.h"
#import "NotificareNotification.h"

@interface NotificareCallback : NSObject <ActionType,UIImagePickerControllerDelegate,UINavigationControllerDelegate,UITabBarDelegate,UITextViewDelegate,UITextFieldDelegate>

@property (nonatomic, strong) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareAction * action;
@property (strong, nonatomic) NotificareNotification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;

-(void)executeAction;

@end
