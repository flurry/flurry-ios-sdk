//
//  FlurryAdManager.h
//  Flurry
//
//  Created by Anthony Watkins on 5/14/12.
//  Copyright (c) 2012 Flurry Inc. All rights reserved.
//  
//  Manages single FlurryAd container for ad space and manages all active adUnits
//  
//  Access to the manager is threadsafe.

#import <Foundation/Foundation.h>


#pragma mark - Flurry Yahoo Request Manager Delegate

@protocol FlurryManagedUIRequestManagerDelegate <NSObject>

@optional

- (void) adsAvailable:(NSArray*)ads;

- (void) adsNotAvailable:(NSDictionary*)params;

@end

#pragma mark - Flurry Yahoo Request Manager

@interface FlurryManagedUIRequestManager : NSObject

// shared instance
+ (FlurryManagedUIRequestManager *) sharedInstance;

// request delegate
@property (nonatomic, weak) id<FlurryManagedUIRequestManagerDelegate> delegate;


// Fetch Ad Units for the given ad unit ids
// If there are none available then this routine will return nil and simultneously
// queue an ad request with the ad cache. Success and error callbacks are done via
// the requestDelegate.
- (void) fetchAdUnitsForUnitIDs:(NSArray*) unitIDs withBucketIds:(NSArray*)bucketIds withBcookie:(NSString*)bCookie;


@end



