//
//  NotificareAppConfig.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareApplication.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessAppInfoBlock)(NotificareApplication * response);
typedef void (^ErrorAppInfoBlock)(NSError * response);

@interface NotificareAppConfig : NSObject

@property (nonatomic,strong) NSString * appKey;
@property (nonatomic,strong) NSString * appSecret;
@property (nonatomic,strong) NSDictionary * options;
@property (nonatomic,strong) NSString * sessionID;
@property (nonatomic,strong) NotificareApplication * application;

+(NotificareAppConfig*)shared;
-(void)launch;
-(void)fetchApplicationInfo:(SuccessAppInfoBlock)successBlock errorHandler:(ErrorAppInfoBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
