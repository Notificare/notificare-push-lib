//
//  NotificareDefinitions.h
//  NotificarePushLib
//
//  Created by Joel Oliveira on 19/10/2017.
//  Copyright © 2017 Notificare. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef NotificareDefinitions_h
#define NotificareDefinitions_h

#define kSDKVersion @"2.1.3"
#define kCoreDataDB @"inboxStoreV2.data"
#define kCoreDataBundle @"NotificareManagedModels"
#define kCoreDataEntity @"NotificareManagedDeviceInbox"
#define kOSVersion [[UIDevice currentDevice] systemVersion]
#define kDaysInterval 1
#define kLocationSessionBackoffDistance 7.0
#define kAuthProtocol @"https"
#define kUseSSL YES
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:(v) options:NSNumericSearch] != NSOrderedAscending)
#define ATTACHMENT_KEY @"attachment"
#define IS_IPAD ( UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad )
#define kFakeBeaconIdentifier @"NotificareFakeBeacon"

#define kNotificareNewRegistration @"notificareNewRegistration"
#define kNotificareSessionDate @"notificareSessionDate"
#define kNotificareRegisteredForNotifications @"notificareRegisteredForNotifications"
#define kNotificareAllowedUI @"notificareAllowedUI"
#define kNotificareUserID @"notificareUserID"
#define kNotificareUserName @"notificareUserName"
#define kNotificareDeviceToken @"notificareDeviceToken"
#define kNotificareDeviceTokenData @"notificareDeviceTokenData"
#define kNotificareDeviceCountry @"notificareDeviceCountry"
#define kNotificareDeviceCountryCode @"notificareDeviceCountryCode"
#define kNotificareAllowedLocationServices @"notificareAllowedLocationServices"
#define kNotificareLocationServicesAuthStatus @"notificareLocationServicesAuthStatus"
#define kNotificareDeviceTimezone @"notificareDeviceTimezone"
#define kNotificareOSVersion @"notificareOSVersion"
#define kNotificareSDKVersion @"notificareSDKVersion"
#define kNotificareAppVersion @"notificareAppVersion"
#define kNotificareDeviceModel @"notificareDeviceModel"
#define kNotificareDeviceLanguage @"notificareDeviceLanguage"
#define kNotificareDeviceRegion @"notificareDeviceRegion"
#define kNotificareDeviceDnD @"notificareDeviceDnD"
#define kNotificareDeviceUserData @"notificareDeviceUserData"
#define kNotificareDeviceLatitude @"notificareDeviceLatitude"
#define kNotificareDeviceLongitude @"notificareDeviceLongitude"
#define kNotificareDeviceAltitude @"notificareDeviceAltitude"
#define kNotificareDeviceCourse @"notificareDeviceCourse"
#define kNotificareDeviceFloor @"notificareDeviceFloor"
#define kNotificareDeviceSpeed @"notificareDeviceSpeed"
#define kNotificareDeviceLastRegistered @"notificareDeviceLastRegistered"
#define kNotificareBackgroundAppRefresh @"notificareBackgroundAppRefresh"
#define kNotificareBluetoothON @"notificareBluetoothON"
#define kNotificareDeviceTransport @"notificareDeviceTransport"

#define kNotificarePreferredLanguage @"notificarePreferredLanguage"
#define kNotificarePreferredRegion @"notificarePreferredRegion"

#define kNotificareInboxBadge @"NotificareInboxBadge"
#define kNotificareCoreDataDB @"notificareCoreDataDB"

#define kNotificareMonitoredBeacons @"notificareMonitoredBeacons"
#define kNotificareMonitoredRegions @"notificareMonitoredRegions"

#define kNotificareCachedBeacons @"notificareCachedBeacons"
#define kNotificareCachedRegions @"notificareCachedRegions"
#define kNotificareRegionSessions @"notificareRegionSessions"
#define kNotificareBeaconSessions @"notificareBeaconSessions"

#define kNotificareErrorStack @"notificareErrorStack"

#define kNotificareMigrationCheck @"notificareMigrationCheckV2"


#define kNotificareEventAppInstall @"re.notifica.event.application.Install"
#define kNotificareEventAppRegistration @"re.notifica.event.application.Registration"
#define kNotificareEventAppUpgrade @"re.notifica.event.application.Upgrade"
#define kNotificareEventAppOpen @"re.notifica.event.application.Open"
#define kNotificareEventAppClose @"re.notifica.event.application.Close"
#define kNotificareEventAppError @"re.notifica.event.application.Exception"
#define kNotificareEventNotificationReceive @"re.notifica.event.notification.Receive"
#define kNotificareEventNotificationOpen @"re.notifica.event.notification.Open"
#define kNotificareEventNotificationInfluenced @"re.notifica.event.notification.Influenced"
#define kNotificareEventRegionSession @"re.notifica.event.region.Session"
#define kNotificareEventBeaconSession @"re.notifica.event.beacon.Session"
#define kNotificareEventLocationVisit @"re.notifica.event.location.Visit"
#define kNotificareEventProductBuy @"re.notifica.event.product.Buy"
#define kNotificareEventProductBuyAppStore @"re.notifica.event.product.Buy.AppStore"
#define kNotificareEventOAuth2Signin @"re.notifica.event.oauth2.Signin"
#define kNotificareEventOAuth2Signup @"re.notifica.event.oauth2.Signup"
#define kNotificareEventOAuth2Signout @"re.notifica.event.oauth2.Signout"
#define kNotificareEventOAuth2ResetPassword @"re.notifica.event.oauth2.ResetPassword"
#define kNotificareEventOAuth2NewPassword @"re.notifica.event.oauth2.NewPassword"
#define kNotificareEventOAuth2SendPassword @"re.notifica.event.oauth2.SendPassword"
#define kNotificareEventOAuth2Validate @"re.notifica.event.oauth2.Validate"
#define kNotificareEventOAuth2Account @"re.notifica.event.oauth2.Account"
#define kNotificareEventOAuth2AccessToken @"re.notifica.event.oauth2.AccessToken"

#define kNotificareHTTPHeaderSDKVersion @"X-Notificare-SDK-Version"
#define kNotificareHTTPHeaderAppVersion @"X-Notificare-App-Version"

#endif /* NotificareDefinitions_h */
