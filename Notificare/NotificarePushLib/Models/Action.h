//
//  Action.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 1/23/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Action : NSObject


@property (strong, nonatomic) NSString * actionType;
@property (strong, nonatomic) NSString * actionLabel;
@property (strong, nonatomic) NSString * actionTarget;
@property (nonatomic, assign) BOOL actionKeyboard;
@property (nonatomic, assign) BOOL actionCamera;


@end
