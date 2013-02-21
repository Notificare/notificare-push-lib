//
//  NotificareBrowser.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 2/3/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ActionType.h"
#import "ActionDelegate.h"
#import "Action.h"
#import "Notification.h"

@interface NotificareBrowser : NSObject <ActionType>

@property (nonatomic, assign) id<ActionDelegate> delegate;
@property (strong, nonatomic) Action * action;
@property (strong, nonatomic) Notification * notification;

-(void)executeAction;

@end
