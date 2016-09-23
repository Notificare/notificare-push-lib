//
//  NotificareNetworkOperation.h
//  NotificarePushLib
//
//  Created by Aernout Peeters on 20-04-2016.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <os/log.h>

/*!
 * @typedef NotificareNetworkOperationState
 * @brief List of NotificareNetworkOperationState types.
 */
typedef NS_ENUM(NSInteger, NotificareNetworkOperationState) {
    NotificareNetworkOperationStateConfig,
    NotificareNetworkOperationStateReady,
    NotificareNetworkOperationStateWaitingForReachability,
    NotificareNetworkOperationStateRunning,
    NotificareNetworkOperationStateCancelled,
    NotificareNetworkOperationStateError,
    NotificareNetworkOperationStateComplete
};

/*!
 * @typedef NotificareNetworkOperationTaskType
 * @brief List of NotificareNetworkOperationTaskType types.
 */
typedef NS_ENUM(NSInteger, NotificareNetworkOperationTaskType) {
    NotificareNetworkOperationTaskTypeData,
    NotificareNetworkOperationTaskTypeDownload,
    NotificareNetworkOperationTaskTypeUpload
};

/*!
 * @typedef NotificareNetworkResponseStatusCode
 * @brief List of NotificareNetworkResponseStatusCode types.
 */
typedef NS_ENUM(NSInteger, NotificareNetworkResponseStatusCode) {
    
    NotificareNetworkResponseStatusCodeContinue                         = 100,
    NotificareNetworkResponseStatusCodeSwitchingProtocols               = 101,
    NotificareNetworkResponseStatusCodeProcessing                       = 102,
    
    NotificareNetworkResponseStatusCodeOK                               = 200,
    NotificareNetworkResponseStatusCodeCreated                          = 201,
    NotificareNetworkResponseStatusCodeAccepted                         = 202,
    NotificareNetworkResponseStatusCodeNonAuthoritativeInformation      = 203,
    NotificareNetworkResponseStatusCodeNoContent                        = 204,
    NotificareNetworkResponseStatusCodeResetContent                     = 205,
    NotificareNetworkResponseStatusCodePartialContent                   = 206,
    NotificareNetworkResponseStatusCodeMultiStatus                      = 207,
    NotificareNetworkResponseStatusCodeAlreadyReported                  = 208,
    NotificareNetworkResponseStatusCodeIMUsed                           = 226,
    
    NotificareNetworkResponseStatusCodeMultipleChoices                  = 300,
    NotificareNetworkResponseStatusCodeMovedPermanently                 = 301,
    NotificareNetworkResponseStatusCodeFound                            = 302,
    NotificareNetworkResponseStatusCodeSeeOther                         = 303,
    NotificareNetworkResponseStatusCodeNotModified                      = 304,
    NotificareNetworkResponseStatusCodeUseProxy                         = 305,
    NotificareNetworkResponseStatusCodeSwitchProxy                      = 306,
    NotificareNetworkResponseStatusCodeTemporaryRedirect                = 307,
    NotificareNetworkResponseStatusCodePermanentRedirect                = 308,
    
    NotificareNetworkResponseStatusCodeBadRequest                       = 400,
    NotificareNetworkResponseStatusCodeUnauthorized                     = 401,
    NotificareNetworkResponseStatusCodePaymentRequired                  = 402,
    NotificareNetworkResponseStatusCodeForbidden                        = 403,
    NotificareNetworkResponseStatusCodeNotFound                         = 404,
    NotificareNetworkResponseStatusCodeMethodNotAllowed                 = 405,
    NotificareNetworkResponseStatusCodeNotAcceptable                    = 406,
    NotificareNetworkResponseStatusCodeProxyAuthenticationRequired      = 407,
    NotificareNetworkResponseStatusCodeRequestTimeout                   = 408,
    NotificareNetworkResponseStatusCodeConflict                         = 409,
    NotificareNetworkResponseStatusCodeGone                             = 410,
    NotificareNetworkResponseStatusCodeLengthRequired                   = 411,
    NotificareNetworkResponseStatusCodePreconditionFailed               = 412,
    NotificareNetworkResponseStatusCodePayloadTooLarge                  = 413,
    NotificareNetworkResponseStatusCodeURITooLong                       = 414,
    NotificareNetworkResponseStatusCodeUnsupportedMediaType             = 415,
    NotificareNetworkResponseStatusCodeRangeNotSatisfiable              = 416,
    NotificareNetworkResponseStatusCodeExpectationFailed                = 417,
    NotificareNetworkResponseStatusCodeImATeapot                        = 418,
    NotificareNetworkResponseStatusCodeMisdirectedRequest               = 421,
    NotificareNetworkResponseStatusCodeUnprocessableEntity              = 422,
    NotificareNetworkResponseStatusCodeLocked                           = 423,
    NotificareNetworkResponseStatusCodeFailedDependency                 = 424,
    NotificareNetworkResponseStatusCodeUpgradeRequired                  = 426,
    NotificareNetworkResponseStatusCodePreconditionRequired             = 428,
    NotificareNetworkResponseStatusCodeTooManyRequests                  = 429,
    NotificareNetworkResponseStatusCodeRequestHeaderFieldsTooLarge      = 431,
    NotificareNetworkResponseStatusCodeUnavailableForLegalReasons       = 451,
    
    NotificareNetworkResponseStatusCodeInternalServerError              = 500,
    NotificareNetworkResponseStatusCodeNotImplemented                   = 501,
    NotificareNetworkResponseStatusCodeBadGateway                       = 502,
    NotificareNetworkResponseStatusCodeServiceUnavailable               = 503,
    NotificareNetworkResponseStatusCodeGatewayTimeout                   = 504,
    NotificareNetworkResponseStatusCodeHTTPVersionNotSupported          = 505,
    NotificareNetworkResponseStatusCodeVariantAlsoNegotiates            = 506,
    NotificareNetworkResponseStatusCodeInsufficientStorage              = 507,
    NotificareNetworkResponseStatusCodeLoopDetected                     = 508,
    NotificareNetworkResponseStatusCodeNotExtended                      = 510,
    NotificareNetworkResponseStatusCodeNetworkAuthenticationRequired    = 511
};



