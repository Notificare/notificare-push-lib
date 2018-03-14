//
//  NotificareScannables.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 08/11/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareScannable.h"
#import "NotificareQRCodeScanner.h"

NS_ASSUME_NONNULL_BEGIN

@class NotificareScannables;

@protocol NotificareScannablesDelegate <NSObject>

@optional

- (void)notificareScannables:(NotificareScannables *)notificareScannables didStartQRCodeScanner:(UIViewController*)scanner;
- (void)notificareScannables:(NotificareScannables *)notificareScannables didInvalidateScannableSessionWithError:(NSError *)error;
- (void)notificareScannables:(NotificareScannables *)notificareScannables didDetectScannable:(NotificareScannable *)scannable;

@end


@interface NotificareScannables : NSObject <NotificareQRCodeScannerDelegate>

@property (nonatomic, assign) id<NotificareScannablesDelegate> notificareScannablesDelegate;


+(NotificareScannables*)shared;
-(void)launch;
-(void)startScannableSessionWithQRCode:(UINavigationController*)navigationController asModal:(BOOL)asModal;
-(void)fetchScannable:(NSString *)message;
- (nullable NSString *)parseURIPayload:(NSData*)data;

@end

NS_ASSUME_NONNULL_END
