//
//  NotificareSurrogate.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString * const NotificareDefaultDelegateNilException;

@interface NotificareAppDelegateSurrogate : NSObject <UIApplicationDelegate>

@property(nonatomic, strong) NSObject<UIApplicationDelegate> *surrogateDelegate;
@property(nonatomic, strong) NSObject<UIApplicationDelegate> *defaultAppDelegate;
@property(nonatomic, readonly, copy) NSDictionary *launchOptions;

+ (NotificareAppDelegateSurrogate *)shared;
- (void)clearLaunchOptions;

@end
