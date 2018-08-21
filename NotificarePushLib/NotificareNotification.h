//
//  Notification.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/23/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificareAttachment.h"

@interface NotificareNotification : NSObject <NSCoding>


@property (strong, nonatomic, nullable) NSString * notificationID;
@property (strong, nonatomic, nonnull) NSDictionary * application;
@property (strong, nonatomic, nonnull) NSString * notificationType;
@property (strong, nonatomic, nonnull) NSString * notificationTime;
@property (strong, nonatomic, nullable) NSString * notificationTitle;
@property (strong, nonatomic, nullable) NSString * notificationSubtitle;
@property (strong, nonatomic, nonnull) NSString * notificationMessage;
@property (strong, nonatomic, nullable) NSArray<NotificareContent*> * notificationContent;
@property (strong, nonatomic, nullable) NSArray<NotificareAction*> * notificationActions;
@property (strong, nonatomic, nullable) NSArray<NotificareAttachment*> * notificationAttachments;
@property (strong, nonatomic, nullable) NSDictionary * notificationExtra;
@property (strong, nonatomic, nullable) NSDictionary * notificationInfo;

- (void)setValuesWithNotificationJSON:(NSDictionary * _Nonnull)notificationJSON;

@end