/*! @brief Model for multipart/form-data parts (attachments) on NotificareNetworkOperationTaskTypeData taskType operations. */
@interface NotificareNetworkAttachment : NSObject

/*! @brief Name parameter for multipart/form-data part. */
@property (strong, nonatomic, nonnull) NSString *name;

/*! @brief File name parameter for multipart/form-data part. */
@property (strong, nonatomic, nonnull) NSString *fileName;

/*! @brief Content type parameter for multipart/form-data part. */
@property (strong, nonatomic, nonnull) NSString *contentType;

/*! @brief Content transfer encoding parameter for multipart/form-data part. Uses "binary" if set to nil. */
@property (strong, nonatomic, nullable) NSString * theContentTransferEncoding;

/*! @brief Filed contents for multipart/form-data part. */
@property (strong, nonatomic, nonnull) NSData * theFileData;

@end



@interface NotificareNetworkOperation : NSObject

/*!
 * @brief HTTP method, i.e. @"POST".
 * Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nonnull) NSString *HTTPMethod;

/*! @brief The full URL string including scheme, domain, path and query parameters. */
@property (strong, nonatomic, readonly, nonnull) NSString *URLString;

/*! @brief BOOL value that is determined by the URLString's scheme. */
@property (nonatomic, readonly) BOOL isSecure;

/*! @brief Current NotificareNetworkOperationState value. */
@property (nonatomic, readonly) NotificareNetworkOperationState state;

/*!
 * @brief The task type. Defaults to NotificareNetworkOperationTaskTypeData. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) NotificareNetworkOperationTaskType taskType;

/*!
 * @brief Determines whether a background session should be used. Only supported for NotificareNetworkOperationTaskTypeDownload and NotificareNetworkOperationTaskTypeUpload taskTypes. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) BOOL useBackgroundSession;

/*!
 * @brief The NSURLRequestCachePolicy value that will be used when building the request. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) NSURLRequestCachePolicy cachePolicy;

/*! @brief List of headers that will be added to the request when building. */
@property (copy, nonatomic, readonly, nonnull) NSDictionary<NSString *, NSString *> *headers;

