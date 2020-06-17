//
//  NotificareDeviceInbox.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/01/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareDeviceInbox : NSObject

@property (strong, nonatomic, nonnull) NSString * inboxId;
@property (strong, nonatomic, nonnull) NSString * applicationId;
@property (strong, nonatomic, nonnull) NSString * deviceID;
@property (strong, nonatomic, nullable) NSString * type;
@property (strong, nonatomic, nullable) NSDictionary * data;
@property (strong, nonatomic, nullable) NSString * title;
@property (strong, nonatomic, nullable) NSString * subtitle;
@property (strong, nonatomic, nullable) NSDictionary * attachment;
@property (strong, nonatomic, nullable) NSDictionary * extra;
@property (strong, nonatomic, nonnull) NSString * message;
@property (strong, nonatomic, nonnull) NSString * notification;
@property (strong, nonatomic, nonnull) NSString * time;
@property (strong, nonatomic, nullable) NSString * userID;
@property (strong, nonatomic, nullable) NSString * expires;
@property (assign, nonatomic) BOOL opened;
@property (assign, nonatomic) BOOL visible;

- (void)setValuesWithDeviceInboxJSON:(NSDictionary * _Nonnull)deviceInboxJSON;

@end
