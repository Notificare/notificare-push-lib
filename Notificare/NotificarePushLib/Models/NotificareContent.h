//
//  Content.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/23/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareContent : NSObject

@property (strong, nonatomic, nonnull) NSString * type;
@property (strong, nonatomic, nonnull) NSString * data;
@property (strong, nonatomic, nonnull) NSDictionary * dataDictionary;

@end