/*!
 * @brief The user name that will be used for authenticated requests. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nullable) NSString *username;

/*!
 * @brief The password that will be used for authenticated requests. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nullable) NSString *password;

/*!
 * @brief BOOL value determining whether or not basic authentication should be used. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) BOOL useBasicAuth;

/*! Denotes whether or not authentication is used. */
@property (nonatomic, readonly) BOOL isAuthenticated;

/*!
 * @brief The payload or request body. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nullable) NSData *requestBodyData;

/*!
 * @brief NSData object to be uploaded. Only usable if taskType equals NotificareNetworkOperationTaskTypeUpload. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nullable) NSData *requestUploadData;

/*!
 * @brief NSURL file to be uploaded. Only usable if taskType equals NotificareNetworkOperationTaskTypeUpload. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (strong, nonatomic, nullable) NSURL *requestUploadFile;

/*! @brief NSURL location NotificareNetworkOperationTaskTypeDownload taskType should move its downloaded file to. */
@property (strong, nonatomic, nullable) NSURL *downloadLocation;

/*! 
 * @brief The NSURLRequest object as configured by this class. Only available after calling -buildRequest.
 */
@property (strong, nonatomic, readonly, nullable) NSURLRequest *request;

/*!
 * @brief The (initial) NSURLSessionTask object created by a NotificareNetworkHost instance. Available once operation has been passed to -[NotificareNetworkHost startOperation:].
 */
@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *task;

/*! @brief Progress value for NotificareNetworkOperationTaskTypeDownload and NotificareNetworkOperationTaskTypeUpload taskTypes. */
@property (nonatomic, readonly) double progress;

/*! @brief NSHTTPURLResponse object available once task has completed. */
@property (strong, nonatomic, readonly, nullable) NSHTTPURLResponse *HTTPResponse;

/*! @brief Raw response data available once task has completed. */
@property (strong, nonatomic, readonly, nullable) NSData *responseData;

/*! @brief Error object available once task has completed with an error. */
@property (strong, nonatomic, readonly, nullable) NSError *error;

/*!
 * @brief The number of times request will be retried if there's no client error. Defaults to 0. Set to -1 for infinite. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) NSInteger retries;

/*! @brief The number of times the task has failed. */
@property (nonatomic, readonly) NSInteger failures;

/*! @brief The number of remaining retries. */
@property (nonatomic, readonly) NSInteger remainingRetries;

/*!
 * @brief The duration for which the operation will stay valid after having started it. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) NSTimeInterval longevity;

/*! @brief NSDate object created when starting or enqueuing the operation. */
@property (strong, nonatomic, readonly, nullable) NSDate *startDate;

/*! @brief Denotes whether the operation has expired. */
@property (nonatomic, readonly) BOOL isExpired;

/*!
 * @brief Code block that is executed when a task successfully completes. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (copy, nonatomic, nullable) void (^successHandler)( NotificareNetworkOperation * _Nonnull operation);

/*!
 * @brief Code block that is executed when a task completes with an error. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (copy, nonatomic, nullable) void (^errorHandler)(NotificareNetworkOperation * _Nonnull operation, NSError * _Nonnull error);

/*!
 * @brief Determines whether or not NotificareNetworkHost should wait for the host to become reachable before executing the operation. Can only be set if state equals NotificareNetworkOperationStateConfig or NotificareNetworkOperationStateReady
 */
@property (nonatomic) BOOL waitForReachability;

/*!
 * @brief Denotes whether or not success and error handlers should be dispatched on main queue. Defaults to YES. Can only be set if state equals NotificareNetworkOperationStateConfig.
 */
@property (nonatomic) BOOL dispatchHandlersOnMainQueue;

/*!
 * @brief Creates a new NotificareNetworkOperation instance.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param URLString The full URL string, including scheme, domain, path and anything else
 */
- (instancetype _Nullable)initWithHTTPMethod:(NSString * _Nonnull)HTTPMethod andWithURLString:(NSString * _Nonnull)URLString;

/*!
 * @brief Creates a new NotificareNetworkOperation instance.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param baseURLString A URL string with a scheme, domain and path but no query string
 * @param URLParams URL encoded parameters that will add a query string to the baseURLString
 */
