//
//  NotificareDeviceManager.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareDevice.h"
#import "NotificareUserData.h"
#import "NotificareDeviceDnD.h"
#import "NotificareLocation.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessDeviceBlock)(NotificareDevice * response);
typedef void (^SuccessTagsBlock)(NSArray<NSString *> * response);
typedef void (^SuccessTagBlock)(NSDictionary * response);
typedef void (^SuccessUserDataFieldsBlock)(NSArray<NotificareUserData *> * response);
typedef void (^SuccessDeviceDnDBlock)(NotificareDeviceDnD * response);
typedef void (^ErrorDeviceBlock)(NSError * response);
typedef void (^ErrorTagBlock)(NSError * response);
typedef void (^ErrorUserDataBlock)(NSError * response);
typedef void (^ErrorDeviceDnDBlock)(NSError * response);

@class NotificareDeviceManager;

@protocol NotificareDeviceManagerDelegate

@optional


- (void)notificareDeviceManager:(NotificareDeviceManager *)notificareDeviceManager didRegisterDevice:(NotificareDevice *)device;

@end

@interface NotificareDeviceManager : NSObject

@property (nonatomic, assign) id<NotificareDeviceManagerDelegate> notificareDeviceManagerDelegate;
@property (nonatomic,strong) NotificareDevice * device;

+(NotificareDeviceManager*)shared;
-(void)launch;

-(void)registerTemporaryDevice:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;

-(void)registerDevice:(NSData *)deviceToken asTemp:(BOOL)temp completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)registerDevice:(NSData *)deviceToken asTemp:(BOOL)temp withUserID:(NSString*)userID completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)registerDevice:(NSData *)deviceToken asTemp:(BOOL)temp withUserID:(NSString*)userID andUserName:(NSString*)userName completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;

-(void)updateDeviceNotificationSettings:(BOOL)allowedUI completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)updateDeviceLocation:(NotificareLocation*)location completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)clearDeviceLocation:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)updateDeviceTimezone:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)updateDeviceLanguage:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)updateDeviceBackgroundAppRefresh:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;
-(void)updateDeviceBluetoothState:(BOOL)state completionHandler:(SuccessDeviceBlock)successBlock errorHandler:(ErrorDeviceBlock)errorBlock;

-(void)fetchTags:(SuccessTagsBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;
-(void)addTags:(NSArray *)tags completionHandler:(SuccessTagBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;
-(void)addTag:(NSString *)tag completionHandler:(SuccessTagBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;
-(void)removeTags:(NSArray *)tags completionHandler:(SuccessTagBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;
-(void)removeTag:(NSString *)tag completionHandler:(SuccessTagBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;
-(void)clearTags:(SuccessTagBlock)successBlock errorHandler:(ErrorTagBlock)errorBlock;

-(void)fetchUserData:(SuccessUserDataFieldsBlock)successBlock errorHandler:(ErrorUserDataBlock)errorBlock;
-(void)updateUserData:(NSArray<NotificareUserData *> *)fields completionHandler:(SuccessUserDataFieldsBlock)successBlock errorHandler:(ErrorUserDataBlock)errorBlock;

-(void)fetchDoNotDisturb:(SuccessDeviceDnDBlock)successBlock errorHandler:(ErrorDeviceDnDBlock)errorBlock;
-(void)updateDoNotDisturb:(NotificareDeviceDnD *)dnd completionHandler:(SuccessDeviceDnDBlock)successBlock errorHandler:(ErrorDeviceDnDBlock)errorBlock;
-(void)clearDoNotDisturb:(SuccessDeviceDnDBlock)successBlock errorHandler:(ErrorDeviceDnDBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
