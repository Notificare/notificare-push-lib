//
//  NotificareBeacon.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 12/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface NotificareBeacon : NSObject


@property (strong, nonatomic, nonnull) NSString * name;
@property (strong, nonatomic, nonnull) NSString * region;
@property (strong, nonatomic, nonnull) NSUUID * beaconUUID;
@property (strong, nonatomic, nonnull) NSString * major;
@property (strong, nonatomic, nonnull) NSString * minor;
@property (strong, nonatomic, nonnull) NSString * proximity;
@property (strong, nonatomic, nullable) NSDictionary * proximityNotifications;
@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSDictionary * notification;
@property (strong, nonatomic, nonnull) NSString * latitude;
@property (strong, nonatomic, nonnull) NSString * longitude;
@property (strong, nonatomic, nullable) NSString * batteryLevel;
@property (strong, nonatomic, nonnull) NSString * purpose;
@property (strong, nonatomic, nullable) CLBeacon * beacon;
@property (strong, nonatomic, nonnull) NSString * timezone;
@property (assign, nonatomic) BOOL triggers;

@end
