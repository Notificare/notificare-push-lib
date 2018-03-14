//
//  NotificareLocation.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 06/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface NotificareLocation : NSObject

@property (strong, nonatomic, nonnull) NSNumber * latitude;
@property (strong, nonatomic, nonnull) NSNumber * longitude;
@property (strong, nonatomic, nonnull) NSNumber * altitude;
@property (strong, nonatomic, nonnull) NSNumber * horizontalAccuracy;
@property (strong, nonatomic, nonnull) NSNumber * verticalAccuracy;
@property (strong, nonatomic, nonnull) NSNumber * floor;
@property (strong, nonatomic, nonnull) NSNumber * speed;
@property (strong, nonatomic, nonnull) NSNumber * course;
@property (strong, nonatomic, nonnull) NSDate * timestamp;


- (void)setValuesWithCLLocation:(CLLocation * _Nonnull)location;

@end
