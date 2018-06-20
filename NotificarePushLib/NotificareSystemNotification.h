//
//  NotificareSystemNotification.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 21/03/2018.
//  Copyright © 2018 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareSystemNotification : NSObject

@property (strong, nonatomic, nullable) NSString * notificationID;
@property (strong, nonatomic, nonnull) NSString * type;
@property (strong, nonatomic, nullable) NSDictionary * extra;

- (void)setValuesWithSystemNotificationJSON:(NSDictionary * _Nonnull)systemNotificationJSON;

@end
