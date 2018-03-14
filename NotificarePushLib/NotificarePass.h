//
//  NotificarePass.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 06/04/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificarePass : NSObject

@property (strong, nonatomic, nonnull) NSString * passbook;
@property (strong, nonatomic, nonnull) NSString * serial;
@property (strong, nonatomic, nonnull) NSString * redeem;
@property (strong, nonatomic, nonnull) NSString * token;
@property (strong, nonatomic, nonnull) NSDate * date;
@property (strong, nonatomic, nonnull) NSDictionary * data;
@property (strong, nonatomic, nullable) NSNumber * limit;
@property (strong, nonatomic, nullable) NSArray * redeemHistory;
@property (assign, nonatomic) BOOL active;

- (void)setValuesWithPassJSON:(NSDictionary * _Nonnull)passJSON;

@end
