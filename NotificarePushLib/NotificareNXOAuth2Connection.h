//
//  NXOAuth2Connection.h
//  OAuth2Client
//
//  Created by Ullrich Schäfer on 27.08.10.
//
//  Copyright 2010 nxtbgthng. All rights reserved.
//
//  Licenced under the new BSD-licence.
//  See README.md in this repository for
//  the full licence.
//

#import <Foundation/Foundation.h>

#import "NotificareNXOAuth2Constants.h"

@class NotificareNXOAuth2Client;
@protocol NotificareNXOAuth2ConnectionDelegate;


/*!
 *    The connection
 *
 *    NXOAuth2Connection is a wrapper around NXURLConnection.
 *    It's main purpose is to simplify the delegates & to provide a context
 *    ivar that can be used to put a connection object in a certain context.
 *    The context may be compared to a tag.
 *
 *    NXOAuth2Connection only provides asynchronous connections as synchronous
 *    connections are strongly discouraged.
 *
 *    The connection works together with the OAuth2 Client to sign a request
 *    before sending it. If no client is passed in the connection will sent
 *    unsigned requests.
 */


#ifndef nNXOAuth2ConnectionDebug
#define nNXOAuth2ConnectionDebug 0
#endif



extern NSString * const nNXOAuth2ConnectionDidStartNotification;
extern NSString * const nNXOAuth2ConnectionDidEndNotification;


typedef void(^nNXOAuth2ConnectionResponseHandler)(NSURLResponse *response, NSData *responseData, NSError *error);
typedef void(^nNXOAuth2ConnectionSendingProgressHandler)(unsigned long long bytesSend, unsigned long long bytesTotal);


@interface NotificareNXOAuth2Connection : NSObject {
@private
    NSURLConnection        *connection;
    NSMutableURLRequest    *request;
    NSURLResponse        *response;
    NSDictionary        *requestParameters;
    
    NSMutableData        *data;
    BOOL                savesData;
    
    id                    context;
    NSDictionary        *userInfo;
    
    NotificareNXOAuth2Client        *client;
    
    NSObject<NotificareNXOAuth2ConnectionDelegate>    *__unsafe_unretained delegate;    // assigned
    
    nNXOAuth2ConnectionResponseHandler responseHandler;
    nNXOAuth2ConnectionSendingProgressHandler sendingProgressHandler;
    
    BOOL                sendConnectionDidEndNotification;
    
#if (nNXOAuth2ConnectionDebug)
    NSDate *startDate;
#endif
}

@property (nonatomic, unsafe_unretained) NSObject<NotificareNXOAuth2ConnectionDelegate>    *delegate;
@property (nonatomic, strong, readonly) NSData *data;
@property (nonatomic, assign) BOOL savesData;
@property (nonatomic, assign, readonly) long long expectedContentLength;
@property (nonatomic, strong, readonly) NSURLResponse *response;
@property (nonatomic, assign, readonly) NSInteger statusCode;
@property (nonatomic, strong) id context;
@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, strong, readonly) NotificareNXOAuth2Client *client;

- (id) initWithRequest:(NSMutableURLRequest *)request
     requestParameters:(NSDictionary *)requestParameters
           oauthClient:(NotificareNXOAuth2Client *)client
sendingProgressHandler:(nNXOAuth2ConnectionSendingProgressHandler)sendingProgressHandler
       responseHandler:(nNXOAuth2ConnectionResponseHandler)responseHandler;

- (id)initWithRequest:(NSMutableURLRequest *)request
    requestParameters:(NSDictionary *)requestParameters
          oauthClient:(NotificareNXOAuth2Client *)client
             delegate:(NSObject<NotificareNXOAuth2ConnectionDelegate> *)delegate;

- (void)cancel;

- (void)retry;

@end
