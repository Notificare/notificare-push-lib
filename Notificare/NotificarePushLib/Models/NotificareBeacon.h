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


@property (strong, nonatomic) NSString * name;
@property (strong, nonatomic) NSString * region;
@property (strong, nonatomic) NSUUID * beaconUUID;
@property (strong, nonatomic) NSString * major;
@property (strong, nonatomic) NSString * minor;
@property (strong, nonatomic) NSString * proximity;
@property (strong, nonatomic) NSDictionary * proximityNotifications;
@property (strong, nonatomic) NSString * application;
@property (strong, nonatomic) NSDictionary * notification;
@property (strong, nonatomic) NSString * latitude;
@property (strong, nonatomic) NSString * longitude;
@property (strong, nonatomic) NSString * batteryLevel;
@property (strong, nonatomic) NSString * purpose;
@property (strong, nonatomic) CLBeacon * beacon;
@property (strong, nonatomic) NSString * timezone;
@property (assign, nonatomic) BOOL triggers;

@end
