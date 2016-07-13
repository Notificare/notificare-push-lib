//
//  NotificareProduct.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface NotificareProduct : NSObject


@property (strong, nonatomic, nonnull) NSString * productName;
@property (strong, nonatomic, nonnull) NSString * productDescription;
@property (strong, nonatomic, nonnull) NSString * type;
@property (strong, nonatomic, nonnull) SKProduct * product;
@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSString * identifier;
@property (strong, nonatomic, nonnull) NSArray * stores;
@property (strong, nonatomic, nonnull) NSArray * downloads;
@property (strong, nonatomic, nonnull) NSString * date;
@property (strong, nonatomic, nonnull) NSString * priceLocale;
@property (strong, nonatomic, nonnull) NSString * price;
@property (strong, nonatomic, nonnull) NSString * currency;
@property (assign, nonatomic) BOOL active;
@property (assign, nonatomic) BOOL purchased;

@end
