//
//  NotificareCrashReport.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#include <execinfo.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessCrashBlock)(NSDictionary * response);
typedef void (^ErrorCrashBlock)(NSError * response);

@interface NotificareCrashReport : NSObject

+(NotificareCrashReport*)shared;
-(void)launch;
-(void)logCrashReport:(SuccessCrashBlock)successBlock errorHandler:(ErrorCrashBlock)errorBlock;

@end
NS_ASSUME_NONNULL_END
