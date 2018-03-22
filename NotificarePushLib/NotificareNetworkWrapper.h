//
//  NotificareNetworkWrapper.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareNetworkHost.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^SuccessBlock)(NSDictionary * info);
typedef void (^OperationErrorBlock)(NotificareNetworkOperation *operation, NSError * error);

/*!
 * @typedef kNotificareErrorCode
 * @brief A list of NotificarePushLib HTTP error codes
 * @constant kNotificareErrorCodeBadRequest Request could not be accepted the resource does not exist
 * @constant kNotificareErrorCodeUnauthorized Request failed due to authentication credentials, please check your App Keys
 * @constant kNotificareErrorCodeForbidden Request could not be accepted because of you do not have access to this resource
 * @constant kNotificareErrorCodeNotFound Request failed because resource could not be found
 * @constant kNotificareErrorCodeConflict Request failed due to duplicated resources
 * @constant kNotificareErrorCodeUnprocessableEntity Request failed due to unprocessable parameters
 * @constant kNotificareErrorCodeInternalServerError Request failed due to a server error
 * @constant kNotificareErrorCodeGatewayTimeout Request failed due to a network timeout
 */
typedef enum  {
    kNotificareErrorCodeNotModified = 304,
    kNotificareErrorCodeBadRequest = 400,
    kNotificareErrorCodeUnauthorized = 401,
    kNotificareErrorCodeForbidden = 403,
    kNotificareErrorCodeNotFound = 404,
    kNotificareErrorCodeConflict = 409,
    kNotificareErrorCodeUnprocessableEntity = 422,
    kNotificareErrorCodeInternalServerError = 500,
    kNotificareErrorCodeBadGateway = 502,
    kNotificareErrorCodeServiceUnavailable = 503,
    kNotificareErrorCodeGatewayTimeout = 504
} kNotificareErrorCode;


@interface NotificareNetworkWrapper : NSObject

@property (strong, nonatomic) NotificareNetworkHost *notificarePushNetworkHost;
@property (strong, nonatomic) NotificareNetworkHost *notificareCloudNetworkHost;

+(NotificareNetworkWrapper*)shared;
-(void)launch:(NSString *)appKey andSecret:(NSString *)secret;


/*!
 * @abstract Basic request method for Push API
 *
 * @discussion
 * Creates and executes a Push API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param bodyJSON The JSON payload for the request's body
 * @param successHandler SuccessBlock code block that is executed when the request completes successfully
 * @param errorHandler OperationErrorBlock code block that is executed when the request fails
 * @return The NotificareNetworkOperation that is being executed
 */
- (NotificareNetworkOperation *)doPushHostOperation:(NSString *)HTTPMethod path:(NSString *)path URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams bodyJSON:(id _Nullable)bodyJSON successHandler:(SuccessBlock)successHandler errorHandler:(OperationErrorBlock)errorHandler;

/*!
 * @abstract Basic request method for Push API
 *
 * @discussion
 * Creates and executes a Cloud API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param bodyData The NSData payload for the request's body
 * @param contentType The content type header
 * @param successHandler SuccessBlock code block that is executed when the request completes successfully
 * @param errorHandler OperationErrorBlock code block that is executed when the request fails
 * @return The NotificareNetworkOperation that is being executed
 */
-(NotificareNetworkOperation *)doUploadPushHostOperation:(NSString *)HTTPMethod
                                                    path:(NSString *)path
                                               URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams
                                                bodyData:(NSData *)bodyData
                                             contentType:(NSString *)contentType
                                          successHandler:(SuccessBlock)successHandler
                                            errorHandler:(OperationErrorBlock)errorHandler;

/*!
 * @abstract Basic request method for Cloud API
 *
 * @discussion
 * Creates and executes a Cloud API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param bodyJSON The JSON payload for the request's body
 * @param successHandler SuccessBlock code block that is executed when the request completes successfully
 * @param errorHandler OperationErrorBlock code block that is executed when the request fails
 * @return The NotificareNetworkOperation that is being executed
 */
- (NotificareNetworkOperation *)doCloudHostOperation:(NSString *)HTTPMethod path:(NSString *)path URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams bodyJSON:(id _Nullable)bodyJSON successHandler:(SuccessBlock)successHandler errorHandler:(OperationErrorBlock)errorHandler;

/*!
 * @abstract Basic request method for Cloud API
 *
 * @discussion
 * Creates and executes a Cloud API request.
 * @param HTTPMethod HTTP method, i.e. @"POST"
 * @param path The relative path of the request, i.e. device
 * @param URLParams URL encoded parameters that are added to the request's URL
 * @param customHeaders Key/value pairs for optional custom HTTPS headers
 * @param bodyJSON The JSON payload for the request's body
 * @param successHandler SuccessBlock code block that is executed when the request completes successfully
 * @param errorHandler OperationErrorBlock code block that is executed when the request fails
 * @return The NotificareNetworkOperation that is being executed
 */
- (NotificareNetworkOperation *)doCloudHostOperation:(NSString *)HTTPMethod path:(NSString *)path URLParams:(NSDictionary<NSString *, NSString *> * _Nullable)URLParams customHeaders:(NSDictionary<NSString *, NSString *> * _Nullable)customHeaders bodyJSON:(id _Nullable)bodyJSON successHandler:(SuccessBlock)successHandler errorHandler:(OperationErrorBlock)errorHandler;

@end

NS_ASSUME_NONNULL_END
