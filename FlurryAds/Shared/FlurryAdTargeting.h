//
//  FlurryAdTargeting.h
//  Flurry iOS Advertising
//
//  Copyright 2009-2014 Flurry, Inc. All rights reserved.
//
//	Methods in this header file are for use by Flurry Publishers

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class CLLocation;

/*!
 *  @brief Enum for setting gender information
 *  @since 6.0.0
 *
 */
typedef enum {
    FL_MALE   = 1,
    FL_FEMALE = 2
} FlGender;

/*!
 *  @brief Provides available methods for targeting.
 *
 *  Set of methods that allow publishers to provide targeting information for a device.
 *
 *  @note This object is meant to be used with the FlurryAds object APIs. For static APIs
 *  please continue to use the equivalent static APIs
 *
 *  @see The APIs for ad targeting with the static Ads APIs \n
 *   Flurry#setLatitude:longitude:horizontalAccuracy:verticalAccuracy: \n
 *   FlurryAds#setKeywordsForTargeting: \n
 *   Flurry#setAge: \n
 *   Flurry#setGender: \n
 *   FlurryAds#setUserCookies: \n
 *
 *  @author 2009 - 2014 Flurry, Inc. All Rights Reserved.
 *  @version 6.0.0
 *
 */
@interface FlurryAdTargeting : NSObject


+ (FlurryAdTargeting *) targeting;

/*!
 *  @brief Set the location for Ad Targeting
 *  @since 6.0
 *
 *  Use information from the CLLocationManager to specify the location for Ad Targeting. Flurry does not
 *  automatically track this information or include the CLLocation framework.
 *
 *  @note The location information set here is not persisted on the user's device.
 *  Regardless of accuracy specified, the Flurry SDK will only report location at city level or higher.
 *  Location is aggregated across all users of your app and not available on a per user basis.
 *  This information should only be captured if it is germaine to the use of your app.
 *
 *  @code
 
    CLLocationManager *locationManager = [[CLLocationManager alloc] init];
    [locationManager startUpdatingLocation];
 
 *  @endcode
 *
 *  After starting the location manager, you can set the location with FlurryAdTargeting. You can implement
 *  CLLocationManagerDelegate to be aware of when the location is updated. Below is an example
 *  of how to use this method, after you have recieved a location update from the locationManager.
 *
 *  @code
    -(void) locationManager: (CLLocationManager *)locationManager 
        didUpdateToLocation: (CLLocation *) newLocation
    {
        FlurryAdTargeting* adTargeting = [FlurryAdTargeting targeting];
        adTargeting.location = locationManager.location;
    }
 *  @endcode
 *  @param location A CLLocation object containing latitude and longitude.
 *
 */
@property (nonatomic, retain) CLLocation* location;

/*!
 *  @brief Sets a dictionary of key/value pairs, which will be transmitted to Flurry servers when a user clicks on an ad.
 *  @since 6.0.0
 *
 *  UserCookies allow the developer to specify information on a user executing an ad action. On each ad click the UserCookies are transmitted to the Flurry servers. The UserCookie key/value pairs will be transmitted back to the developer via the app callback if one is set. This is useful for rewarded inventory, to identify which of your users should be rewarded when a reward callback is sent.
 *
 *  @note Calling this method with a nil or empty dictionary will clear any previously set user cookies. Calling this method a second time with a valid dictionary will replace the previous entries.
 *
 *  @code
 *  - (void) showInterstitialAddUserCookies
    {
        NSDictionary *cookies =
        [NSDictionary dictionaryWithObjectsAndKeys:@"xyz123", // Parameter Value
                                                    @"UserCharacterId", // Parameter Name
                                                    nil];
        FlurryAdInterstitial* adInterstitial = [[FlurryAdInterstitial alloc] initWithSpace:@"MAIN_SCREEN_INTERSTITIAL"];
        FlurryAdTargeting* adTargeting = [FlurryAdTargeting targeting];
        adTargeting.userCookies = cookies;
        adInterstitial.adTargeting = adTargeting;
        [adInterstitial fetchAd];
    }
 *  @endcode
 *
 *  @param userCookies The information about the user executing ad actions. Note: do not transmit personally identifiable information in the user cookies.
 */
@property (nonatomic, retain) NSDictionary *userCookies;

/*!
 *  @brief Sets a dictionary of key/value pairs, which will be transmitted to Flurry servers when an ad is requested.
 *  @since 6.0.0
 *
 *  Keywords allow the developer to specify information on a user executing an ad action for the purposes of targeting.  These keywords are transmitted to the Flurry servers on this ad object's ad request. If corresponding keywords are matched on the ad server, a subset of targeted ads will be delivered. This allows partners to supply information they track internally, which is not available to Flurry's targeting system.
 *
 *  @note Calling this method with a nil or empty dictionary will clear any previously passed keywords. Calling this method a second time with a valid dictionary will replace the previous entries.
 *
 *  @code
    - (void) showInterstitialAddKeywords
    {
        NSDictionary *keywords =
        [NSDictionary dictionaryWithObjectsAndKeys:@"UserParameterValue", // Parameter Value
                                                    @"UserParameterName", // Parameter Name
                                                    nil];
        FlurryAdInterstitial* adInterstitial = [[FlurryAdInterstitial alloc] initWithSpace:@"MAIN_SCREEN_INTERSTITIAL"];
        FlurryAdTargeting* adTargeting = [FlurryAdTargeting targeting];
        adTargeting.keywords = keywords;
        adInterstitial.adTargeting = adTargeting;
        [adInterstitial fetchAd];
    }
 *  @endcode
 *
 *  @param keywords The information about the user to be used in targeting an ad. Note: do not transmit personally identifiable information in keywords.
 */
@property (nonatomic, retain) NSDictionary *keywords;


@property (nonatomic, assign) BOOL testAdsEnabled;



@end
