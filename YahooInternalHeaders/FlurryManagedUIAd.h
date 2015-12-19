//
//  FlurryManagedUIAd.h
//  Pods
//
//  Created by Vamsikrishna Prakhya on 11/23/15.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FlurryAdEvent.h"
#import "FlurryEventController.h"
#import "FlurryManagedUIAdTrackerDelegate.h"

@interface FlurryAdAsset : NSObject

@property (nonatomic, strong, readonly) NSString* name;
@property (nonatomic, strong, readonly) NSString* type;
@property (nonatomic, strong, readonly) NSString* value;
@property (nonatomic, assign, readonly) int width;
@property (nonatomic, assign, readonly) int height;

+(FlurryAdAsset*) assetForName:(NSString*) name
                     assetList:(NSArray*) assetList;

@end

@protocol IFlurryManagedUIAdReporting <NSObject>

#pragma mark - View Tracking

@property (nonatomic, strong) NSDictionary* impressionParams;

- (void) trackViewabilityWithView:(UIView*) viewToTrack;
- (void) untrackViewability;
- (UIView*) trackingView;


#pragma mark - Click Tracking

- (void) reportClickWithPresentingViewController:(UIViewController *)presentingViewController
                                          params:(NSDictionary*) params;

- (void) reportInfoIconClickWithPresentingViewController:(UIViewController *)presentingViewController;


#pragma mark - Feedback Beaconing

- (void) reportAdHiddenWithParams:(NSDictionary*) params;
- (void) reportAdHiddenReasonGivenWithParams:(NSDictionary*) params;


#pragma mark - Video Beaconing

- (void) reportVideoStartWithParams:(NSDictionary*) params;
- (void) reportVideoChargeWithParams:(NSDictionary*) params;
- (void) reportVideoQuartile25WithParams:(NSDictionary*) params;
- (void) reportVideoQuartile50WithParams:(NSDictionary*) params;
- (void) reportVideoQuartile75WithParams:(NSDictionary*) params;
- (void) reportVideoQuartile100WithParams:(NSDictionary*) params;
- (void) reportVideoClickQuartile100WithParams:(NSDictionary*) params;

@end

@interface FlurryManagedUIAd : NSObject <IFlurryManagedUIAdReporting, IFlurryManagedUIAdTrackerDelegate, IFlurryEventControllerHandler>

@property (nonatomic, strong, readonly) NSString *adID;
@property (nonatomic, strong, readonly) NSString *unitID;
@property (nonatomic, strong, readonly) NSString *interactionType;
@property (nonatomic, strong, readonly) NSString *layoutTypeString;
@property (nonatomic, strong, readonly) NSString *adTypeForInstrumentation;
@property (nonatomic, strong, readonly) NSString *mediaTypeForInstrumentation;
@property (nonatomic, strong, readonly) NSString *inventorySourceID;
@property (nonatomic, strong, readonly) NSString *displayType;
@property (nonatomic, strong, readonly) NSDate   *timeOfCreation;

@property (nonatomic, strong, readonly) NSString *feedbackDomain;
@property (nonatomic, strong, readonly) NSString *carouselGroup;

@property (nonatomic, strong, readonly) NSDictionary *appInfo;
@property (nonatomic, strong, readonly) NSDictionary *uiInfo;
@property (nonatomic, strong, readonly) NSDictionary *diagnostics;
@property (nonatomic, strong, readonly) NSDictionary *errorInfo;

@property (nonatomic, strong, readonly) NSArray *assetList;
@property (nonatomic, strong, readonly) NSNumber*  durationSeconds;
@property (nonatomic, strong, readonly) NSNumber*  visiblePercentThreshold;
@property (nonatomic, strong, readonly) NSMutableDictionary *params;

@end
