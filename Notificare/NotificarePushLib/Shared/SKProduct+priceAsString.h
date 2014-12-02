//
//  SKProduct+_priceAsString.h
//  Notificare
//
//  Created by Joel Oliveira on 12/1/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface SKProduct (priceAsString)

@property (nonatomic, readonly) NSString *priceAsString;
@property (nonatomic, readonly) NSString *currencyAsString;

@end
