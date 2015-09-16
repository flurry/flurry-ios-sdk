//
//  FlurryAdNativeDelegate.h
//  Flurry
//
//  Copyright 2010 - 2014 Flurry, Inc. All rights reserved.
//
//  Methods in this header file are for use with FlurryAds library
//

#import <UIKit/UIKit.h>
#import "FlurryAdError.h"

@class FlurryAdNative;

/*!
 *  @brief Provides all available delegates for receiving callbacks related to Native Ad Serving.
 *  
 *  Set of methods that allow developers to manage and take actions within
 *  different phases of App ad display.
 *  
 *  @note This class serves as a delegate for FlurryAdNative. \n
 *  For additional information on how to use Flurry's Ads SDK to
 *  attract high-quality users and monetize your user base see <a href="http://wiki.flurry.com/index.php?title=Publisher">Support Center - Publisher</a>.
 *  @author 2010 - 2014 Flurry, Inc. All Rights Reserved.
 *  @version 6.0.0
 * 
 */
@protocol FlurryAdNativeDelegate <NSObject>

@optional

/*!
 *  @brief Invoked when an ad is received for the specified @c nativeAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been received and is available for display.
 *
 *  @see FlurryAdNative#fetchAd for details on the method that will invoke this delegate.
 *
 *  @param nativeAd The ad object that has successfully fetched an ad.
 */
- (void) adNativeDidFetchAd:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Invoked when the specified native ad object is about to present a full screen.
 *  @since 6.0.0
 *
 *  @param nativeAd The native ad object that is associated with the full screen that is about to present a fullscreen.
 *
 */
- (void) adNativeWillPresent:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Invoked when the ad has been selected that will take the user out of the app.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked and the user is about to be taken outside the app.
 *
 *  @param nativeAd The native ad object that received the click.
 *
 */
- (void) adNativeWillLeaveApplication:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad will be removed.
 *  @since 6.0.0
 *
 *  @param nativeAd The native ad object that is associated with the full screen that is about to be dismissed.
 *
 */
- (void) adNativeWillDismiss:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Invoked when a fullscreen associated with the specified ad has been removed.
 *  @since 6.0.0
 *
 *  @param nativeAd The native ad object that is associated with the full screen that that has been dismissed.
 *
 */
- (void) adNativeDidDismiss:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Informational callback invoked when an ad is clicked for the specified @c nativeAd object.
 *  @since 6.0.0
 *
 *  This method informs the app that an ad has been clicked. This should not be used to adjust state of an app. It is only intended for informational purposes.
 *
 *  @param nativeAd The ad object that received the click.
 *
 */
- (void) adNativeDidReceiveClick:(FlurryAdNative*) nativeAd;

/*!
 *  @brief Informational callback invoked when there is an ad error
 *  @since 6.0
 *
 *  @see FlurryAdError for the possible error reasons.
 *
 *  @param nativeAd The native ad object associated with the error
 *  @param adError an enum that specifies the reason for the error.
 *  @param errorDescription An error object that gives additional information on the cause of the ad error.
 *
 */
- (void) adNative:(FlurryAdNative*) nativeAd adError:(FlurryAdError) adError errorDescription:(NSError*) errorDescription;

/*!
 *  @brief Informational callback invoked when an ad impression is logged
 *  @since 6.6.0
 *
 *  @param nativeAd The native ad object associated with the impressions
 *
 */
- (void) adNativeDidLogImpression:(FlurryAdNative*) nativeAd;


@end
