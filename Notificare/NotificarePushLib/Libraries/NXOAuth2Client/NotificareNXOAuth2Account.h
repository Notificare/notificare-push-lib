//
//  NXOAuth2Account.h
//  OAuth2Client
//
//  Created by Tobias Kräntzer on 12.07.11.
//
//  Copyright 2011 nxtbgthng. All rights reserved.
//
//  Licenced under the new BSD-licence.
//  See README.md in this repository for
//  the full licence.
//

#import <Foundation/Foundation.h>

@class NotificareNXOAuth2Client;
@class NotificareNXOAuth2AccessToken;

#pragma mark Notifications

extern NSString * const nNXOAuth2AccountDidChangeUserDataNotification;
extern NSString * const nNXOAuth2AccountDidChangeAccessTokenNotification;
extern NSString * const nNXOAuth2AccountDidLoseAccessTokenNotification;
extern NSString * const nNXOAuth2AccountDidFailToGetAccessTokenNotification;

#pragma mark -

@interface NotificareNXOAuth2Account : NSObject {
@private
    NSString *accountType;
    NSString *identifier;
    id <NSObject, NSCoding, NSCopying> userData;
    NotificareNXOAuth2Client *oauthClient;
    NotificareNXOAuth2AccessToken *accessToken;
}

#pragma mark Accessors

@property (nonatomic, copy, readonly) NSString *accountType;
@property (nonatomic, copy, readonly) NSString *identifier;
@property (nonatomic, copy) id <NSObject, NSCoding, NSCopying> userData;

@property (nonatomic, strong, readonly) NotificareNXOAuth2Client *oauthClient;
@property (nonatomic, strong, readonly) NotificareNXOAuth2AccessToken *accessToken;

@end
