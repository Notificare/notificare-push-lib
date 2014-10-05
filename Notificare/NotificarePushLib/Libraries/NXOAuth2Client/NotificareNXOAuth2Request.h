//
//  NXOAuth2Request.h
//  OAuth2Client
//
//  Created by Tobias Kräntzer on 13.07.11.
//
//  Copyright 2011 nxtbgthng. All rights reserved.
//
//  Licenced under the new BSD-licence.
//  See README.md in this repository for
//  the full licence.
//

#import <Foundation/Foundation.h>

#import "NotificareNXOAuth2Connection.h"

@class NotificareNXOAuth2Account;

@interface NotificareNXOAuth2Request : NSObject {
@private
    NSDictionary *parameters;
    NSURL *resource;
    NSString *requestMethod;
    NotificareNXOAuth2Account *account;
    NotificareNXOAuth2Connection *connection;
    NotificareNXOAuth2Request *me;
}


#pragma mark Class Methods

+ (void)performMethod:(NSString *)method
           onResource:(NSURL *)resource
      usingParameters:(NSDictionary *)parameters
          withAccount:(NotificareNXOAuth2Account *)account
  sendProgressHandler:(nNXOAuth2ConnectionSendingProgressHandler)progressHandler
      responseHandler:(nNXOAuth2ConnectionResponseHandler)responseHandler;


#pragma mark Lifecycle

- (id)initWithResource:(NSURL *)url method:(NSString *)method parameters:(NSDictionary *)parameter;


#pragma mark Accessors

@property (nonatomic, strong, readwrite) NotificareNXOAuth2Account *account;

@property (nonatomic, strong, readwrite) NSString *requestMethod;
@property (nonatomic, strong, readwrite) NSURL *resource;
@property (nonatomic, strong, readwrite) NSDictionary *parameters;


#pragma mark Signed NSURLRequest

- (NSURLRequest *)signedURLRequest;


#pragma mark Perform Request

- (void)performRequestWithSendingProgressHandler:(nNXOAuth2ConnectionSendingProgressHandler)progressHandler
                                 responseHandler:(nNXOAuth2ConnectionResponseHandler)responseHandler;


#pragma mark Cancel

- (void)cancel;

@end
