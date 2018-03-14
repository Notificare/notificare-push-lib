//
//  Map.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/24/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "NotificareAction.h"
#import "NotificareContent.h"
#import "NotificareAttachment.h"
#import "NotificareNotification.h"
#import "NotificationType.h"
#import "NotificationDelegate.h"
#import "NotificareActions.h"
#import "NotificareMarker.h"

NS_ASSUME_NONNULL_BEGIN

@interface NotificareMap : UIViewController <NotificationType,MKMapViewDelegate>

@property (nonatomic, assign) id<NotificationDelegate> delegate;
@property (nonatomic, strong) NotificareNotification * notification;
@property (nonatomic, strong) NotificareActions * notificareActions;
@property (strong, nonatomic) MKMapView *mapView;
@property (strong, nonatomic) UIBarButtonItem *actionsButton;

-(id)handleNotification;

@end

NS_ASSUME_NONNULL_END
