//
//  NotificareUserData.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 21/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareUserData : NSObject

@property (strong, nonatomic, nonnull) NSString * key;
@property (strong, nonatomic, nonnull) NSString * label;
@property (strong, nonatomic, nonnull) NSString * type;
@property (strong, nonatomic, nonnull) NSString * value;

- (void)setValuesWithUserDataJSON:(NSDictionary * _Nonnull)userDataJSON;

@end
