//
//  NotificareApplication.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 03/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareApplication : NSObject

@property (strong, nonatomic, nonnull) NSString * application;
@property (strong, nonatomic, nonnull) NSString * name;
@property (strong, nonatomic, nonnull) NSArray * actionCategories;
@property (strong, nonatomic, nullable) NSString * appStoreId;
@property (strong, nonatomic, nonnull) NSString * category;
@property (strong, nonatomic, nonnull) NSDictionary * inboxConfig;
@property (strong, nonatomic, nullable) NSDictionary * passbookConfig;
@property (strong, nonatomic, nullable) NSDictionary * regionConfig;
@property (strong, nonatomic, nonnull) NSDictionary * services;
@property (strong, nonatomic, nullable) NSDictionary * websitePushConfig;
@property (strong, nonatomic, nonnull) NSArray * userDataFields;

- (void)setValuesWithApplicationJSON:(NSDictionary * _Nonnull)appJSON;

@end
