//
//  NotificarePassbookViewController.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 14/10/14.
//  Copyright (c) 2014 Notificare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PassKit/PassKit.h>
#import "NSString+FromBundle.h"
#import "UIImage+FromBundle.h"
#import "NSDictionary+FromPlist.h"
#import "NSDate+TimeAgo.h"

@interface NotificarePassbookViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@property (strong, nonatomic) NSMutableArray * tableSections;
@property (strong, nonatomic) NSMutableArray * tableSectionTitles;
@property (strong, nonatomic) UITableView * tableView;
@property (strong, nonatomic) UILabel * emptyLabel;
@property (strong, nonatomic) PKPassLibrary * passLib;

@end
