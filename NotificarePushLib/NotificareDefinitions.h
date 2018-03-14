//
//  NotificareDefinitions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef NotificareDefinitions_h
#define NotificareDefinitions_h

#define kSDKVersion @"2.0.0"
#define kOSVersion [[UIDevice currentDevice] systemVersion]
#define kDaysInterval 1
#define kLocationSessionBackoffDistance 7.0
#define kAuthProtocol @"https"
#define kUseSSL YES
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:(v) options:NSNumericSearch] != NSOrderedAscending)
#define ATTACHMENT_KEY @"attachment"
#define IS_IPAD ( UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad )

#endif /* NotificareDefinitions_h */
