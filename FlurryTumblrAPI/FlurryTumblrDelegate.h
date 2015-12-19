
typedef enum
{
    FlurryTumblrUserCanceled = 0,
    FlurryTumblrUserDenied    = 1,
    FlurryTumblrOtherError    = 2
}FlurryTumblrErrorType;

@protocol FlurryTumblrDelegate <NSObject>

@optional

- (void) flurryTumblrPostError: (NSError*) error errorType:(FlurryTumblrErrorType) errorType;

- (void) flurryTumblrPostSuccess;


@end