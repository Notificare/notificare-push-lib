//
//  NotificareCallback.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import "ActionType.h"
#import "ActionDelegate.h"
#import "NotificareEngine.h"
#import "Action.h"
#import "Notification.h"

@interface NotificareCallback : NSObject <ActionType,UIImagePickerControllerDelegate,UINavigationControllerDelegate,UITabBarDelegate,UITextViewDelegate,UITextFieldDelegate>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) Action * action;
@property (strong, nonatomic) Notification * notification;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIImagePickerController *imagePicker;
@property (strong, nonatomic) UIToolbar * toolBar;
@property (strong, nonatomic) UIBarButtonItem * sendButton;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) NSString * message;
@property (strong, nonatomic) NSData * media;
@property (strong, nonatomic) UIActivityIndicatorView * activityIndicator;
@property (strong, nonatomic) UITextView * messageView;
@property (strong, nonatomic) UITextField * messageField;
@property (nonatomic, assign) BOOL withMessage;
@property (strong, nonatomic) UINavigationController *navController;
@property (strong, nonatomic) UIViewController *controller;


-(void)executeAction;

@end
