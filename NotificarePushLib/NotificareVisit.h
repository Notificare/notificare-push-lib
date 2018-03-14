//
//  NotificareVisit.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 07/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface NotificareVisit : NSObject

@property (strong, nonatomic, nonnull) NSNumber * latitude;
@property (strong, nonatomic, nonnull) NSNumber * longitude;
@property (strong, nonatomic, nonnull) NSDate * departureDate;
@property (strong, nonatomic, nonnull) NSDate * arrivalDate;

- (void)setValuesWithCLVisit:(CLVisit * _Nonnull)visit;

@end
