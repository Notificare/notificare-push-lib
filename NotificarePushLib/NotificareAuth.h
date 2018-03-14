//
//  NotificareAuth.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 18/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NotificareUser.h"
#import "NotificareNXOAuth2.h"
#import "NotificareSegment.h"
#import "NotificareUserPreference.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^NotificareAuthCompletionBlock)(id _Nullable response , NSError * _Nullable error);

@class NotificareAuth;

@protocol NotificareAuthDelegate <NSObject>

@optional

- (void)notificareAuth:(NotificareAuth *)notificareAuth didChangeAccountNotification:(NSDictionary *)info;
- (void)notificareAuth:(NotificareAuth *)notificareAuth didFailToRequestAccessNotification:(NSError * _Nullable)error;
- (void)notificareAuth:(NotificareAuth *)notificareAuth didReceiveActivationToken:(NSString *)token;
- (void)notificareAuth:(NotificareAuth *)notificareAuth didReceiveResetPasswordToken:(NSString *)token;

@end

@interface NotificareAuth : NSObject

@property (nonatomic, assign) id<NotificareAuthDelegate> notificareAuthDelegate;
@property (nonatomic, strong) NSString *accountStoreType;
@property (nonatomic, strong, nullable) NotificareUser * user;

+(NotificareAuth*)shared;
-(void)launch;

/*!
 *  @abstract Create Account
 *
 *  @discussion
 *  Use this method to create an account. According to the settings of your add-on module, this can trigger the recipient to receive
 *  email messages to activate this account or simply to welcome him/her to your app.
 *  @param email A NSString representing the email address
 *  @param name A NSString representing the name address
 *  @param password A NSString representing the password address
 *  @code [[[NotificarePushLib shared] authManager] createAccount:[[self email] text] withName:[[self name] text] andPassword:[[self password] text] completionHandler:^(NSDictionary *info) {
 
 } errorHandler:^(NSError *error) {
 
 }];
 */
- (void)createAccount:(NSString *)email withName:(NSString *)name andPassword:(NSString *)password completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Reset Password
 *
 *  @discussion
 *  Use this method to allow the user to reset his/her password. The token required by this application can only be retrieved if the
 *  delegate didReceiveResetPasswordToken: is implemented. Please implement that protocol delegate. Use the token provide by to complete this operation
 *  @param password A NSString representing the new password for this account
 */
- (void)resetPassword:(NSString *)password withToken:(NSString *)token completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Validate Account
 *
 *  @discussion
 *  Use this method to allow the user to activate his/her account. This will be exclusively triggered by the email received by the user. For this to work,
 *  make sure you implement the delegate didReceiveActivationToken: and call this method inside that delegate.
 */
- (void)validateAccount:(NSString *)token completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Send Password
 *
 *  @discussion
 *  Use this method to allow the user to request a new password for his/her account. This will trigger an email message that will allow the user to create
 *  a new password as described in resetPassword:withToken: methods explained above.
 *  @param email A NSString representing the email address for the account to be recovered
 */
- (void)sendPassword:(NSString *)email completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Login
 *
 *  @discussion
 *  Use this method to allow the user to authenticate in your application. Once successfully logged in the library will automatically add this account to the
 *  device's keychain. This will make sure the user data is store and encrypted and only accessible by that device. Also after this method being
 *  successfully completed you can use all the user related methods described below.
 *  @param username A NSString representing the email address used as username
 *  @param password A NSString representing the password for this account
 */
- (void)loginWithUsername:(NSString *)username andPassword:(NSString *)password completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Logout
 *
 *  @discussion
 *  Use this method should be log out any authenticated user. This method should also be used to allow the user to forget a device.
 */
- (void)logoutAccount;
/*!
 *  @abstract Logout
 *
 *  @discussion
 *  Use this helper method to check if the user is logged in or not. This is meant to help the app's UI display any user related method without having to
 *  request the full User Object.
 *  @return A Boolean indicating if user is logged in or not
 */
- (BOOL)isLoggedIn;
/*!
 *  @abstract Account Data
 *
 *  @discussion
 *  Use this method to access the user profile.
 */
- (void)fetchAccountDetails:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Access Token
 *
 *  @discussion
 *  Use this method to generate an access token for this user. This access token could be shared with 3rd parties and will be used by our Mail Push
 *  service to quickly send notifications to a user using an email message. Simply use the code generated as the user of the following host: CODE@push.notifica.re
 */
- (void)generateAccessToken:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Change Password
 *
 *  @discussion
 *  Use this method to allow an authenticated user to change his/her password. Preferebly the UI for this method should handle any validation or
 *  any matching password confirmation functionality before requesting this method.
 *  @param password A NSString representing the password
 */
- (void)changePassword:(NSString *)password completionHandler:(NotificareAuthCompletionBlock)completionBlock;

/*!
 *  @abstract Segments
 *
 *  @discussion
 *  List of all NotificareUserPreference objects. These objects will contain information about user selectable segments. Should be used to show the user's selectable segments defined for this application.
 */
- (void)fetchUserPreferences:(NotificareAuthCompletionBlock)completionBlock;

/*!
 *  @abstract Add User Segment
 *
 *  @discussion
 *  Use this method to allow an authenticated user to add himself/herself to a segment previously created and added to the user preferences. These are
 *  retrievable by the method described below.
 *  @param segment A NotificareSegment object
 *  @param preference A NotificareUserPreference object
 */
- (void)addSegment:(NotificareSegment *)segment toPreference:(NotificareUserPreference *)preference completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Remove User Segment
 *
 *  @discussion
 *  Use this method to allow an authenticated user to remove himself/herself from a segment previously created and added to the user preferences. These are
 *  retrievable by the method described below.
 *  @param segment A NotificareSegment object
 *  @param preference A NotificareUserPreference object
 */
- (void)removeSegment:(NotificareSegment *)segment fromPreference:(NotificareUserPreference *)preference completionHandler:(NotificareAuthCompletionBlock)completionBlock;
/*!
 *  @abstract Check Account
 *
 *  @discussion
 *  Use this helper method to quickly check if an account with this email has been created.
 */
- (void)checkAccount:(NSString *)user completionHandler:(NotificareAuthCompletionBlock)completionBlock;


@end

NS_ASSUME_NONNULL_END
