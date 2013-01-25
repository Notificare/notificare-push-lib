//
//  NotificareEngine.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
#import "MKNetworkKit.h"

typedef void (^NotificationResponseBlock)(NSDictionary*info);
typedef void (^BackgroundCallResponseBlock)(NSDictionary*response);


@interface NotificareEngine : MKNetworkEngine


@property (strong, nonatomic) NSString * apiID;
@property (strong, nonatomic) NSString * apiSecret;

-(MKNetworkOperation*)registerDevice:(NSString*)device;
-(MKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID;
-(MKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;


-(MKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device;
-(MKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID;
-(MKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;


-(MKNetworkOperation*)getNotification:(NSString*)notificationID completionHandler:(NotificationResponseBlock) info errorHandler:(MKNKErrorBlock) errorBlock;

-(MKNetworkOperation*)executeBackgroundCall:(NSString *)path withMethod:(NSString *)method isSSL:(BOOL)ssl completionHandler:(BackgroundCallResponseBlock)response errorHandler:(MKNKErrorBlock) error;


@end
