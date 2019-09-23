//
//  FConfig.h
//  Flurry
//
//  Created by  Mark Cwalinski on 1/18/17.
//  Copyright © 2017 Flurry. All rights reserved.
//

#import <Foundation/Foundation.h>
@class FConfigUserBuilder;
@class FConfigBuilder;



/*!
 * @brief Provides a protocol for subscribed observers of the FConfig class to listen to
 * @since 8.1.0
 *
 * A set of actions that allow an observing class to take action based on certain events,
 * such as fetch operations or activations.
 *
 * @note This is an observer pattern and is not a delegate.  This means that multiple classes
 * can observe after registering with the FConfig#registerObserver method.
 */
@protocol FConfigObserver <NSObject>

@optional
/*!
 * @brief Notification of a fetch completion
 * @since 8.1.0
 *
 * The method that is called when a fetch is iniated and completes with a change.
 */
- (void) fetchComplete;

/*!
 * @brief Notification of a fetch completion with no changes
 * @since 8.1.0
 *
 * The method that is called with a fetch completes but no changes are made.
 */
- (void) fetchCompleteNoChange;

/*!
 * @brief Notification that a fetch was made but failed
 * @since 8.1.0
 * 
 * The method that is called when a fetch is initiated but fails for some reason.
 */
- (void) fetchFail;

/*!
 * @brief Notification that an activation has occurred
 * @since 8.1.0
 *
 * The method that is called when an activation is done.  This is important in the 
 * "greedy" case of activation.  An object may greedily call for activation and other
 * objects may need to know to modify their state (or ignore this activation) in order
 * to maintain a consistent user experience.
 */
- (void) activationComplete;

@end

/*!
 * @brief FConfig allows for control of server-side config within the app via the Flurry SDK
 * @since 8.1.0
 *
 * FConfig is a config service that seeks to allow app developers to have configuration services
 * over their app.  For example, a developer could bake in a green theme for the day of the Saint
 * Patrick's Holiday.  Further, a developer could roll out, into production, the ability for the
 * developers to test real-world changes while only exposing those changes to the developers.
 *
 * The Flurry Config service (FConfig) is designed to provide the least disruptive experience to users
 * possible.  In light of this goal, fetched configs will only be applied when the app leaves
 * memory and relaunches.  This will guarantee a continuity of the user experience that is not
 * jarring if a new config gets rolled out mid-session.
 *
 * In this basic useage all that is necessary is to call fetch on the shared instance.  The code
 * may then check feature flags with the assurance that the UI experience will be consistent.
 *
 * However, it is often the case that a devloper would like to be more aggressive with the application
 * of a config.  To satisfy that need the FConfig service supplies an observer that an object may
 * subscribe to.
 *
 * As events happen, such as succesful fetching or the activation of a config, the object that is
 * observing may take action.  This allows the developer to have more control over the configuration
 * service if it is necessary.
 */
@interface FConfig : NSObject

/*!
 * @brief get the shared instance of the FConfig singleton
 * @since 8.1.0
 * 
 * Gets or initializes the shared instance of the FConfig.  On initialization, FConfig will 
 * internally call activate() and activate
 * the last fetched config from the last run of the app.
 *
 */

+ (nonnull FConfig *)sharedInstance;

/*!
 * @brief Fetches the newest config from the server (if one is available).
 * @since 8.1.0
 * 
 * Fetch the most recent config from the server for this client.  Upon completion
 * of the fetch, the FConfigObserver will be called to make note of the result.
 *
 * There is a built in throttle on the number of times this call can be made.
 * That throttle is based on a response from the server.
 *
 * It is important to know that fetching does not activate a new config.
 *
 * @see FConfig#FConfigObserver for details on the observer
 */
- (void)fetchConfig;

/*!
 * @brief Activate the last staged commit if it has not already been activated
 * @since 8.1.0
 *
 * Aggressively activate the latest config if it has not been activated.  Unlike the typical
 * operation where a fetched config is only activated after the next session, this will put
 * the last fetched config directly into use.
 *
 * When an activation occurs, anyone listening to the FConfigObserver will be notified
 * of the activation.
 * 
 * @see FConfig#FConfigObserver for more details on the observer
 */
- (BOOL)activateConfig;

/*!
 * @brief Get the string value for the given key
 * @since 8.1.0
 *
 * Get the string value for the given key.  The config service will do its best to handle
 * the string appropriately, but all attempts should be made to validate that the returned
 * value is, indeed, a fully formed string.  If no value is provided in the config the
 * default value will be chosen.
 *
 * @param key the key for the desired string
 * @param def the value to fall back on if no config value exists
 */
- (NSString * _Nullable)getStringForKey:(nonnull NSString *)key
                            withDefault:(NSString * _Nullable)def;

/*!
 * @brief Get the boolean value for the given key
 * @since 8.1.0
 *
 * Get the boolean value for the given key.  The config service will send back NO/FALSE
 * for anything but a YES/TRUE value from the backend.  If no value is provided in the config the
 * default value will be chosen.
 *
 * @param key the key for the destired boolean value
 * @param def the value to fall back on if no config value exists
 */
- (BOOL)getBoolForKey:(nonnull NSString *)key
          withDefault:(BOOL)def;

/*!
 * @brief Get the number value for the given key
 * @since 8.1.0
 *
 * Get the number value for the given key.  The config service will do its best to handle
 * the number appropriately, but all attempts should be made to validate that the returned
 * value is, indeed, a fully formed number.  If no value is provided in the config the
 * default value will be chosen.
 *
 * @param key the key for the desired number
 * @param def the value to fall back on if no config value exists
 */
- (NSNumber * _Nullable)getNumberForKey:(nonnull NSString *)key
                            withDefault:(NSNumber * _Nullable)def;

/*!
 * @brief Register as an observer with the provided execution queue
 * @since 8.1.0
 *
 * An object may register as an observer in order to be notified of events within the
 * config service.  In order to prevent possible execution problems the developer
 * should provide an execution queue that is safe for the config service to execute on.
 *
 * @param observer the observing object
 * @param queue the execution queue on which the observer callbacks will be executed
 */
- (void)registerObserver:(id _Nonnull)observer withExecutionQueue:(dispatch_queue_t _Nonnull)queue;

@end
