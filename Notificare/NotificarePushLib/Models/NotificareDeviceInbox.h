//
//  NotificareDeviceInbox.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/01/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareDeviceInbox : NSObject

@property (strong, nonatomic) NSString * inboxId;
@property (strong, nonatomic) NSString * applicationId;
@property (strong, nonatomic) NSString * deviceID;
@property (strong, nonatomic) NSDictionary * data;
@property (strong, nonatomic) NSString * message;
@property (strong, nonatomic) NSString * notification;
@property (strong, nonatomic) NSString * time;
@property (strong, nonatomic) NSString * userID;
@property (assign, nonatomic) BOOL opened;

@end
