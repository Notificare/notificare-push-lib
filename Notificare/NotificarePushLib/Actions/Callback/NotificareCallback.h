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

@interface NotificareCallback : NSObject <ActionType,UIImagePickerControllerDelegate,UINavigationControllerDelegate,UITabBarDelegate>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) NotificareEngine * notificareEngine;
@property (strong, nonatomic) Action * action;
@property (strong, nonatomic) UIViewController * rootViewController;
@property (strong, nonatomic) UIImagePickerController *imagePicker;
@property (strong, nonatomic) UIToolbar * toolBar;
@property (strong, nonatomic) UIBarButtonItem * uploadButton;
@property (strong, nonatomic) UIBarButtonItem * closeButton;
@property (strong, nonatomic) NSString * message;
@property (strong, nonatomic) NSData * media;
@property (strong, nonatomic) UIProgressView * progressBar;


-(void)executeAction;

@end
