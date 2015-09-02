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

@property (nonatomic, retain) NSString* text;
@property (nonatomic, retain) NSString* title;

@end


@interface FlurryImageShareParameters : NSObject <IFlurryTumblrShareParameters>

@property (nonatomic, retain) NSString* imageURL;
@property (nonatomic, retain) NSString* imageCaption;

@end


@interface FlurryTumblr : NSObject

/*!
 *  @brief Set the consumer key and secret
 *  @since 7.0.0
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
+ (void) setConsumerKey: (NSString*) consumerKey consumerSecret: (NSString*) consumerSecret;


/*!
 *  @brief Authenticate and then share to Tumblr
 *  @since 7.0.0
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
+ (void) post: (id<IFlurryTumblrShareParameters>)parameters  presentingViewController:(UIViewController*) presentingController;

/*!
 *  @brief Sets the object to receive various delegate methods.
 *  @since 7.0.0
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
+ (void) setDelegate: (id<FlurryTumblrDelegate>) delegate;


/*!
 *  @brief Returns a Tumblr icon
 *  @since 7.0.0
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
+ (UIImage*) tumblrLogo;


@end