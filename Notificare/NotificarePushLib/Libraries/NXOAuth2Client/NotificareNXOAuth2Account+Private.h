//
//  NXOAuth2Account+Private.h
//  OAuth2Client
//
//  Created by Tobias Kräntzer on 19.07.11.
//
//  Copyright 2011 nxtbgthng. All rights reserved.
//
//  Licenced under the new BSD-licence.
//  See README.md in this repository for
//  the full licence.
//

#import "NotificareNXOAuth2Account.h"

@interface NotificareNXOAuth2Account (Private)

- (id)initAccountWithOAuthClient:(NotificareNXOAuth2Client *)oauthClient accountType:(NSString *)accountType;
- (id)initAccountWithAccessToken:(NotificareNXOAuth2AccessToken *)accessToken accountType:(NSString *)accountType;

@end
