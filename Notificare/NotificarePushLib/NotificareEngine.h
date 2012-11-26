//
//  NotificareEngine.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//
#import "MKNetworkKit.h"

@interface NotificareEngine : MKNetworkEngine{
    
}

@property (strong, nonatomic) NSString * apiID;
@property (strong, nonatomic) NSString * apiSecret;

-(MKNetworkOperation*)registerDevice:(NSString*)device withAlias:(NSString*)alias;


@end
