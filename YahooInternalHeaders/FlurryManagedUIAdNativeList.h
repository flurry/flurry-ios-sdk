//
//  FlurryNativeAdList.h
//  Pods
//
//  Created by Vamsikrishna Prakhya on 11/12/15.
//
//

#import <Foundation/Foundation.h>
#import "FlurryManagedUIAd.h"

@interface FlurryManagedUIAdNativeList : NSObject

@property (nonatomic, strong) NSString *adUnitId;
@property (nonatomic, strong) NSMutableArray *managedUIAds;

+ (NSArray*)buildAdLists:(NSArray*)ads;

@end
