//
//  Notification.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/23/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface NotificareNotification : NSObject <NSCoding>


@property (strong, nonatomic) NSString * notificationID;
@property (strong, nonatomic) NSDictionary * application;
@property (strong, nonatomic) NSString * notificationType;
@property (strong, nonatomic) NSString * notificationTime;
@property (strong, nonatomic) NSString * notificationMessage;
@property (strong, nonatomic) NSString * notificationLatitude;
@property (strong, nonatomic) NSString * notificationLongitude;
@property (strong, nonatomic) NSString * notificationDistance;
@property (strong, nonatomic) NSArray * notificationContent;
@property (strong, nonatomic) NSArray * notificationActions;
@property (strong, nonatomic) NSArray * notificationAttachments;
@property (strong, nonatomic) NSArray * notificationTags;
@property (strong, nonatomic) NSArray * notificationSegments;
@property (strong, nonatomic) NSDictionary * notificationExtra;
@property (strong, nonatomic) NSDictionary * notificationInfo;
@property (strong, nonatomic) NSNumber * displayMessage;


@end
