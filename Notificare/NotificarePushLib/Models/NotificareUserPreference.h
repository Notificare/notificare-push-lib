//
//  NotificareUserPreference.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 10/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareUserPreference : NSObject

@property (strong, nonatomic) NSString * preferenceLabel;
@property (strong, nonatomic) NSString * preferenceId;
@property (strong, nonatomic) NSString * preferenceType;
@property (strong, nonatomic) NSArray * preferenceOptions;

@end
