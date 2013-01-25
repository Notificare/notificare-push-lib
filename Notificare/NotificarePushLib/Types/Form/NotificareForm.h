//
//  Form.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Notification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"

@interface NotificareForm : NSObject <NotificationType, MKMapViewDelegate,MKAnnotation>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) Notification * notification;


-(void)openNotification;

@end
