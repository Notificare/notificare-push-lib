//
//  NotificareMonetize.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "NotificareProduct.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessProductsBlock)(NSArray<NotificareProduct *> * products);
typedef void (^SuccessProductBlock)(NotificareProduct * product);
typedef void (^ErrorProductBlock)(NSError * error);

@class NotificareMonetize;

@protocol NotificareMonetizeDelegate

@optional

- (void)notificareMonetize:(NotificareMonetize *)monetize didLoadStore:(NSArray <NotificareProduct *> *)products;
- (void)notificareMonetize:(NotificareMonetize *)monetize didFailToLoadStore:(NSError *)error;
- (void)notificareMonetize:(NotificareMonetize *)monetize didCompleteProductTransaction:(SKPaymentTransaction *)transaction;
- (void)notificareMonetize:(NotificareMonetize *)monetize didRestoreProductTransaction:(SKPaymentTransaction *)transaction;
- (void)notificareMonetize:(NotificareMonetize *)monetize didFailProductTransaction:(SKPaymentTransaction *)transaction withError:(NSError *)error;
- (void)notificareMonetize:(NotificareMonetize *)monetize didStartDownloadContent:(SKPaymentTransaction *)transaction;
- (void)notificareMonetize:(NotificareMonetize *)monetize didPauseDownloadContent:(SKDownload *)download;
- (void)notificareMonetize:(NotificareMonetize *)monetize didCancelDownloadContent:(SKDownload *)download;
- (void)notificareMonetize:(NotificareMonetize *)monetize didReceiveProgressDownloadContent:(SKDownload *)download;
- (void)notificareMonetize:(NotificareMonetize *)monetize didFailDownloadContent:(SKDownload *)download;
- (void)notificareMonetize:(NotificareMonetize *)monetize didFinishDownloadContent:(SKDownload *)download;



@end


@interface NotificareMonetize : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver>

@property (nonatomic, assign) id<NotificareMonetizeDelegate> notificareMonetizeDelegate;
@property (strong, nonatomic) NSMutableSet * productIdentifiers;
@property (strong, nonatomic) NSMutableArray * products;
@property (strong, nonatomic) NSMutableArray * pendingTransactions;
@property (strong, nonatomic) NSMutableSet * purchasedProducts;
@property (strong, nonatomic) SKProductsRequest * storeRequest;

+(NotificareMonetize*)shared;
- (void)launch;
- (void)reloadProducts;
- (void)fetchProducts:(SuccessProductsBlock)info errorHandler:(ErrorProductBlock)error;
- (void)fetchPurchasedProducts:(SuccessProductsBlock)info errorHandler:(ErrorProductBlock)error;
- (void)fetchProduct:(NSString *)productIdentifier completionHandler:(SuccessProductBlock)info errorHandler:(ErrorProductBlock)error;
- (void)buyProduct:(NotificareProduct *)product;
- (void)pauseDownloads:(NSArray<SKDownload *> *)downloads;
- (void)cancelDownloads:(NSArray<SKDownload *>  *)downloads;
- (void)resumeDownloads:(NSArray<SKDownload *>  *)downloads;
- (NSString * _Nullable)contentPathForProduct:(NSString *)productIdentifier;

@end

NS_ASSUME_NONNULL_END
