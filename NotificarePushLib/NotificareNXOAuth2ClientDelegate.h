//
//  NXOAuth2ClientDelegate.h
//  OAuth2Client
//
//  Created by Gernot Poetsch on 14.09.10.
//
//  Copyright 2010 nxtbgthng. All rights reserved.
//
//  Licenced under the new BSD-licence.
//  See README.md in this repository for
//  the full licence.
//

#import "NotificareNXOAuth2Constants.h"
#import "NotificareNXOAuth2TrustDelegate.h"

@class NotificareNXOAuth2Client;

@protocol NotificareNXOAuth2ClientDelegate <NotificareNXOAuth2TrustDelegate>

@required
/*!
 * When this is called on the delegate, you are supposed to invoke the appropriate authentication method in the client.
 */
- (void)oauthClientNeedsAuthentication:(NotificareNXOAuth2Client *)client;

@optional
- (void)oauthClientDidGetAccessToken:(NotificareNXOAuth2Client *)client;
- (void)oauthClientDidLoseAccessToken:(NotificareNXOAuth2Client *)client;
- (void)oauthClientDidRefreshAccessToken:(NotificareNXOAuth2Client *)client;
- (void)oauthClient:(NotificareNXOAuth2Client *)client didFailToGetAccessTokenWithError:(NSError *)error;

@end