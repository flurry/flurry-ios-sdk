//
//  FlurryAdNativeAssets.h
//  Flurry iOS Advertising
//
//  Copyright 2009-2014 Flurry, Inc. All rights reserved.
//	
//	Methods in this header file are for use by Flurry Publishers

#import <Foundation/Foundation.h>

extern int const STYLE1_SMALL;
extern int const STYLE1_MEDIUM;
extern int const STYLE1_LARGE;
extern int const STYLE1_XLARGE;
extern int const STYLE2_SMALL;
extern int const STYLE2_MEDIUM;

@interface FlurryAdNativeStyle : NSObject

@property (nonatomic, readonly) NSString *style;

- (id)initWithStyle:(int)styleNum;

@end
