//
//  FlurryAdView.h
//  Flurry iOS Advertising
//
//  Copyright 2009-2014 Flurry, Inc. All rights reserved.
//
//	Methods in this header file are for use by Flurry Publishers

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "FlurryAdInterstitialDelegate.h"
#import "FlurryAdTargeting.h"

/*!
 *  @brief Provides all available methods for displaying interstitial ads.
 *
 *  Set of methods that allow publishers to configure, target, and deliver ads to their customers.
 *
 *  @note This class depends on Flurry.h.
 *  For information on how to use Flurry's Ads SDK to
 *  attract high-quality users and monetize your user base see <a href="https://developer.yahoo.com/flurry/docs/howtos">Support Center - Publishers</a>.
 *
 *  @author 2009 - 2014 Flurry, Inc. All Rights Reserved.
 *  @version 6.0.0
 *
 */
@interface FlurryAdInterstitial : NSObject

/*!
 *  @brief Read only property that can be used to retrieve the ad space that was passed into an initializer routine. An Ad Space is an area within your app that is designated to display ads. Ad spaces need to be setup and configured on the Flurry developer portal.
 *  @since 6.0.0
 *
 *  @return The ad space string value.
 */
@property (nonatomic, copy, readonly) NSString *space;

/*!
 *  @brief This property should be used for ad targeting based on parameters such as location, targeting kewords, age and gender
 *
 *
 *  @since 6.0.0
 *
 *  @see FlurryAdTargeting for details.
 *
 *  @return The ad targeting that was orignally set or nil if never set.
 *
 */
@property (nonatomic, strong) FlurryAdTargeting *targeting;

/*!
 *  @brief Sets the object to receive various notifications of various ad actions.
 *  @since 6.0.0
 *
 *  This method allows you to register an object that will receive
 *  notifications at different phases of interstitial ad serving.
 *
 *  @see FlurryAdInterstitialDelegate for details on delegates available.
 *
 *  @code
    -(void) fetchInterstitialAd;
    {
        FlurryAdInterstitial* interstitialAd = [[FlurryAdInterstitial alloc] initWithSpace:adSpace];
        interstitialAd.adDelegate = self;
        [interstitialAd fetchAd];
    }
 *  @endcode
 *
 *  @return The ad delegate object if set earlier, or nil if never set
 *
 */
@property (nonatomic, weak) id<FlurryAdInterstitialDelegate> adDelegate;


/*!
 *  @brief Returns if an ad is currently ready to display for this ad object
 *  @since 6.0.0
 *
 *  This method will verify if an ad is currently available for this ad object.
 *  If an ad is not available, you can call #fetchAd to load a new ad.
 *
 *  @note If this method returns YES, an ad will be available. \n
 *  It is advisable to listen to the delegate FlurryAdInterstitialDelegate#adInterstitial:adError:errorDescription:
 *  to get notified if the ad fetch request fails.
 *
 *  @see #fetchAd for details on retrieving an ad.\n
 *
 *  @code

    @property FlurryAdInterstitial* adInterstitial
 
    - (void) showInterstitialIfReady
    {
        if ([self.adInterstitial ready] == YES)
        {
            [self.adInterstitial presentWithViewController:self];
        }
        else
        {
            self.adInterstitial = [[FlurryAdInterstitial alloc] initWithSpace:@"MAIN_VIEW_INTERSTITIAL"];
            self.adInterstitial.adDelegate = self;
            [self.adInterstitial fetchAd];
        }
    }
 *  @endcode
 *
 *  @return YES/NO to indicate if an ad is ready to be displayed.
 */
@property (nonatomic, readonly) BOOL ready;

/*!
 *  @brief Initialize the interstitial ad object
 *  @since 6.0.0
 *
 *  This method initializes the ad object and gets it ready to fetch and serve an interstitial ad.
 *
 *  @code
    FlurryAdInterstitial* FlurryAdInterstitial = [[FlurryAdInterstitial alloc] initWithSpace:@"INTERSTITIAL_AD"];
    @endcode
 *
 *  @param space represents the placement of the ad in your app.
 *  @c e.g. @c @"GAME_END_SCREEN_INTERSTITIAL_AD".
 *
 */
- (id)   initWithSpace:(NSString *)space;

/*!
 *  @brief Retrieves an ad for this object using the adspace specified in the initializer routine.
 *  @since 6.0.0
 *
 *  This method will attempt to retrieve ads for this object's ad space from the Flurry server.
 *
 *  @see \n
 *  FlurryAdInterstitialDelegate#adInterstitialDidFetchAd: for details on the notification of ads being received.\n
 *  FlurryAdInterstitialDelegate#adInterstitial:adError:errorDescription: for details on notification of failure to receive ads from this request.\n
 *  #presentWithViewController: for details on displaying an available ad.
 *
 *  @code
 
    @property (strong) FlurryAdInterstitial* adInterstitial;
 
    - (void)fetchAd
    {
        adInterstitial = [[FlurryAdInterstitial alloc] initWithSpace:@"MAIN_VIEW_INTERSTITIAL"];
        adInterstitial.adDelegate = self;
        [adInterstitial fetchAd];
    }
 
    // Show whenever delegate is invoked
    - (void) adInterstitialDidFetchAd:(FlurryAdInterstitial *) adInterstitial {
        // Received Ad
        [adInterstitial presentWithViewController:self];
    }
 
    // Alternatively, try to display at a certain point in the app
    - (void) levelComplete {
        if([self.adInterstitial ready]) {
            [self.adInterstitial presentWithViewController:self];
        }
    }
 *  @endcode
 *
 */
- (void) fetchAd;

/*!
 *  @brief Display the ad associated with this ad object
 *  @since 6.0.0
 *
 *  This method will display an ad if one is ready for display on the device.
 *
 *  @see
 *  #fetchAd for details on retrieving an ad.\n
 *  #ready: for details on verifying is an ad is ready to be displayed. \n
 *  FlurryAdInterstitialDelegate#adInterstitial:adError:errorDescription: for details on notification of error in rendering an ad for this request.
 *
 *  @code
    - (void)showFullscreenAd
    {
        if([self.adInterstitial ready]) {
            [self.adInterstitial presentWithViewController:self];
        }
    }
 *  @endcode
 *
 *  @param presentingViewController The viewController to show the fullscreen ad modally.
 */
- (void) presentWithViewController: (UIViewController *) presentingViewController;


@end
