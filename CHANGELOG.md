# Change Log

## Version 10.x

### Version 10.3.1 - 04/23/2020

* Fixed crash when session cold starts
* Fixed crash on iPad iOS 12.x

### Version 10.3.0 - 04/13/2020

* Fixed crash caused by Calendar Preferences update
* Fixed Crash on FlurryWatchConnectivity when running an iPad
* Fixed crash caused by fetching app state in background thread
* Fixed crash caused by invalid pointer during URLSession construction
* Added sanity check for userId to conform to data type String

### Version 10.2.0 - 01/08/2020

* New apis for FlurryUserProperties
    * Added `[FlurryUserProperties set: values:]`
    * Added `[FlurryUserProperties set: value:]`
    * Added `[FlurryUserProperties add: values:]`
    * Added `[FlurryUserProperties add: value:]`
    * Added `[FlurryUserProperties remove: values:]`
    * Added `[FlurryUserProperties remove: value:]`
    * Added `[FlurryUserProperties remove:]`
    * Added `[FlurryUserProperties flag:]`
* WatchOS streaming sdk watchconnectivity bug fix
* Fixed bug when setCrashReportingEnable:NO

### Version 10.1.0 - 12/02/2019

* New apis for FlurryCCPA
    * Added `[FlurryCCPA withDataSaleOptOut:]` to `FlurrySessionBuilder`
    * Added `[FlurryCCPA setDataSaleOptOut:]`
    * Added `[FlurryCCPA setDelete:]`
* Made fix for FConfig fetch fail
* Fixed revenue APIs call back crashes
* Uses WKWebView for ad display

### Version 10.0.2 - 10/01/2019

* API Deprecations
    * `[Flurry setSessionReportsOnCloseEnabled:]`
    * `[Flurry setSessionReportsOnPauseEnabled:]`
* watchOS apps no longer have access to `Flurry` class. watchOS APIs are only located in `FlurryWatch` class.
* Fixed crash on iOS 8 and iOS 9 devices.
* Improved reliability and performance.

### Version 10.0.1 - 09/23/2019

* Fixed potential build errors while using FConfig.
* Improved reliability and performance.

### Version 10.0.0 - 09/17/2019

* Redesigned, slimmer SDK structured on the modular analytics session resulting in reduced SDK size, shorter cold start, and laying down the foundation for server-side configurable session definition. 
* Flurry Analytics Support for watchOS 5
* tvOS 
    * Added a new set of [TVML JavaScript APIs](https://developer.yahoo.com/flurry/docs/analytics/gettingstarted/tvos/)
    * Added tvOS support for Flurry Messaging
* API Deprecations
    * `[Flurry logAllPageViewsForTarget:]`
    * `[Flurry stopLogPageViewsForTarget:]`
    * `[Flurry logPageView]`
* API Removals
    * `[Flurry setAppVersion:]`
    * `[Flurry setTVEventFlushCount:]`
    * `[Flurry setTVSessionReportingInterval:]`
    * `[Flurry setDebugLogEnabled:]`
    * `[Flurry setSessionContinueSeconds:]`
    * `[Flurry setCrashReportingEnabled:]`
    * `[Flurry logAllPageViews:]`
    * `[Flurry setPulseEnabled:]`
    * `[Flurry setEventLoggingEnabled:]`
    * `[Flurry setBackgroundSessionEnabled:]`
    * `[Flurry setLatitude:longitude:horizontalAccurary:verticalAccuracy:]`
* `Flurry.setUserId()` can now be set/unset within the same session
* Added `logPaymentTransactionParamsWithTransactionId()` to manually log payments
* Improved compatibility with iOS 13
* Fixed crash in `FlurryAdActorDefferedQueue`
* Removed compiler warnings during the build process. 
* Added `withSessionOrigin()`, `withSessionOriginVersion()`, `withSessionOriginParameters()`, `withSessionDeeplink()` and `withSessionProperties()` to `FlurrySessionBuilder`
* Added multi platform support for podspec so that FlurrySDK pod can be used for iOS, tvOS and watchOS
