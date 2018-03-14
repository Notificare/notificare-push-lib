//
//  NotificareStorage.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareAsset.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessAssetsBlock)(NSArray<NotificareAsset *> * response);
typedef void (^SuccessAssetBlock)(NotificareAsset * asset);
typedef void (^ErrorAssetBlock)(NSError * error);

@interface NotificareStorage : NSObject

+(NotificareStorage*)shared;
-(void)launch;
-(void)fetchAssets:(NSString*)group completionHandler:(SuccessAssetsBlock)successBlock errorHandler:(ErrorAssetBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
