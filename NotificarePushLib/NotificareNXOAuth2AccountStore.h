//
//  NXOAuth2AccountStore.h
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

#import "NotificareNXOAuth2TrustDelegate.h"

@class NotificareNXOAuth2Account;
@class NotificareNXOAuth2Connection;

#pragma mark Notifications

extern NSString * const nNXOAuth2AccountStoreDidFailToRequestAccessNotification;
extern NSString * const nNXOAuth2AccountStoreAccountsDidChangeNotification;

extern NSString * const nNXOAuth2AccountStoreNewAccountUserInfoKey;

#pragma mark Configuration

extern NSString * const nkNXOAuth2AccountStoreConfigurationClientID;
extern NSString * const nkNXOAuth2AccountStoreConfigurationSecret;
extern NSString * const nkNXOAuth2AccountStoreConfigurationAuthorizeURL;
extern NSString * const nkNXOAuth2AccountStoreConfigurationTokenURL;
extern NSString * const nkNXOAuth2AccountStoreConfigurationRedirectURL;
extern NSString * const nkNXOAuth2AccountStoreConfigurationScope;
extern NSString * const nkNXOAuth2AccountStoreConfigurationTokenType;
extern NSString * const nkNXOAuth2AccountStoreConfigurationTokenRequestHTTPMethod;

/* 
 * Requires a NSDictionary as a value.
 * They are passed onto the authentication request as additional query parameters.
 * The dictionary may not contain the keys "grant_type", "client_id", "client_secret",
 * "username", "password", "redirect_uri", "code", "assertion_type" and "assertion" are not allowed.
 */
extern NSString * const nkNXOAuth2AccountStoreConfigurationAdditionalAuthenticationParameters;

/*
 * Requires a NSDictionary as a value.
 * They are passed onto the HTTP Header Fields request as additional parameters.
 * Example of a valid setup: @{ @"Content-type" : @"application/x-www-form-urlencoded" }
 */
extern NSString * const nkNXOAuth2AccountStoreConfigurationCustomHeaderFields;


#pragma mark Account Type

extern NSString * const nkNXOAuth2AccountStoreAccountType;


#pragma mark Handler

typedef nNXOAuth2TrustMode(^nNXOAuth2TrustModeHandler)(NotificareNXOAuth2Connection *connection, NSString *hostname);
typedef NSArray *(^nNXOAuth2TrustedCertificatesHandler)(NSString *hostname);
typedef void(^nNXOAuth2PreparedAuthorizationURLHandler)(NSURL *preparedURL);


#pragma mark -

@interface NotificareNXOAuth2AccountStore : NSObject {
@private
    NSMutableDictionary *pendingOAuthClients;
    NSMutableDictionary *accountsDict;
    NSMutableDictionary *configurations;
    NSMutableDictionary *trustModeHandler;
    NSMutableDictionary *trustedCertificatesHandler;
}

+ (id)sharedStore;

#pragma mark Accessors

@property(nonatomic, strong, readonly) NSArray *accounts;
- (NSArray *)accountsWithAccountType:(NSString *)accountType;
- (NotificareNXOAuth2Account *)accountWithIdentifier:(NSString *)identifier;


#pragma mark Configuration

- (void)setClientID:(NSString *)aClientID
             secret:(NSString *)aSecret
   authorizationURL:(NSURL *)anAuthorizationURL
           tokenURL:(NSURL *)aTokenURL
        redirectURL:(NSURL *)aRedirectURL
     forAccountType:(NSString *)anAccountType;

- (void)setClientID:(NSString *)aClientID
             secret:(NSString *)aSecret
              scope:(NSSet *)theScope
   authorizationURL:(NSURL *)anAuthorizationURL
           tokenURL:(NSURL *)aTokenURL
        redirectURL:(NSURL *)aRedirectURL
      keyChainGroup:(NSString *)aKeyChainGroup
     forAccountType:(NSString *)anAccountType;

- (void)setClientID:(NSString *)aClientID
             secret:(NSString *)aSecret
              scope:(NSSet *)theScope
   authorizationURL:(NSURL *)anAuthorizationURL
           tokenURL:(NSURL *)aTokenURL
        redirectURL:(NSURL *)aRedirectURL
      keyChainGroup:(NSString *)aKeyChainGroup
          tokenType:(NSString *)aTokenType
     forAccountType:(NSString *)anAccountType;

- (void)setConfiguration:(NSDictionary *)configuration forAccountType:(NSString *)accountType;

- (NSDictionary *)configurationForAccountType:(NSString *)accountType;


#pragma Trust Mode Handler

- (void)setTrustModeHandlerForAccountType:(NSString *)accountType block:(nNXOAuth2TrustModeHandler)handler;
- (nNXOAuth2TrustModeHandler)trustModeHandlerForAccountType:(NSString *)accountType;

- (void)setTrustedCertificatesHandlerForAccountType:(NSString *)accountType block:(nNXOAuth2TrustedCertificatesHandler)handler;
- (nNXOAuth2TrustedCertificatesHandler)trustedCertificatesHandlerForAccountType:(NSString *)accountType;


#pragma mark Manage Accounts

- (void)requestAccessToAccountWithType:(NSString *)accountType;
- (void)requestAccessToAccountWithType:(NSString *)accountType withPreparedAuthorizationURLHandler:(nNXOAuth2PreparedAuthorizationURLHandler)aPreparedAuthorizationURLHandler;
- (void)requestAccessToAccountWithType:(NSString *)accountType username:(NSString *)username password:(NSString *)password;
- (void)requestAccessToAccountWithType:(NSString *)accountType assertionType:(NSURL *)assertionType assertion:(NSString *)assertion;
- (void)requestClientCredentialsAccessWithType:(NSString *)accountType;
- (void)addAccount:(NotificareNXOAuth2Account *)account;
- (void)removeAccount:(NotificareNXOAuth2Account *)account;


#pragma mark Handle OAuth Redirects

- (BOOL)handleRedirectURL:(NSURL *)URL;

@end
