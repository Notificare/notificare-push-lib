//
//  NotificareAsset.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 20/03/16.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NotificareAsset : NSObject

@property (strong, nonatomic, nonnull) NSString * assetTitle;
@property (strong, nonatomic, nullable) NSString * assetDescription;
@property (strong, nonatomic, nullable) NSString * assetUrl;
@property (strong, nonatomic, nullable) NSDictionary * assetButton;
@property (strong, nonatomic, nullable) NSDictionary * assetMetaData;

@end
