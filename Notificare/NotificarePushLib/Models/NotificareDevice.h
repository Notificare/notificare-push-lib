//
//  NotificareDevice.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 28/01/15.
//  Copyright (c) 2015 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareDevice : NSObject

@property (strong, nonatomic) NSString * deviceID;
@property (strong, nonatomic) NSString * userID;
@property (strong, nonatomic) NSString * username;
@property (strong, nonatomic) NSNumber * timezone;
@property (strong, nonatomic) NSString * osVersion;
@property (strong, nonatomic) NSString * sdkVersion;
@property (strong, nonatomic) NSString * appVersion;
@property (strong, nonatomic) NSString * device;
@property (strong, nonatomic) NSString * country;
@property (nonatomic) float latitude;
@property (nonatomic) float longitude;
@property (assign, nonatomic) BOOL canReceiveNotifications;
@property (assign, nonatomic) BOOL allowedLocationServices;

@end
