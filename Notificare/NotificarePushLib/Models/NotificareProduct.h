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


@property (strong, nonatomic) NSString * productName;
@property (strong, nonatomic) NSString * productDescription;
@property (strong, nonatomic) NSString * type;
@property (strong, nonatomic) SKProduct * product;
@property (strong, nonatomic) NSString * application;
@property (strong, nonatomic) NSString * identifier;
@property (strong, nonatomic) NSArray * stores;
@property (strong, nonatomic) NSArray * downloads;
@property (strong, nonatomic) NSString * date;
@property (strong, nonatomic) NSString * priceLocale;
@property (strong, nonatomic) NSString * price;
@property (strong, nonatomic) NSString * currency;
@property (assign, nonatomic) BOOL active;
@property (assign, nonatomic) BOOL purchased;

@end
