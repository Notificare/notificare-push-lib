//
//  NotificareAsset.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/03/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareAsset : NSObject

@property (strong, nonatomic) NSString * assetTitle;
@property (strong, nonatomic) NSString * assetDescription;
@property (strong, nonatomic) NSString * assetUrl;
@property (strong, nonatomic) NSDictionary * assetButton;
@property (strong, nonatomic) NSDictionary * assetMetaData;

@end
