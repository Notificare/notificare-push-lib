//
//  NSString+Utils.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 4/29/13.
//  Copyright (c) 2013 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sys/utsname.h>

@interface NSString (Utils)

+(NSString*)machineName;

+(NSString*)randomID;
    
@end
