//
//  NotificareRegion.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 03/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface NotificareRegion : NSObject

@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSString * regionId;
@property (strong, nonatomic, nonnull) NSString * regionName;
@property (strong, nonatomic, nullable) NSString * regionDescription;
@property (strong, nonatomic, nullable) NSString * regionReferenceKey;
@property (strong, nonatomic, nullable) NSNumber * regionMajor;
@property (strong, nonatomic, nullable) NSString * regionAddress;
@property (strong, nonatomic, nullable) NSString * regionIcon;
@property (strong, nonatomic, nullable) NSString * regionCategory;
@property (strong, nonatomic, nonnull) NSString * regionCountry;
@property (strong, nonatomic, nullable) NSArray * regionTags;
@property (strong, nonatomic, nonnull) NSDictionary * regionGeometry;
@property (strong, nonatomic, nullable) NSDictionary * regionAdvancedGeometry;
@property (strong, nonatomic, nonnull) NSNumber * regionDistance;
@property (strong, nonatomic, nonnull) NSString * regionTimezone;
@property (strong, nonatomic, nonnull) NSString * regionTimeZoneOffset;
@property (strong, nonatomic, nullable) NSDictionary * regionWeather;

- (void)setValuesWithRegionJSON:(NSDictionary * _Nonnull)regionJSON;

@end
