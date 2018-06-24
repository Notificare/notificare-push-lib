//
//  NotificareInboxManager.h
//  app
//
//  Created by Aernout Peeters on 03-05-2016.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "NotificareManagedDeviceInbox.h"
#import "NotificareDeviceInbox.h"
#import "NotificareNotification.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^NotificareInboxCompletionBlock)(id _Nullable response , NSError * _Nullable error);

@class NotificareInboxManager;

@protocol NotificareInboxManagerDelegate <NSObject>

@optional

- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didLoadInbox:(NSArray<NotificareDeviceInbox*>*)items;
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didUpdateBadge:(int)badge;

@end


@interface NotificareInboxManager : NSObject

@property (nonatomic, assign) id<NotificareInboxManagerDelegate> notificareInboxManagerDelegate;

+(NotificareInboxManager*)shared;
- (void)launch;
- (void)reloadInbox;
- (void)updateInboxItem:(NotificareNotification*)notification;
- (void)addInboxItem:(NSDictionary*)userInfo completionHandler:(NotificareInboxCompletionBlock)completionBlock;
- (int)myBadge;

/*!
 *  @abstract Refresh inbox items
 *
 *  @discussion
 *  Use this method to sync inbox items on-demand. Useful when remote notifications are not implemented.
 */
- (void)refresh;
/*!
 *  @abstract Fetch the inbox items
 *
 *  @discussion
 *  Displays the inbox items list
 */
- (void)fetchInbox:(NotificareInboxCompletionBlock)completionBlock;
/*!
 *  @abstract Open inbox item
 *
 *  @discussion
 *  Displays the inbox item. Should be used with a NotificareDeviceInbox item.
 *  @param inboxItem A NotificareDeviceInbox object
 */
- (void)openInboxItem:(NotificareDeviceInbox *)inboxItem completionHandler:(NotificareInboxCompletionBlock)completionBlock;

/*!
 *  @abstract Remove Inbox Item from Inbox
 *
 *  @discussion
 *  Remove an inbox item from the Inbox
 *  @param inboxItem A NotificareDeviceInbox object
 */
- (void)removeFromInbox:(NotificareDeviceInbox *)inboxItem completionHandler:(NotificareInboxCompletionBlock)completionBlock;
/*!
 *  @abstract Mark Inbox Item as read
 *
 *  @discussion
 *  Mark an inbox item as read
 *  @param inboxItem A NotificareDeviceInbox object
 */
- (void)markAsRead:(NotificareDeviceInbox *)inboxItem completionHandler:(NotificareInboxCompletionBlock)completionBlock;

/*!
 *  @abstract Remove All Notifications from Inbox
 *
 *  @discussion
 *  Remove all notifications from the Inbox
 */
- (void)clearInbox:(NotificareInboxCompletionBlock)completionBlock;

/*!
 *  @abstract Helper method to force a badge refresh
 *
 *  @discussion
 *  Force a badge refresh
 */
-(void)refreshBadge:(NotificareInboxCompletionBlock)completionBlock;

@end
NS_ASSUME_NONNULL_END
