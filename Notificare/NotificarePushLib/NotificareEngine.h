//
//  NotificareEngine.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
#import "NotificareMKNetworkKit.h"
#import "NotificareMKNetworkEngine.h"

typedef void (^NotificationResponseBlock)(NSDictionary*info);
typedef void (^FileUploadResponseBlock)(NSDictionary*file);

@interface NotificareEngine : NotificareMKNetworkEngine


@property (strong, nonatomic) NSString * apiID;
@property (strong, nonatomic) NSString * apiSecret;
@property (strong, nonatomic) NSString * deviceLatitude;
@property (strong, nonatomic) NSString * deviceLongitude;
@property (strong, nonatomic) NSString * device;



-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;


-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;

-(NotificareMKNetworkOperation*)updateDeviceLocation:(NSString*)device;

-(NotificareMKNetworkOperation*)getNotification:(NSString*)notificationID completionHandler:(NotificationResponseBlock) info errorHandler:(nMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)eventLog:(NSDictionary *)params;

-(NotificareMKNetworkOperation*)uploadFile:(NSData*)file completionHandler:(FileUploadResponseBlock)response errorHandler:(nMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)executeAction:(NSString *)path withParams:(NSDictionary *)params withMethod:(NSString *)method isSSL:(BOOL)ssl;

-(NotificareMKNetworkOperation*)actionLog:(NSDictionary *)data;


@end
