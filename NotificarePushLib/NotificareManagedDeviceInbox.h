//
//  NotificareManagedDeviceInbox.h
//  app
//
//  Created by Aernout Peeters on 29-04-2016.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "NotificareDeviceInbox.h"

@interface NotificareManagedDeviceInbox : NSManagedObject

@property (strong, nonatomic, nonnull) NSString * inboxId;
@property (strong, nonatomic, nonnull) NSString * applicationId;
@property (strong, nonatomic, nonnull) NSString * deviceID;
@property (strong, nonatomic, nullable) NSString * type;
@property (strong, nonatomic, nullable) NSDictionary * data;
@property (strong, nonatomic, nonnull) NSString * message;
@property (strong, nonatomic, nullable) NSString * title;
@property (strong, nonatomic, nullable) NSString * subtitle;
@property (strong, nonatomic, nullable) NSDictionary * attachment;
@property (strong, nonatomic, nullable) NSDictionary * extra;
@property (strong, nonatomic, nonnull) NSString * notification;
@property (strong, nonatomic, nonnull) NSDate * time;
@property (strong, nonatomic, nullable) NSString * userID;
@property (strong, nonatomic, nullable) NSDate * expires;
@property (assign, nonatomic) BOOL opened;
@property (assign, nonatomic) BOOL visible;

+ (NotificareManagedDeviceInbox * _Nullable)ManagedDeviceInbox:(NotificareDeviceInbox * _Nonnull)nonManaged inContext:(NSManagedObjectContext * _Nonnull)managedObjectContext;
- (NotificareDeviceInbox * _Nullable)toNonManaged;

@end
