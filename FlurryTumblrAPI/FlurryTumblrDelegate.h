/*!
 *  @brief FlurryTumblrDelegate
 *  @deprecated 8.0.0
 */

typedef enum
{
    FlurryTumblrUserCanceled = 0,
    FlurryTumblrUserDenied    = 1,
    FlurryTumblrOtherError    = 2
}FlurryTumblrErrorType;

@protocol FlurryTumblrDelegate <NSObject>

@optional

- (void) flurryTumblrPostError: (NSError*) error errorType:(FlurryTumblrErrorType) errorType __attribute__ ((deprecated));

- (void) flurryTumblrPostSuccess __attribute__ ((deprecated));


@end
