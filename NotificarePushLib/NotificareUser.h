//
//  NotificareUser.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 10/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareUser : NSObject

@property (strong, nonatomic, nonnull) NSString * accessToken;
@property (strong, nonatomic, nonnull) NSString * account;
@property (nonatomic, assign) BOOL active;
@property (strong, nonatomic, nonnull) NSString * application;
@property (nonatomic, assign) BOOL autoGenerated;
@property (strong, nonatomic, nullable) NSMutableArray * segments;
@property (strong, nonatomic, nullable) NSString * userID;
@property (strong, nonatomic, nullable) NSString * userName;
@property (strong, nonatomic, nullable) NSDictionary * userData;
@property (nonatomic, assign) BOOL validated;

- (void)setValuesWithUserJSON:(NSDictionary * _Nonnull)userJSON;

@end
