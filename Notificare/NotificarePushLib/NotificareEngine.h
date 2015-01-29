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


-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID completionHandler:(NotificationResponseBlock) info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username completionHandler:(NotificationResponseBlock) info errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID;
-(NotificareMKNetworkOperation*)registerDevice:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;


-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID;
-(NotificareMKNetworkOperation*)registerDeviceForWebsockets:(NSString*)device withUserID:(NSString*)userID withUsername:(NSString*)username;

-(NotificareMKNetworkOperation*)unregisterDevice:(NSString*)device;

-(NotificareMKNetworkOperation*)updateDeviceLocation:(NSString*)device;
-(NotificareMKNetworkOperation*)clearDeviceLocation:(NSString*)device;

-(NotificareMKNetworkOperation*)updateDeviceTimezone:(NSString*)device;

-(NotificareMKNetworkOperation*)updateDeviceLanguage:(NSString*)device;

-(NotificareMKNetworkOperation*)getNotification:(NSString*)notificationID completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)clearNotification:(NSString*)notificationID completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)getTags:(NSString *)deviceID completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;

-(NotificareMKNetworkOperation*)addTags:(NSArray *)tags forDevice:(NSString *)device completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)clearTags:(NSString *)deviceID completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) error;

-(NotificareMKNetworkOperation*)removeTag:(NSString *)tag forDevice:(NSString *)device completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)fetchUserPreferences:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)getNearestFencesForLatitude:(float)latitude andLongitude:(float)longitude completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)trigger:(NSString*)device forDevice:(NSString *)device andRegion:(NSString *)region;

-(NotificareMKNetworkOperation*)trigger:(NSString*)device forDevice:(NSString *)device andBeacon:(NSString *)beacon;

-(NotificareMKNetworkOperation*)trigger:(NSString *)type forDevice:(NSString *)device andRegion:(NSString *)region completionHandler:(NotificationResponseBlock)response errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)trigger:(NSString *)type forDevice:(NSString *)device andBeacon:(NSString *)beacon completionHandler:(NotificationResponseBlock)response errorHandler:(NotificareMKNKErrorBlock)errorBlock;

-(NotificareMKNetworkOperation*)eventLog:(NSDictionary *)params;
-(NotificareMKNetworkOperation*)eventLog:(NSDictionary *)params completionHandler:(NotificationResponseBlock)response errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)uploadFile:(NSData*)file completionHandler:(FileUploadResponseBlock)response errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)executeAction:(NSString *)path withParams:(NSDictionary *)params withMethod:(NSString *)method isSSL:(BOOL)ssl;

-(NotificareMKNetworkOperation*)actionLog:(NSDictionary *)data;
-(NotificareMKNetworkOperation*)actionLog:(NSDictionary *)data completionHandler:(NotificationResponseBlock)response errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)getBeacons:(NSString *)region completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;

-(NotificareMKNetworkOperation*)getApplicationInfo:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;

-(NotificareMKNetworkOperation*)createAccount:(NSDictionary *)params completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;
-(NotificareMKNetworkOperation*)resetPassword:(NSDictionary *)params withToken:(NSString *)token completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;
-(NotificareMKNetworkOperation*)validateAccount:(NSString *)token completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)errorBlock;
-(NotificareMKNetworkOperation*)sendPassword:(NSDictionary *)params completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;
-(NotificareMKNetworkOperation*)checkAccount:(NSString *)user completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock)error;

-(NotificareMKNetworkOperation*)getProducts:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)getProduct:(NSString *)productId completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;
-(NotificareMKNetworkOperation*)getProductByIdentifier:(NSString *)identifier completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;

-(NotificareMKNetworkOperation*)doPurchase:(NSString *)receipt withPrice:(NSString *)price withCurrency:(NSString *)currency forDevice:(NSString *)device completionHandler:(NotificationResponseBlock)info errorHandler:(NotificareMKNKErrorBlock) errorBlock;

@end
