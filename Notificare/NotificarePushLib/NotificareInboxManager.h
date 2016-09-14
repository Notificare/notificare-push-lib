//
//  NotificareInboxManager.h
//  app
//
//  Created by Aernout Peeters on 03-05-2016.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NotificareInboxManager;
@class NotificareManagedDeviceInbox;


/*! @brief Protocol definition for NotificareInboxManager's delegate. */
@protocol NotificareInboxManagerDelegate <NSObject>

@optional

/*!
 * @brief Delegate method that is triggered after fetching latest inbox items.
 * @param notificareInboxManager The NotificareInboxManager instance.
 */
- (void)didUpdateInbox:(NotificareInboxManager *)notificareInboxManager;

/*!
 * @brief Delegate method that is triggered after clearing local inbox and fetching all inbox items.
 * @param notificareInboxManager The NotificareInboxManager instance.
 */
- (void)didReloadInbox:(NotificareInboxManager *)notificareInboxManager;

/*!
 * @brief Delegate method that is triggered after opening an inbox item.
 * @param notificareInboxManager The NotificareInboxManager instance.
 * @param managedInboxItem The opened NotificareManagedDeviceInbox item.
 */
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didOpenInboxItem:(NotificareManagedDeviceInbox *)managedInboxItem;

/*!
 * @brief Delegate method that is triggered after removing an inbox item.
 * @param notificareInboxManager The NotificareInboxManager instance.
 * @param managedInboxItem The removed NotificareManagedDeviceInbox item.
 */
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didRemoveFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem;

/*!
 * @brief Delegate method that is triggered after removing an inbox item at a specified indexPath.
 * @param notificareInboxManager The NotificareInboxManager instance.
 * @param managedInboxItem The removed NotificareManagedDeviceInbox item.
 * @param indexPath The NSIndexPath the item was removed at.
 */
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didRemoveFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem forIndexPath:(NSIndexPath *)indexPath;

/*!
 * @brief Delegate method that is triggered after clearing local and remote inboxes.
 * @param notificareInboxManager The NotificareInboxManager instance.
 */
- (void)didClearInbox:(NotificareInboxManager *)notificareInboxManager;

@end


@interface NotificareInboxManager : NSObject

/*!
 * @brief Used to determine if NotificarePushLib should update NotificareInboxManager when handling notifications. Must be set to YES after calling +sharedManager before using.
 */
@property (nonatomic) BOOL enabled;

/*! @brief NSArray object holding NotificareManagedDeviceInbox items. */
@property (nonatomic, copy, readonly) NSArray<NotificareManagedDeviceInbox *> *managedInboxItems;

/*! @brief Creates a singleton instance of NotificareInboxManager. */
+ (instancetype)sharedManager;

/*!
 * @brief Adds an object to the list of delegates.
 * @param delegate An object implementing the NotificareInboxManagerDelegate protocol
 */
- (void)addDelegate:(id<NotificareInboxManagerDelegate>)delegate;

/*!
 * @brief Removes an object from the list of delegates.
 * @param delegate An object implementing the NotificareInboxManagerDelegate protocol
 */
- (void)removeDelegate:(id<NotificareInboxManagerDelegate>)delegate;

/*! @brief Fetches latest inbox items. */
- (void)updateInbox;

/*! @brief Clears local inbox and fetches all inbox items. */
- (void)reloadInbox;

/*!
 * @brief Opens inbox item.
 * @param managedInboxItem The NotificareManagedDeviceInbox item to be opened.
 */
- (void)openInboxItem:(NotificareManagedDeviceInbox *)managedInboxItem;

/*!
 * @brief Removes inbox item.
 * @param managedInboxItem The NotificareManagedDeviceInbox item to be removed.
 */
- (void)removeFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem;

/*!
 * @brief Removes inbox item at specified path.
 * @param managedInboxItem The NotificareManagedDeviceInbox item to be removed.
 * @param indexPath The NSIndexPath the item will be removed at.
 */
- (void)removeFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem forIndexPath:(NSIndexPath *)indexPath;

/*! @brief Clears local and remote inboxes. */
- (void)clearInbox;

/*! @brief Clears local inbox. */
- (void)clearLocalInbox;

@end
