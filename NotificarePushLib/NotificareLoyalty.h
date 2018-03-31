//
//  NotificareLoyalty.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 31/03/2018.
//  Copyright © 2018 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificarePass.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessPassesBlock)(NSArray<NotificarePass *> * response);
typedef void (^SuccessPassBlock)(NotificarePass * pass);
typedef void (^ErrorPassBlock)(NSError * error);

@interface NotificareLoyalty : NSObject

+(NotificareLoyalty*)shared;
-(void)launch;
-(void)fetchPassBySerial:(NSString*)serial completionHandler:(SuccessPassBlock)successBlock errorHandler:(ErrorPassBlock)errorBlock;
-(void)fetchPassByBarcode:(NSString*)barcode completionHandler:(SuccessPassBlock)successBlock errorHandler:(ErrorPassBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
