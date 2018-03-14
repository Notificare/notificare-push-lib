//
//  NotificareQRCodeScanner.h
//  app
//
//  Created by Joel on 08-11-2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

@class NotificareQRCodeScanner;

@protocol NotificareQRCodeScannerDelegate <NSObject>

@optional

- (void)notificareQRCodeScanner:(NotificareQRCodeScanner *)notificareQRCodeScanner didScanQRCode:(NSString*)payload;

@end

@interface NotificareQRCodeScanner : UIViewController <AVCaptureMetadataOutputObjectsDelegate>

@property (nonatomic, assign) id<NotificareQRCodeScannerDelegate> notificareQRCodeScannerDelegate;


@end

NS_ASSUME_NONNULL_END
