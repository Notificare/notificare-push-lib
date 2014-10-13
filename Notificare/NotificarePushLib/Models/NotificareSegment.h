//
//  NotificareSegment.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 10/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareSegment : NSObject

@property (strong, nonatomic) NSString * segmentLabel;
@property (strong, nonatomic) NSString * segmentId;
@property (assign, nonatomic) BOOL selected;

@end