- (instancetype _Nullable)initWithHTTPMethod:(NSString * _Nonnull)HTTPMethod withBaseURLString:(NSString * _Nonnull)baseURLString andWithURLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams;

/*!
 * @brief Method to set the URLString property. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param baseURLString A URL string with a scheme, domain and path but no query string
 * @param URLParams URL encoded parameters that will add a query string to the baseURLString
 */
- (void)setURLString:(NSString * _Nonnull)baseURLString withURLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams;

/*!
 * @brief Sets a header value for a specified field. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param fieldValue The value to be set.
 * @parm fieldName The name of the field.
 */
- (void)setHeader:(NSString * _Nullable)fieldValue forFieldName:(NSString * _Nonnull)fieldName;

/*!
 * @brief Sets multiple header values. Can only be added if state equals NotificareNetworkOperationStateConfig.
 * @param headers Dictionary where the key equals the header's field name and the value the header's field value.
 */
- (void)addHeaders:(NSDictionary<NSString *, NSString *> * _Nonnull)headers;

/*!
 * @brief Removes specific header values. Can only be removed if state equals NotificareNetworkOperationStateConfig.
 * @param fieldNames The header field names that will be removed.
 */
- (void)removeHeaders:(NSArray<NSString *> * _Nonnull)fieldNames;

/*!
 * @brief Removes all header values. Can only be cleared if state equals NotificareNetworkOperationStateConfig.
 */
- (void)clearHeaders;

/*!
 * @brief Sets username, password and useBasicAuth properties. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param username The user name that will be used for authenticated requests
 * @param password The password that will be used for authenticated requests
 * @param useBasicAuth Denotes whether or not basic authentication should be used
 */
- (void)setUsername:(NSString * _Nullable)username password:(NSString * _Nullable)password useBasicAuth:(BOOL)useBasicAuth;

/*!
 * @brief Creates a url encoded query string to use as a request body. Sets Content-Type header to application/x-www-form-urlencoded. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param params Dictionary where keys will be uses for parameter names and values for parameter values
 */
- (void)setRequestBodyDataWithParams:(NSDictionary<NSString *, NSString *> * _Nonnull)params;

/*!
 * @brief Creates a multipart request body from parameters and attachments. Sets Content-Type header to multipart/form-data. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param params Dictionary where keys will be uses for parameter names and values for parameter values
 * @param attachments List of NotificareNetworkAttachment objects
 */
- (void)setRequestBodyDataWithParams:(NSDictionary<NSString *, NSString *> * _Nonnull)params andWithAttachments:(NSArray<NotificareNetworkAttachment *> * _Nonnull)attachments;

/*!
 * @brief Sets request body from a JSON object. Sets Content-Type header to application/json. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param JSON An object that can be converted to JSON, such as an NSArray or NSDictionary object
 */
- (void)setRequestBodyDataWithJSON:(id _Nonnull)JSON;

/*! 
 * @brief Sets request body from a UIImage object. Sets Content-Type header to image/jpeg or image/png, depepending on type. Can only be set if state equals NotificareNetworkOperationStateConfig.
 * @param image The image object to be encoded
 * @param type "jpeg" or "png"
 */
- (void)setRequestBodyDataWithImage:(UIImage * _Nonnull)image type:(NSString * _Nonnull)type;

/*!
 * @brief Creates an NSURLRequest object based on HTTPMethod, URLString, headers and requestBody. Can only be built if state equals NotificareNetworkOperationStateConfig. Sets state to NotificareNetworkOperationStateRunning.
 */
- (void)buildRequest;

/*!
 * @brief Cancels the task and will trigger errorHandler if set. Can only be cancelled if state equals NotificareNetworkOperationStateRunning.
 */
- (void)cancel;

/*!
 * @brief Converts responseData to a UTF8 encoded string.
 * @return A UTF8 encoded NSString object.
 */
- (NSString * _Nullable)responseDataToUTF8String;

/*!
 * @brief Tries to deserialize responseData into a JSON object.
 * @return A JSON object such as an NSArray or NSDictionary object.
 */
- (id _Nullable)responseDataToJSON;

/*!
 * @brief Creates a UIImage object with the responseData.
 * @return A UIImage object.
 */
- (UIImage * _Nullable)responseDataToImage;



@end
