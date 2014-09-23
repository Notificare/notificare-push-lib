//
//   Copyright 2012 Square Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef enum {
    SR_CONNECTING   = 0,
    SR_OPEN         = 1,
    SR_CLOSING      = 2,
    SR_CLOSED       = 3,
    
} SRReadyState;

@class NotificareSRWebSocket;

extern NSString *const nSRWebSocketErrorDomain;

@protocol NotificareSRWebSocketDelegate;

@interface NotificareSRWebSocket : NSObject <NSStreamDelegate>

@property (nonatomic, assign) id <NotificareSRWebSocketDelegate> delegate;

@property (nonatomic, readonly) SRReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;

// This returns the negotiated protocol.
// It will be niluntil after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegage queue will be dispatch_main_queue by default
// Only can set OperationQeuue or dispatch_queue
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NSRunLoop SR_networkRunLoop] using defaultModes
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// SRWebSockets are intended one-time-use only.  Open should be called once and only once
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data
- (void)send:(id)data;

@end

@protocol NotificareSRWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text 
// or NSData if the server is using binary
- (void)webSocket:(NotificareSRWebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(NotificareSRWebSocket *)webSocket;
- (void)webSocket:(NotificareSRWebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(NotificareSRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;

@end


@interface NSURLRequest (CertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *SR_SSLPinnedCertificates;

@end


@interface NSMutableURLRequest (CertificateAdditions)

@property (nonatomic, retain) NSArray *SR_SSLPinnedCertificates;

@end

@interface NSRunLoop (SRWebSocket)

+ (NSRunLoop *)SR_networkRunLoop;

@end
