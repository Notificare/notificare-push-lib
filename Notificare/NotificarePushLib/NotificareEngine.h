//
//  NotificareEngine.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
#import "MKNetworkKit.h"

typedef void (^NotificationResponseBlock)(NSDictionary*info);


@interface NotificareEngine : MKNetworkEngine


@property (strong, nonatomic) NSString * apiID;
@property (strong, nonatomic) NSString * apiSecret;

-(MKNetworkOperation*)registerDevice:(NSString*)device;
-(MKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID;
-(MKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;

-(MKNetworkOperation*)getNotification:(NSString*)notificationID completionHandler:(NotificationResponseBlock) info errorHandler:(MKNKErrorBlock) errorBlock;;
//-(MKNetworkOperation*)archiveNotification:(NSDictionary*)notification;
//-(MKNetworkOperation*)removeNotification:(NSDictionary*)notification;


@end
