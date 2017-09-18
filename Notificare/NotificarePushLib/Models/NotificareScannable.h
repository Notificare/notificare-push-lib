//
//  NotificareScannable.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 29/08/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareScannable : NSObject
@property (strong, nonatomic, nonnull) NSString * scannableId;
@property (strong, nonatomic, nonnull) NSString * name;
@property (strong, nonatomic, nonnull) NSString * tag;
@property (strong, nonatomic, nonnull) NSString * type;
@property (strong, nonatomic, nonnull) NSDictionary * data;

- (void)setValuesWithScannableJSON:(NSDictionary * _Nonnull)scannableJSON;
@end
