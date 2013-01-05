//
//  NotificareActions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 11/25/12.
//  Copyright (c) 2012 Notificare. All rights reserved.
//

#import "MKNetworkKit.h"

@class NotificareActions;

/*!
 NotificareActionsDelegate
 */
@protocol NotificareActionsDelegate

@optional

- (void)notificareActions:(NotificareActions *)connector willOpenAction:(NSDictionary *)info;

- (void)notificareActions:(NotificareActions *)connector didOpenAction:(NSDictionary *)info;

- (void)notificareActions:(NotificareActions *)connector willExecuteAction:(NSDictionary *)info;

- (void)notificareActions:(NotificareActions *)connector didExecuteAction:(NSDictionary *)info;


@required

- (void)notificareActions:(NotificareActions *)connector didFailWithError:(NSError *)error;

@end

/*!
  
 */
@interface NotificareActions : NSObject {
	SEL didFailSelector;
	SEL didFinishSelector;
}

/*!
 The delegate to call on results
 */
@property (strong, nonatomic) id<NotificareActionsDelegate> delegate;
@property (nonatomic, assign) SEL didFailSelector;
@property (nonatomic, assign) SEL didFinishSelector;



@end
