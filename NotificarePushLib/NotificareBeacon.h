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

@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSString * beaconId;
@property (strong, nonatomic, nonnull) NSString * beaconName;
@property (strong, nonatomic, nonnull) NSString * beaconRegion;
@property (strong, nonatomic, nonnull) NSUUID * beaconUUID;
@property (strong, nonatomic, nonnull) NSNumber * beaconMajor;
@property (strong, nonatomic, nullable) NSNumber * beaconMinor;
@property (strong, nonatomic, nullable) CLBeacon * beacon;
@property (assign, nonatomic) BOOL beaconTriggers;

- (void)setValuesWithBeaconJSON:(NSDictionary * _Nonnull)beaconJSON;

@end
