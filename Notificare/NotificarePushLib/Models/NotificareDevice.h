//
//  NotificareDevice.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 28/01/15.
//  Copyright (c) 2015 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareDevice : NSObject

@property (strong, nonatomic, nonnull) NSString * deviceID;
@property (strong, nonatomic, nullable) NSString * userID;
@property (strong, nonatomic, nullable) NSString * username;
@property (strong, nonatomic, nonnull) NSNumber * timezone;
@property (strong, nonatomic, nonnull) NSString * osVersion;
@property (strong, nonatomic, nonnull) NSString * sdkVersion;
@property (strong, nonatomic, nonnull) NSString * appVersion;
@property (strong, nonatomic, nonnull) NSString * device;
@property (strong, nonatomic, nonnull) NSString * country;
@property (strong, nonatomic, nullable) NSDictionary * dnd;
@property (nonatomic) float latitude;
@property (nonatomic) float longitude;
@property (assign, nonatomic) BOOL canReceiveNotifications;
@property (assign, nonatomic) BOOL allowedLocationServices;

@end
