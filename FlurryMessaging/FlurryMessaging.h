//
//  FlurryMessaging.h
//  FlurryMessaging
//
//  Created by Shruthi Ramesh on 11/16/17.
//  Copyright © 2017 Flurry Inc. All rights reserved.
//
#if !TARGET_OS_WATCH
#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

@class FlurryMessage;

/*!
 *  @brief Provides all available delegates for receiving callbacks related to Flurry Notifications.
 *  @since 8.1.0.rc.1
 *
 *  Set of methods that allow developers to manage and take actions within the App.
 *  @note Useful when used with the AUTOMATIC INTEGRATION
 *
 */
@protocol FlurryMessagingDelegate <NSObject>

@optional

/*!
 *  @brief Invoked when Flurry Notifications is received
 *  @since 8.1.0.rc.1
 *
 *  This method informs the app that Flurry Notifications was received.
 *
 */
-(void) didReceiveMessage:(nonnull FlurryMessage*)message;

/*!
 *  @brief Invoked when Flurry Notifications receives an action
 *  @since 8.1.0.rc.1
 *
 *  This method informs the app that Flurry Notifications receives an action.
 *
 */
-(void) didReceiveActionWithIdentifier:(nullable NSString*)identifier message:(nonnull FlurryMessage*)message;

@end

typedef void(^MessagingHandler)(void);

/*!
 *  @brief FlurryMessage is a convenience class to access all the properties set on the Flurry Message.
 *  @since 8.1.0.rc.1
 *
 *  Title    - gives the Message title
 *  Body     - gives the Message body
 *  Sound    - gives the name of the sound file set on the Message payload
 *  AppData  - gives the custom <key, value> pairs set on the Message payload
 *
 */
@interface FlurryMessage : NSObject

@property (nonatomic, readonly, strong, nullable) NSString* title;
@property (nonatomic, readonly, strong, nullable) NSString* body;
@property (nonatomic, readonly, strong, nullable) NSString* sound;
@property (nonatomic, readonly, strong, nullable) NSDictionary* appData;

@end


@interface FlurryMessaging : NSObject

/*!
 *  @brief (MANUAL INTEGRATION) Enables Passing of the Device Token for the Push Notification
 *  @since 8.1.0.rc.1
 *
 *  @code
 -(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
 {
 [Flurry setDeviceToken:deviceToken];
 }
 * @endcode
 *
 */
+(void) setDeviceToken:(nullable NSData *)deviceToken;

/*!
 *  @brief (MANUAL INTEGRATION) Method to be called when a remote notfication is received
 *  @since 8.1.0.rc.1
 *
 *  This method logs and processes the Flurry Push Notification when received.
 *
 *  @code
 -(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
 fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
 {
 [Flurry receivedRemoteNotification:userInfo withCompletionHandler:^{
 //Load and Nibs or storyboard from here
 completionHandler(UIBackgroundFetchResultNoData);
 }];
 }
 * @note The completionHandler provided by UIApplication should be called within the Flurry's completion handler.
 * This gives Flurry sufficient time to finish processing and not suspend the app in between. The completionHandler may be called from a background thread.
 *
 * @endcode
 *
 */
#if TARGET_OS_IPHONE
+(void) receivedRemoteNotification:(nonnull NSDictionary *)userInfo withCompletionHandler:(_Nullable MessagingHandler)completionHandler;
#endif
/*!
 *  @brief (MANUAL INTEGRATION) Method to be called when a notification is presented by the UNUserNotificationCenter when in foreground.
 *  @since 8.1.0.rc.1
 *
 *  This method logs and processes the Flurry Push Notification when presented in foreground by the UNUserNotificationCenter.
 *
 *  @code
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification
 withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler
 {
 [Flurry presentNotification:notification withCompletionHandler:^{
 completionHandler(UNNotificationPresentationOptionSound);
 }];
 }
 * @note Does not have to be implemented if the app is not targetting iOS10 or if you do not wish to use
 * UNUserNotificationCenter.
 * The completionHandler provided by UNUserNotificationCenter should be called within the Flurry's completion handler.
 * This gives Flurry sufficient time to finish processing and not suspend the app in between.
 * UNNotificationPresentationOptions - gives various options to deal with a notifcation in foreground.
 *
 * @endcode
 *
 */

