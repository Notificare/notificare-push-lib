//
//  NotificareDeviceDnD.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 22/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareDeviceDnD : NSObject

@property (strong, nonatomic, nonnull) NSDate * start;
@property (strong, nonatomic, nonnull) NSDate * end;

- (void)setValuesWithDeviceDnDJSON:(NSDictionary * _Nonnull)deviceDnDJSON;

@end
