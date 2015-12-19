//
//  FlurryManagedUITrackingManager.h
//  Pods
//
//  Created by Vamsikrishna Prakhya on 11/25/15.
//
//

#import <Foundation/Foundation.h>
#import "FlurryManagedUIAd.h"

@interface FlurryManagedUITrackingManager : NSObject

+(FlurryManagedUITrackingManager*) sharedInstance;

- (void) registerAd: (FlurryManagedUIAd*) managedUIAd withViewToTrack:(UIView*)trackView withImpressionDuration:(NSTimeInterval)impressionSeconds andPlayDuration:(NSTimeInterval)playbackSeconds;

- (BOOL)deRegisterAd:(FlurryManagedUIAd*)managedUIAd;

@end