+(void) presentNotification:(nonnull UNNotification *)notification withCompletionHandler:(_Nullable MessagingHandler)completionHandler API_AVAILABLE(ios(10.0));

/*!
 *  @brief (MANUAL INTEGRATION) Method to be called when a action on a notfication is received from UNUserNotificationCenter.
 *  @since 8.1.0.rc.1
 *
 *  This method logs and processes the Flurry Push Notification actions.
 *
 *  @code
 - (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response
 withCompletionHandler:(void (^)(void))completionHandler
 {
 [Flurry receivedNotificationResponse:response withCompletionHandler:^{
 completionHandler();
 }];
 }
 * @note Does not have to be implemented if the app is not targetting iOS10 or if you do not wish to use
 * UNUserNotificationCenter.
 * The completionHandler provided by UNUserNotificationCenter should be called within the Flurry's completion handler.
 * This gives Flurry sufficient time to finish processing and not suspend the app in between. The completionHandler may be called from a background thread.
 *
 * @endcode
 *
 */
#if !TARGET_OS_TV
+(void) receivedNotificationResponse:(nonnull UNNotificationResponse *)response withCompletionHandler:(_Nullable MessagingHandler) completionHandler API_AVAILABLE(ios(10.0));
#endif
/*!
 *  @brief Helper method which identifies a Flurry generated Push Notification
 *  @since 8.1.0.rc.1
 *
 *  @code
 -(void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
 fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
 {
 if(Flurry isFlurryMsg:userInfo]) {
 [Flurry receivedRemoteNotification:userInfo withCompletionHandler:^{
 //Load and Nibs or storyboard from here
 completionHandler(UIBackgroundFetchResultNoData);
 }];
 }
 }
 * @endcode
 *
 */
+(BOOL) isFlurryMsg:(nonnull NSDictionary*)userInfo;


/*!
 *  @brief Call this setter if you want enable AUTOMATIC INTEGRATION for Push Notificaions.
 *  @since 8.1.0.rc.1
 *
 *  This method takes care of all the setup for Push Notifications.
 *  1) Registers for Notifications
 *  2) Handles device tokens
 *  3) Listens for callbacks from UIApplication and UNUserNotificationCenter
 *
 *  @code
 *  - (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 [Flurry setAutoIntegrationForMessaging];
 // ....
 }
 * @endcode
 *
 */
+(void) setAutoIntegrationForMessaging;

/*!
 *  @brief Set FlurryMessaging delegate for optional callback on push events.
 *  @since 8.1.0.rc.1
 *
 * @code
 *  - (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 [Flurry setAutoIntegrationForMessaging];
 // If self implements protocol, FlurryMessagingDelegate
 [Flurry setMessagingDelegate:self];
 // ....
 }
 *  @note By default the callback is received on the main queue. Optionally users can choose to receive on a specific queue by using
 +(void) setMessagingDelegate:(nonnull __weak id<FlurryMessagingDelegate>)delegate withCallbackQueue:(nonnull dispatch_queue_t)messagingCallbackQueue;
 * @endcode
 *
 */
+(void) setMessagingDelegate:(nonnull id<FlurryMessagingDelegate>)delegate ;


/*!
 *  @brief Set FlurryMessaging delegate for optional callback on push events.
 *  @since 8.4.4
 *
 * @code
 *  - (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 [Flurry setAutoIntegrationForMessaging];
 // If self implements protocol, FlurryMessagingDelegate
 [Flurry setMessagingDelegate:self withCallbackQueue:queue];
 // ....
 }
 * @endcode
 *
 */
+(void) setMessagingDelegate:(nonnull id<FlurryMessagingDelegate>)delegate withCallbackQueue:(nonnull dispatch_queue_t)messagingCallbackQueue;
@end
#endif
