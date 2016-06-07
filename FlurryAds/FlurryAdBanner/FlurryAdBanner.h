//
//  FlurryAdBanner.h
//  Flurry iOS Advertising
//
//  Copyright 2009-2014 Flurry, Inc. All rights reserved.
//
//	Methods in this header file are for use by Flurry Publishers


#import <UIKit/UIKit.h>
#import "FlurryAdTargeting.h"
#import "FlurryAdBannerDelegate.h"


/*!
 *  @brief Provides all available methods for displaying banner ads.
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
@interface FlurryAdBanner : NSObject 

/*!
 *  @brief Read only property that can be used to retrieve the ad space that was
 *  passed into an initializer routine. An Ad Space is an area within your app that is designated to display ads.
 *  Ad spaces need to be setup and configured on the Flurry developer portal.
 *  @since 6.0.0
 *
 *  @return The ad space string value.
 */
@property (nonatomic, copy) NSString* space;


/*!
 *  @brief This property should be used for ad targeting based on parameters such as
 *  location, targeting kewords and user cookies.
 *
 *
 *  @since 6.0.0
 *
 *  @see FlurryAdTargeting for details.
 *
 *  @param  targeting The ad targeting object.
 *
 *  @return The ad targeting that was orignally set or nil if never set.
 *
 */
@property (nonatomic, strong) FlurryAdTargeting* targeting;

/*!
 *  @brief Sets the object to receive various delegate methods.
 *  @since 6.0.0
 *
 *  This method allows you to register an object that will receive
 *  notifications at different phases of banner ad serving.
 *
 *  @see FlurryAdBannerDelegate for details on delegates available.
 *
 *  @code
 *   -(void) fetchBannerAd;
    {
        FlurryAdBanner* bannerAd = [[FlurryAdBanner alloc] initWithSpace:adSpace];
        bannerAd.adDelegate = self;
        [bannerAd fetchAndDisplayAdInView:self.view viewControllerForPresentation:self];
    }
 *  @endcode
 *
 *  @param delegate The object to receive notifications of various ad actions.
 *
 */
@property (nonatomic, weak) id<FlurryAdBannerDelegate> adDelegate;


/*!
 *  @brief Returns if an ad is currently ready to display for this ad object
 *  @since 6.0.0
 *
 *  This method will verify if an ad is currently available for this ad object.
 *  If an ad is not available, you can call #fetchAdForFrame: to load a new ad.
 *
 *  @note If this method returns YES, an ad will be available and the assetList will be populated.
 *  It is advisable to listen to the delegate FlurryAdBannerDelegate#adBanner:adError:errorDescription:
 *  to get notified if the ad fetch request fails.
 *
 *  @see #fetchAdForFrame: for details on retrieving an ad.
 *
 *  @code

    @property (strong) FlurryAdBanner* banner;
 
    - (void) showBannerIfReady
    {
        if ([self.adBanner ready] == YES)
        {
            [self.adBanner displayAdInView:self.view viewControllerForPresentation:self];
        }
        else
        {
            self.adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_AD"];
            self.adBanner.adDelegate = self;
            [self.adBanner fetchAdForFrame:self.view.frame];
        }
    }

 *  @endcode
 *
 *  @return YES/NO to indicate if an ad is ready to be displayed.
 */
@property (nonatomic, readonly) BOOL ready;

/*!
 *  @brief Initialize the banner ad object
 *  @since 6.0.0
 *
 *  This method initializes the ad object and gets it ready to fetch and serve a banner ad.
 *
 *  @see #space for more description on the input parameter
 *
 *  @code
 
    FlurryAdBanner* bannerAd = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_AD"];
 
    @endcode
 *
 *  @param space represents the placement of the ad in your app.
 *  @c e.g. @"MAIN_VIEW_BOTTOM_BANNER_AD".
 *
 *
 */
- (id) initWithSpace:(NSString *)space;

