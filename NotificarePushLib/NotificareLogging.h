//
//  NotificareLogging.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <os/log.h>
#import "NotificareDefinitions.h"

@interface NotificareLogging : NSObject

+(NotificareLogging*)shared;
-(void)launch;
-(void)nLog:(NSString *)log, ...;


@end
