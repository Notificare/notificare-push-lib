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


@property (strong, nonatomic, nonnull) NSString * notificationID;
@property (strong, nonatomic, nonnull) NSDictionary * application;
@property (strong, nonatomic, nonnull) NSString * notificationType;
@property (strong, nonatomic, nonnull) NSString * notificationTime;
@property (strong, nonatomic, nonnull) NSString * notificationMessage;
@property (strong, nonatomic, nullable) NSString * notificationLatitude;
@property (strong, nonatomic, nullable) NSString * notificationLongitude;
@property (strong, nonatomic, nullable) NSString * notificationDistance;
@property (strong, nonatomic, nullable) NSArray * notificationContent;
@property (strong, nonatomic, nullable) NSArray * notificationActions;
@property (strong, nonatomic, nullable) NSArray * notificationAttachments;
@property (strong, nonatomic, nullable) NSArray * notificationTags;
@property (strong, nonatomic, nullable) NSArray * notificationSegments;
@property (strong, nonatomic, nullable) NSDictionary * notificationExtra;
@property (strong, nonatomic, nullable) NSDictionary * notificationInfo;
@property (strong, nonatomic, nonnull) NSNumber * displayMessage;


@end
