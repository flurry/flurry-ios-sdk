//
//  FlurryAdInterstitialDelegate.h
//  Flurry
//
//  Copyright 2010 - 2013 Flurry, Inc. All rights reserved.
//
//  Methods in this header file are for use with Flurry
//

#import <UIKit/UIKit.h>
#import "FlurryAdError.h"

@class FlurryAdInterstitial;

/*!
 *  @brief Provides all available delegates for receiving callbacks related to Ad Serving.
 *
 *  Set of methods that allow developers to manage and take actions within
 *  different phases of App ad display.
 *
 *  @note This class serves as a delegate for FlurryAds. \n
 *  For additional information on how to use Flurry's Ads SDK to
 *  attract high-quality users and monetize your user base see <a href="http://wiki.flurry.com/index.php?title=Publisher">Support Center - Publisher</a>.
 *  @author 2010 - 2014 Flurry, Inc. All Rights Reserved.
 *  @version 6.0.0
 *
 */
@protocol FlurryAdInterstitialDelegate <NSObject>

@optional

/*!
 *  @brief Invoked when an ad is received for the specified @c interstitialAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been received and is available for display.
 *
 *  @see FlurryAdInterstitial#fetchAd for details on the method that will invoke this delegate.
 *
 *  @param interstitialAd The ad object that has successfully fetched an ad.
 */
- (void) adInterstitialDidFetchAd:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Invoked when the interstitial ad is rendered.
 *  @since 6.0.0
 *
 *  This method informs the user an ad was retrieved, and successful in displaying to the user.
 *
 *  @see \n
 *  FlurryAdInterstitial#presentWithViewController: for details on the method that will invoke this delegate. \n
 *
 *  @param interstitialAd The ad object that rendered successfully.
 *
 */
- (void) adInterstitialDidRender:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad will present on the screen.
 *  @since 6.0.0
 *
 *  @param interstitialAd The interstitial ad object that is associated with the full screen that will present.
 *
 */
- (void) adInterstitialWillPresent:(FlurryAdInterstitial*)interstitialAd;


/*!
 *  @brief Invoked when the ad has been selected that will take the user out of the app.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked and the user is about to be taken outside the app.
 *
 *  @param interstitialAd The ad object that received the click.
 *
 */
- (void) adInterstitialWillLeaveApplication:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad will be removed.
 *  @since 6.0.0
 *
 *  @param interstitialAd The interstitial ad object that is associated with the full screen that will be dismissed.
 *
 */
- (void) adInterstitialWillDismiss:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad has been removed.
 *  @since 6.0.0
 *
 *  @param interstitialAd The interstitial ad object that is associated with the full screen that has been dismissed.
 *
 */
- (void) adInterstitialDidDismiss:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Informational callback invoked when an ad is clicked for the specified @c interstitialAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked. This should not be used to adjust state of an app. It is only intended for informational purposes.
 *
 *  @param interstitialAd The ad object that received the click.
 *
 */
- (void) adInterstitialDidReceiveClick:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Invoked when a video finishes playing
 *  @since 6.0.0
 *
 *  This method informs the app that a video associated with this ad has finished playing.
 *
 *  @param interstitialAd The interstitial ad object that played the video and finished playing the video.
 *
 */
- (void) adInterstitialVideoDidFinish:(FlurryAdInterstitial*)interstitialAd;

/*!
 *  @brief Informational callback invoked when there is an ad error
 *  @since 6.0
 *
 *  @see FlurryAdError for the possible error reasons.
 *
 *  @param interstitialAd The interstitial ad object associated with the error
 *  @param adError an enum that gives the reason for the error.
 *  @param errorDescription An error object that gives additional information on the cause of the ad error.
 *
 */
- (void) adInterstitial:(FlurryAdInterstitial*) interstitialAd adError:(FlurryAdError) adError errorDescription:(NSError*) errorDescription;

@end
