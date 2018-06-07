//
//  NotificareGeo.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import "NotificareRegion.h"
#import "NotificareBeacon.h"
#import "NotificareLocation.h"
#import "NotificareHeading.h"
#import "NotificareVisit.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessRegionsBlock)(NSArray<NotificareRegion *> *region);
typedef void (^SuccessBeaconsBlock)(NSArray<NotificareBeacon *> *beacon);
typedef void (^SuccessRegionBlock)(NotificareRegion * region);
typedef void (^SuccessBeaconBlock)(NotificareBeacon * beacon);
typedef void (^ErrorRegionBlock)(NSError * error);
typedef void (^ErrorBeaconBlock)(NSError * error);

typedef enum NotificareRegionState : NSInteger {
    NotificareRegionStateUnknown = 0,
    NotificareRegionStateInside = 1,
    NotificareRegionStateOutside = 2
} NotificareRegionState;

typedef enum NotificareGeoAuthorizationStatus : NSInteger {
    NotificareGeoAuthorizationStatusDenied = 0,
    NotificareGeoAuthorizationStatusRestricted = 1,
    NotificareGeoAuthorizationStatusNotDetermined = 2,
    NotificareGeoAuthorizationStatusAuthorizedAlways = 3,
    NotificareGeoAuthorizationStatusAuthorizedWhenInUse = 4
} NotificareGeoAuthorizationStatus;

@class NotificareGeo;

@protocol NotificareGeoDelegate <NSObject>

@optional

- (void)notificareGeo:(NotificareGeo *)notificareGeo didFailToStartLocationServiceWithError:(NSError *)error;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didReceiveLocationServiceAuthorizationStatus:(NotificareGeoAuthorizationStatus)status;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didUpdateLocations:(NSArray<NotificareLocation*> *)locations;
- (void)notificareGeo:(NotificareGeo *)notificareGeo monitoringDidFailForRegion:(id)region withError:(NSError *)error;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didStartMonitoringForRegion:(id)region;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didDetermineState:(NotificareRegionState)state forRegion:(id)region;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didEnterRegion:(id)region;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didExitRegion:(id)region;
- (void)notificareGeo:(NotificareGeo *)notificareGeo rangingBeaconsDidFailForRegion:(NotificareBeacon *)region withError:(NSError *)error;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didRangeBeacons:(NSArray<NotificareBeacon *> *)beacons inRegion:(NotificareBeacon *)region;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didUpdateHeading:(NotificareHeading *)heading;
- (void)notificareGeo:(NotificareGeo *)notificareGeo didVisit:(NotificareVisit *)visit;

@end


@interface NotificareGeo : NSObject <CLLocationManagerDelegate>

@property (nonatomic, assign) id<NotificareGeoDelegate> notificareGeoDelegate;
@property (nonatomic, strong) CLLocationManager * locationManager;

+(NotificareGeo*)shared;
-(void)launch;
-(void)startLocationUpdates;
-(void)stopLocationUpdates;
-(BOOL)locationServicesEnabled;

@end

NS_ASSUME_NONNULL_END
