//
//  Action.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/23/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareAction : NSObject


@property (strong, nonatomic, nonnull) NSString * actionType;
@property (strong, nonatomic, nonnull) NSString * actionLabel;
@property (strong, nonatomic, nullable) NSString * actionTarget;
@property (nonatomic, assign) BOOL actionKeyboard;
@property (nonatomic, assign) BOOL actionCamera;


@end