/*!
 *  @brief Retrieves an ad for this object using the adspace specified in the initializer routine.
 *  @since 6.0.0
 *
 *  This method will attempt to retrieve ads for this object's ad space from the Flurry server.
 *
 *  @see
 *  FlurryAdBannerDelegate#adBannerDidFetchAd: for details on the notification of ads being received.\n
 *  FlurryAdBannerDelegate#adBanner:adError:errorDescription: for details on notification of failure to receive ads from this request.\n
 *  #displayAdInView:viewControllerForPresentation: for details on displaying an available ad.
 *
 *  @code
 
    - (void)fetchAd
    {
        FlurryAdBanner* adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        adBanner.adDelegate = self;
        [adBanner fetchAdForFrame:self.view.frame];
    }
 
    // Show whenever delegate is invoked
    - (void) adBannerDidFetchAd:(FlurryAdBanner *) adBanner 
    {
        // Received Ad
        [adBanner displayAdInView:self.view viewControllerForPresentation:self];
    }
 
    @property (strong) FlurryAdBanner* adBanner;
 
    // Alternatively, try to display at a certain point in the app
    - (void) levelComplete 
    {
        self.adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        self.adBanner.adDelegate = self;
        [self.adBanner fetchAndDisplayAdInView:self.view viewControllerForPresentation:self];
    }
 *  @endcode
 * 
 *  @param frame The frame of the view within which the banner will be displayed
 *
 */
- (void) fetchAdForFrame:(CGRect)frame;

/*!
 *  @brief Display an ad for this object that has been fetched earlier using #fetchAdForFrame:
 *  @since 6.0.0
 *
 *  This method will attempt to display the ad associated with the ad object.
 *
 *  @see 
 *  FlurryAdBannerDelegate#adBanner:adError:errorDescription: for details on notification of failure to display ad.
 *
 *  @code
 
    @property (strong) FlurryAdBanner* adBanner;
 
    - (void)fetchAd
    {
        FlurryAdBanner* adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        adBanner.adDelegate = self;
        [adBanner fetchAdForFrame:self.view.frame];
    }
 
    // Show whenever delegate is invoked
    - (void) adBannerDidFetchAd:(FlurryAdBanner *) adBanner
    {
        // Received Ad
        [adBanner displayAdInView:self.view viewControllerForPresentation:self];
    }
 
    @property (strong) FlurryAdBanner* adBanner;
 
    // Alternatively, try to display at a certain point in the app
    - (void) levelComplete
    {
        self.adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        self.adBanner.adDelegate = self;
        [self.adBanner fetchAndDisplayAdInView:self.view viewControllerForPresentation:self];
    }
    @endcode
 *
 *  @param view The UIView within which the banner will be displayed
 *  @param viewController The UIViewController to use for displaying a fullscreen when the banner is clicked.
 *
 */
- (void) displayAdInView:(UIView *)view viewControllerForPresentation:(UIViewController *)viewController;

/*!
 *  @brief Fetch and then display an ad for this object that has been fetched earlier using #fetchAdForFrame
 *  @since 6.0.0
 *
 *  This method will attempt to fetch a banner ad from the FlurryAd server and display it within the view passed into this API.
 *
 *  @see \n
 *  FlurryAdBannerDelegate#adBannerDidFetchAd: for details on the notification of ads being received.\n
 *  FlurryAdBannerDelegate#adBanner:adError:errorDescription: for details on notification of failure to display ad.\n
 *
 *  @code
 
    @property (strong) FlurryAdBanner* adBanner;
 
    - (void)fetchAd
    {
        FlurryAdBanner* adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        adBanner.adDelegate = self;
        [adBanner fetchAdForFrame:self.view.frame];
    }
 
    // Show whenever delegate is invoked
    - (void) adBannerDidFetchAd:(FlurryAdBanner *) adBanner
    {
        // Received Ad
        [adBanner displayAdInView:self.view viewControllerForPresentation:self];
    }
 
    @property (strong) FlurryAdBanner* adBanner;
 
    // Alternatively, try to display at a certain point in the app
    - (void) levelComplete
    {
        self.adBanner = [[FlurryAdBanner alloc] initWithSpace:@"BANNER_BOTTOM"];
        self.adBanner.adDelegate = self;
        [self.adBanner fetchAndDisplayAdInView:self.view viewControllerForPresentation:self];
    }
    @endcode
 *
 *  @param view The UIView within which the banner will be displayed
 *  @param viewController The UIViewController to use for displaying a fullscreen when the banner is clicked.
 *
 */
- (void) fetchAndDisplayAdInView:(UIView *)view viewControllerForPresentation:(UIViewController *)viewController;

@end