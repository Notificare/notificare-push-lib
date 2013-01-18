//
//  Notificare.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 12/11/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>
#import <MapKit/MapKit.h>

@interface Notificare : NSObject <UIAlertViewDelegate>

@property (strong, nonatomic) NSString * bundleName;
@property (strong, nonatomic) NSString * appStoreID;
@property (strong, nonatomic) UIViewController *rootViewController;
@property (strong, nonatomic) UIButton *button;
@property (strong, nonatomic) PKPassLibrary *passLib;

-(void)handleNotification:(NSDictionary*)notification;

@end
