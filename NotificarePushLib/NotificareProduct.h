//
//  NotificareProduct.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "SKProduct+priceAsString.h"

@interface NotificareProduct : NSObject


@property (strong, nonatomic, nonnull) NSString * productName;
@property (strong, nonatomic, nonnull) NSString * productDescription;
@property (strong, nonatomic, nonnull) NSString * productType;
@property (strong, nonatomic, nonnull) SKProduct * product;
@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSString * productIdentifier;
@property (strong, nonatomic, nonnull) NSArray * productStores;
@property (strong, nonatomic, nonnull) NSArray * productDownloads;
@property (strong, nonatomic, nonnull) NSString * productDate;
@property (strong, nonatomic, nonnull) NSString * productPriceLocale;
@property (strong, nonatomic, nonnull) NSString * productPrice;
@property (strong, nonatomic, nonnull) NSString * productCurrency;
@property (assign, nonatomic) BOOL active;
@property (assign, nonatomic) BOOL purchased;

- (void)setValuesWithProductJSON:(NSDictionary * _Nonnull)productJSON;
- (void)setValuesWithSKProduct:(SKProduct * _Nonnull)skProduct;

@end
