//
//  NotificareBaseInboxViewController.h
//  app
//
//  Created by Aernout Peeters on 03-05-2016.
//  Copyright © 2016 Notificare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NotificareInboxManager.h"

@interface NotificareBaseInboxViewController : UIViewController <NotificareInboxManagerDelegate, UITableViewDataSource, UITableViewDelegate>

/*! @brief The NotificareInboxManager instance. Use to update inbox and to open or remove inbox items. */
@property (strong, nonatomic, readonly) NotificareInboxManager *notificareInboxManager;

/*! @brief The UITableView this class is the data source and delegate for. If not set, it will try to fall back to the view property. */
@property (strong, nonatomic) IBOutlet UITableView *tableView;

/*! @brief UIFont for the message label in cells created by this class. */
@property (strong, nonatomic) UIFont *cellMessageLabelFont;

/*! @brief UIFont for the time ago label in cells created by this class. */
@property (strong, nonatomic) UIFont *cellTimeAgoLabelFont;

/*! @brief UIColor that is used for labels in cell created by this class if the inbox item hasn't been opened yet. */
@property (strong, nonatomic) UIColor *cellUnopenedTextColor;

/*! @brief UIColor that is used for labels in cell created by this class if the inbox item has been opened. */
@property (strong, nonatomic) UIColor *cellOpenedTextColor;

/* Methods from NotificareInboxManagerDelegate. Override where needed. */
- (void)didUpdateInbox:notificareInboxManager;
- (void)didReloadInbox:(NotificareInboxManager *)notificareInboxManager;
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didOpenInboxItem:(NotificareManagedDeviceInbox *)managedInboxItem;
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didRemoveFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem;
- (void)notificareInboxManager:(NotificareInboxManager *)notificareInboxManager didRemoveFromInbox:(NotificareManagedDeviceInbox *)managedInboxItem forIndexPath:(NSIndexPath *)indexPath;
- (void)didClearInbox:notificareInboxManager;

@end
