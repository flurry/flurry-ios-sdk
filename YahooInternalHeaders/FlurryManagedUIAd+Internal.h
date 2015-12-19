//
//  YMAd+InternalMethods.h
//  YMobileAdSDK
//
//  Copyright (c) 2015 Yahoo, Inc. All rights reserved.

// #import "YMAd-Debug.h"
// #import "YMAdState.h"

// #import "FlurryYahooAdNative.h"

#import "FlurryManagedUIAd.h"

@class FlurryAdUnit;

@interface FlurryManagedUIAd ()


+ (instancetype) createWithAdId:(NSString*) adID
                         unitID:(NSString*) unitID
                interactionType:(NSString*) interactionType
                 feedbackDomain:(NSString*) feedbackDomain
                        appInfo:(NSDictionary*) appInfo
                         uiInfo:(NSDictionary*) uiInfo
                      assetList:(NSArray*)  assetList;

- (id)initWithAdUnit:(FlurryAdUnit*)ad;
- (FlurryAdUnit *)activeAdUnit;

@end

