//
//  FlurryTumblrAPI.h
//  Flurry iOS Tumblr Agent
//
//  Copyright 2009-2015 Flurry, Inc. All rights reserved.
//
//	Methods in this header file are for use with Flurry Tumblr Syndication

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FlurryTumblrDelegate.h"

@protocol IFlurryTumblrShareParameters <NSObject>

@property (nonatomic, retain) NSString*     iOSDeepLink;
@property (nonatomic, retain) NSString*     androidDeepLink;
@property (nonatomic, retain) NSString*     webLink;

@end

@interface FlurryTextShareParameters : NSObject <IFlurryTumblrShareParameters>

@property (nonatomic, strong) NSString* text;
@property (nonatomic, strong) NSString* title;

@end


@interface FlurryImageShareParameters : NSObject <IFlurryTumblrShareParameters>

@property (nonatomic, strong) NSString* imageURL;
@property (nonatomic, strong) NSString* imageCaption;

@end


@interface FlurryTumblr : NSObject

/*!
 *  @brief Set the consumer key and secret
 *  @since 7.0.0
 *  @deprecated 8.0.0
 *
 *  Set your app’s consumer key and secret prior to making any calls to
 *  FlurryTumblr
 *
 *  @code
 *  - (void)applicationDidFinishLaunching:(UIApplication *)application
 {
 // set the consumer key and secret
 [FlurryTumblr setConsumerKey:@”Your Consumer Key” consumerSecret:@”Your Consumer Secret”];
 }
 
 @endcode
 *
 */
+ (void) setConsumerKey: (NSString*) consumerKey consumerSecret: (NSString*) consumerSecret __attribute__ ((deprecated));

/*!
 *  @brief Set the consumer key , consumer secret and consume urlScheme(required for SafariViewController login control)
 *  @since 7.5.0
 *  @deprecated 8.0.0
 *
 *  Set your app’s consumer key and secret prior to making any calls to FlurryTumblr
 *  The URL scheme is the app's custom URL scheme.  
 *  Custom URL scheme is typically added to your app's plist as shown below:
    <array>
        <dict>
            <key>CFBundleURLName</key>
                <string>com.yahoo.Tumblr-Publisher</string>
            <key>CFBundleURLSchemes</key>
            <array>
                <string>Tumblr-Publisher</string>
            </array>
        </dict>
    </array>
 *
 *  @note As the app can have multiple custom URL schemes, FlurryTumblr does not read the custom URL
 *  scheme from the app's plist and requires that the app pass the URL scheme it wishes to use with 
 *  FlurryTumblr to the SDK.
 *  The app needs to call this API and then call handleURL as noted below to enable FlurryTumblr to 
 *  use SafariViewController to authenticate the user.
 *
 *  @code
    - (void)applicationDidFinishLaunching:(UIApplication *)application
    {
        // set the consumer key and secret . Example consumerScheme = @"Tumblr-Publisher"
        [FlurryTumblr setConsumerKey:@”Your Consumer Key” consumerSecret:@”Your Consumer Secret” consumerScheme:@"Your Consumer Scheme"];
    }
 
    @endcode
 *
 */
+ (void) setConsumerKey: (NSString*) consumerKey consumerSecret: (NSString*) consumerSecret consumerScheme:(NSString*)urlScheme __attribute__ ((deprecated));


/*!
 *  @brief Authenticate and then share to Tumblr
 *  @since 7.0.0
 *  @deprecated 8.0.0
 *
 *  Flurry will do a one time authentication of the user and then post the shared content to Tumblr.
 *  To receive success and failure notifications please implement the FlurryTumblrDelegate protocol
 *  and register your viewcontroller as the delegate with Flurry.
 *
 *  @see FlurryTextShareParameters and FlurryImageShareParameters
 *
 *
 *  @code
 *  - (void)tumblrPostImage:(NSURL*)imgPath withCaption:(NSString*)imgCaption
    {
        FlurryImageShareParameters* imgShareParameters = [[FlurryImageShareParameters alloc] init];
 
        // set share parameters
        imgShareParameters.imageURL = [imgPath absoluteString];
        imgShareParameters.imageCaption = imgCaption;
        imgShareParameters.iOSDeepLink = @"Your App’s iOS Deep Link to Content";
        imgShareParameters.androidDeepLink = @"Your App’s Android Deep Link";
        imgShareParameters.webLink = @"Your App’s Web Link"; *
 
        // share
        [FlurryTumblr post:imgShareParameters presentingViewController:self];
    }
 
    @endcode
 *
 */
+ (void) post: (id<IFlurryTumblrShareParameters>)parameters  presentingViewController:(UIViewController*) presentingController __attribute__ ((deprecated));

/*!
 *  @brief Sets the object to receive various delegate methods.
 *  @since 7.0.0
 *  @deprecated 8.0.0
 *
 *  This method allows you to register an object that will receive
 *  notifications at different phases of Tumblr sharing.
 *
 *  @see FlurryTumblrDelegate.h for details on delegates available.
 *
 *  @note: please don’t set the delegate to nil on viewDidUnload as Flurry Tumblr views are shown modally
 *   it is recommended instead to set it to nil in the dealloc of your delegate object.
 *
 *  @code
 *  - (void) viewDidLoad
 {
 [FlurryTumblr setDelegate:self];
 
 // ....
 }
 *  @endcode
 *
 *  @param delegate The object to receive notifications of various tumblr actions.
 *
 */
+ (void) setDelegate: (id<FlurryTumblrDelegate>) delegate __attribute__ ((deprecated));


/*!
 *  @brief Returns a Tumblr icon
 *  @since 7.0.0
 *  @deprecated 8.0.0
 *
 *  This image can be used with a UI element such as a UI button that will
 *  share to Tumblr.
 *
 *  @see https://www.tumblr.com/logo for additional icons
 *
 *
 *  @code
 *  - (void) addTumblrButton
    {
        UIButton* tumblrButton = [[UIButton alloc] init];
        UIImage* tumblrImage = [FlurryTumblr tumblrLogo];
        [tumblrButton setBackgroundImage:tumblrImage forState:UIControlStateNormal];
        [self.view addSubView: tumblrButton];
 
        // ....
    }
 *  @endcode
 *
 */
+ (UIImage*) tumblrLogo __attribute__ ((deprecated));

/*!
 *  @brief Check to see if the Flurry SDK handles the URL
 *  @since 7.5.0
 *  @deprecated 8.0.0
 *
 *  Flurry will listen and handle the URL callback from SafariViewController after Tumblr login
 *  This features added for only iOS 9.0 and above.
 
 *  @code
 *  -(BOOL) application:(UIApplication *)app openURL:(nonnull NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(nonnull id)annotation
    {
 
        if ([sourceApplication isEqualToString:@"com.apple.SafariViewService"])
        {
            return [FlurryTumblr handleURL:url];
        }
        return NO;
    }
 
 * @endcode
 *
 */
+ (BOOL)handleURL:(NSURL*)url __attribute__ ((deprecated));
@end
