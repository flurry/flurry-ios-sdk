//
//  FlurryAdDelegate.h
//  Flurry iOS Advertising
//
//  Copyright 2010 - 2015 Flurry, Inc. All rights reserved.
//
//  Methods in this header file are for use with Flurry
//

#import <UIKit/UIKit.h>
#import "FlurryAdError.h"


@class FlurryAdBanner;

/*!
 *  @brief Provides all available delegates for receiving callbacks related to Banner Ad Serving.
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
@protocol FlurryAdBannerDelegate <NSObject>

@optional

/*!
 *  @brief Invoked when an ad is received for the specified @c bannerAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been received and is available for display.
 *
 *  @see FlurryAdBanner#fetchAdForFrame: for details on the method that will invoke this delegate.
 *
 *  @param bannerAd The ad object that has successfully fetched an ad.
 */
- (void) adBannerDidFetchAd:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when the banner ad is rendered.
 *  @since 6.0.0
 *
 *  This method informs the user an ad was retrieved, and successful in displaying to the user.
 *
 *  @see \n
 *  FlurryAdBanner#displayAdInView:viewControllerForPresentation: for details on the method that will invoke this delegate. \n
 *  FlurryAdBanner#fetchAndDisplayAdInView:viewControllerForPresentation: for details on the method that will invoke this delegate.
 *
 *  @param bannerAd The ad object that rendered successfully.
 *
 */
- (void) adBannerDidRender:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when the specified banner ad object is about to present a full screen.
 *  @since 6.0.0
 *
 *  @param bannerAd The banner ad object that is associated with the full screen that is about to present a fullscreen.
 *
 */
- (void) adBannerWillPresentFullscreen:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when the ad has been selected that will take the user out of the app.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked and the user is about to be taken outside the app.
 *
 *  @param bannerAd The ad object that received the click.
 *
 */
- (void) adBannerWillLeaveApplication:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad will be removed.
 *  @since 6.0.0
 *
 *  @param bannerAd The banner ad object that is associated with the full screen that is about to be dismissed.
 *
 */
- (void) adBannerWillDismissFullscreen:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad has been removed.
 *  @since 6.0.0
 *
 *  @param bannerAd The banner ad object that is associated with the full screen that that has been dismissed.
 *
 */
- (void) adBannerDidDismissFullscreen:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Informational callback invoked when an ad is clicked for the specified @c bannerAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked. This should not be used to adjust state of an app. It is only intended for informational purposes.
 *
 *  @param bannerAd The ad object that received the click.
 *
 */
- (void) adBannerDidReceiveClick:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Invoked when a video finishes playing
 *  @since 6.0.0
 *
 *  This method informs the app that a video associated with this ad has finished playing. Note the SDK
 *  will launch a full screen video player for banners that present a video when they receive a click.
 *
 *  @param bannerAd The banner ad object that played the video and finished playing the video.
 *
 */
- (void) adBannerVideoDidFinish:(FlurryAdBanner*)bannerAd;

/*!
 *  @brief Informational callback invoked when there is an ad error
 *  @since 6.0
 *
 *  @see FlurryAdError for the possible error reasons.
 *
 *  @param bannerAd The banner ad object associated with the error
 *  @param adError an enum that specifies the reason for the error.
 *  @param errorDescription An error object that gives additional information on the cause of the ad error.
 *
 */
- (void) adBanner:(FlurryAdBanner*) bannerAd adError:(FlurryAdError) adError errorDescription:(NSError*) errorDescription;

@end
