//
//  FlurryAdNativeAssets.h
//  Flurry iOS Advertising
//
//  Copyright 2009-2014 Flurry, Inc. All rights reserved.
//	
//	Methods in this header file are for use by Flurry Publishers

#import <Foundation/Foundation.h>

/*!
 *  @brief Enum for supported asset types
 *  @since 6.0.0
 *
 */
typedef enum
{
    ASSET_TYPE_STRING = 0,
    ASSET_TYPE_IMAGE = 1,
    ASSET_TYPE_VIDEO = 2,
    ASSET_TYPE_VAST_VIDEO = 3,
    ASSET_TYPE_RICH_MEDIA = 4,
    ASSET_TYPE_UNKNOWN = 5
} kAssetType;

/*!
 *  @brief Provides all available methods for displaying native ad assets.
 *
 *  Set of methods that allow publishers to retrieve assets for native ads.
 *
 *  For information on how to use Flurry's Ads SDK to
 *  attract high-quality users and monetize your user base see <a href="https://developer.yahoo.com/flurry/docs/howtos">Support Center - Publishers</a>.
 *
 *  @author 2009 - 2014 Flurry, Inc. All Rights Reserved.
 *  @version 6.0.0
 *
 */
@interface FlurryAdNativeAsset : NSObject

/*!
 *  @brief Read only property that can be used to retrieve the name of the asset.
 *
 *  @since 6.0.0
 */
@property (nonatomic, strong, readonly) NSString *name;

/*!
 *  @brief Read only property that indicates the type of asset.
 *
 *  @since 6.0.0
 */
@property (nonatomic, readonly) kAssetType type;

/*!
 *  @brief Read only property that indicates the value of the asset.
 *
 *  @since 6.0.0
 */
@property (nonatomic, strong, readonly) NSString *value;

/*!
 *  @brief Read only property that indicates the width of the asset. This value is set if this object represents an image asset.
 *
 *  @since 6.0.0
 */
@property (nonatomic, assign, readonly) int width;

/*!
 *  @brief Read only property that indicates the height of the asset. This value is set if this object represents an image asset.
 *
 *  @since 6.0.0
 */
@property (nonatomic, assign, readonly) int height;


@end