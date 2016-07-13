//
//  NotificareUserPreference.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 10/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareUserPreference : NSObject

@property (strong, nonatomic, nonnull) NSString * preferenceLabel;
@property (strong, nonatomic, nonnull) NSString * preferenceId;
@property (strong, nonatomic, nonnull) NSString * preferenceType;
@property (strong, nonatomic, nonnull) NSArray * preferenceOptions;

@end
