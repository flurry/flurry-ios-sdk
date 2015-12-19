//
//  FlurryManagedUIAdTrackerDelegate.h
//  Pods
//
//  Created by Vamsikrishna Prakhya on 11/30/15.
//
//

@protocol IFlurryManagedUIAdTrackerDelegate <NSObject>

@property (nonatomic, assign) BOOL tracked;

- (void)viewIsNowVisibleForDuration: (NSTimeInterval) timeInterval;
- (void)endTrackingForVideoPlay;
- (void)viewPartiallyOutOfView;
- (BOOL)getFrameViewedAndTrackedForVideoPlay;
- (void)setFrameViewedAndTrackedForVideoPlay:(BOOL)setting;

@end
