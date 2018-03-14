//
//  NotificareHeading.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 07/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface NotificareHeading : NSObject

@property (strong, nonatomic, nonnull) NSNumber * magneticHeading;
@property (strong, nonatomic, nonnull) NSNumber * trueHeading;
@property (strong, nonatomic, nonnull) NSNumber * headingAccuracy;
@property (strong, nonatomic, nonnull) NSNumber * headingX;
@property (strong, nonatomic, nonnull) NSNumber * headingY;
@property (strong, nonatomic, nonnull) NSNumber * headingZ;


- (void)setValuesWithCLHeading:(CLHeading * _Nonnull)heading;

@end
