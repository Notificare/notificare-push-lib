//
//  NotificarePass.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 06/04/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificarePass : NSObject

@property (strong, nonatomic) NSString * passbook;
@property (strong, nonatomic) NSString * serial;
@property (strong, nonatomic) NSString * redeem;
@property (strong, nonatomic) NSString * token;
@property (strong, nonatomic) NSDate * date;
@property (strong, nonatomic) NSDictionary * data;
@property (strong, nonatomic) NSNumber * limit;
@property (strong, nonatomic) NSArray * redeemHistory;
@property (assign, nonatomic) BOOL active;

@end
