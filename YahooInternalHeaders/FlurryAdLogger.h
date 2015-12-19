//
//  FlurryAdLogger.h
//  Pods
//
//  Created by Shruthi Ramesh on 12/8/15.
//
//

#import <Foundation/Foundation.h>
@class FlurryManagedUIAd;


typedef enum {
    FlurryManagedAdActionEventAdDisplayed = 1001,
    FlurryManagedAdActionEventAdClickedSuccess = 1002,
    FlurryManagedAdActionEventAdClickedError = 1003,
    FlurryManagedAdActionEventBrowserLaunchFail = 1006,
    FlurryManagedAdActionEventBrowserLaunchSuccess = 1007,
    FlurryManagedAdActionEventImpressionReportFailed = 1009,
    FlurryManagedAdActionEventAdClicked = 1012,
    FlurryManagedAdActionEventAdViewingTime = 1207
}   FlurryManagedAdActionEventCode;

typedef enum {
    FlurryManagedAdErrorEventCodeBeaconSendFailed = 103006
}   FlurryManagedAdErrorEventCode;

enum {
    FlurryReasonCodeAlwaysYI13N = 1 << 1,
} ;
typedef uint8_t FlurryReasonCode;

extern NSString *const kFlurryManagedAdY13NColumnSDKName;
extern NSString *const kFlurryManagedAdY13NColumnSDKVersion ;
extern NSString *const kFlurryManagedAdY13NColumnSource ;
extern NSString *const kFlurryManagedAdY13NColumnAPIKey ;
extern NSString *const kFlurryManagedAdY13NColumnAdType;
extern NSString *const kFlurryManagedAdY13NColumnCreativeType ;
extern NSString *const kFlurryManagedAdY13NColumnAdCreativeID ;
extern NSString *const kFlurryManagedAdY13NColumnStatusCode ;
extern NSString *const kFlurryManagedAdY13NColumnStatusCodeValue;
extern NSString *const kFlurryManagedAdY13NColumnURL;
extern NSString *const kFlurryManagedAdYI13NColumnAdUnit ;
extern NSString *const kFlurryManagedAdYI13NColumnAdUnitDisplayType;
extern NSString *const kFlurryManagedAdYI13NColumnRequestID ;
extern NSString *const kFlurryManagedAdYI13NColumnTemplate;
extern NSString *const kFlurryManagedAdYI13NColumnAssetType ;
extern NSString *const kFlurryManagedAdYI13NColumnInventorySourceID ;
extern NSString *const kFlurryManagedAdYI13NColumnTag;


@protocol IFlurryManagedUIAdLogger <NSObject>

- (void) logEvent:(NSString *)name params:(NSDictionary *)params code:(uint8_t)reasonCode userInteraction:(BOOL)userInteraction;

@end


@interface FlurryAdLogger : NSObject

+(instancetype) sharedInstance;

- (void) logAdActionEvent:(FlurryManagedAdActionEventCode)eventCode value:(NSString *)value  ad:(FlurryManagedUIAd *)ad params:(NSDictionary*)params;

- (void) logErrorEvent:(FlurryManagedAdErrorEventCode)eventCode value:(NSString *)value  ad:(FlurryManagedUIAd *)ad  params:(NSDictionary*)params;

@property (nonatomic, weak) id<IFlurryManagedUIAdLogger> snoopyLogger;
@property (nonatomic, weak) id<IFlurryManagedUIAdLogger> flurryLogger;
@property (nonatomic, strong) NSString* apiKey;
@property (nonatomic, strong) NSString* sdkVersion;

@end
