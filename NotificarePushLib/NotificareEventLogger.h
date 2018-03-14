//
//  NotificareEventLogger.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessEventBlock)(NSDictionary * response);
typedef void (^ErrorEventBlock)(NSError * response);

@interface NotificareEventLogger : NSObject

+(NotificareEventLogger*)shared;
-(void)launch;
-(void)logEvent:(NSString*)name withData:(NSDictionary * _Nullable)data completionHandler:(SuccessEventBlock)successBlock errorHandler:(ErrorEventBlock)errorBlock;

@end
NS_ASSUME_NONNULL_END
