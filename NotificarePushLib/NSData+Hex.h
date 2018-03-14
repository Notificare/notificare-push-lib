//
//  NSData+Hex.h
//  NotificarePushLib
//
//  Created by Joel Oliveira | Mangrove on 11/27/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Hex)

/*!
    @abstract Creates a string of hexadecimal octets
 */
- (NSString *)hexadecimalString;

/*!
    @abstract Creates NSData from a hexadecimal NSString
 */
+ (NSData *)dataFromHexadecimalString:(NSString *)string;

@end
