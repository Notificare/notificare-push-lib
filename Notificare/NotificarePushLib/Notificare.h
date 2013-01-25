//
//  Notificare.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 12/11/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>
#import <MapKit/MapKit.h>
#import "NotificationType.h"

@class Notificare;

@protocol NotificareDelegate

@optional

- (void)notificare:(Notificare *)library willOpenNotification:(NSDictionary *)info;
- (void)notificare:(Notificare *)library didOpenNotification:(NSDictionary *)info;
- (void)notificare:(Notificare *)library didCloseNotification:(NSDictionary *)info;
- (void)notificare:(Notificare *)library didFailToOpenNotification:(NSDictionary *)info;

@end


@interface Notificare : NSObject <NotificationDelegate>

@property (nonatomic, assign) id<NotificareDelegate> notificareDelegate;
@property (strong, nonatomic) NSDictionary * theNotification;
@property (strong, nonatomic) id <NotificationType> type;

-(void)handleNotification:(NSDictionary*)notification;

@end
