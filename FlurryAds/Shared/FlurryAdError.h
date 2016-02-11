/*!
 *  @file FlurryAdError.h
 *  @brief Provides all errors that could result from Ad objects
 *  
 *  This information will be present in object based error delegates.
 *
 *  @author 2010 - 2014 Flurry, Inc. All Rights Reserved.
 *
 *  @since 6.0.0
 *
 */
typedef enum
{
    FLURRY_AD_ERROR_DID_FAIL_TO_RENDER   = 0,
    FLURRY_AD_ERROR_DID_FAIL_TO_FETCH_AD = 1,
    FLURRY_AD_ERROR_CLICK_ACTION_FAILED  = 2,
}FlurryAdError;