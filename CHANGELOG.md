# Change Log

## Version 12.x

### Version 12.1.1 - 06/30/2022

* Fix for http 400 error when consentStrings is nil

### Version 12.1.0 - 06/23/2022

* Flurry's xcframework uses framework rather than static libraries
* Fix for tvOS arm64 simulator support 

### Version 12.0.0 - 04/18/2022

* Introduced the XCFramework in our build pipeline to replace legacy static library 
* Enhanced the minimum deployment target to iOS 10.0, tvOS 10.0, macOS 11.0, and watchOS 3.0
* Introduced `NS_SWIFT_NAME()` in header file for re-defining all external Flurry APIs and enums in swift
* APIs removed :
    * `[Flurry setSessionReportsOnCloseEnabled:]`
    * `[Flurry setSessionReportsOnPauseEnabled:]`
    * `[Flurry logPaymentTransactionParamsWithTransactionId:productId:currency:productName:transactionState:userDefinedParams:statusCallback:]`
    * `[Flurry logFlurryPaymentTransactionParamsWithTransactionId:productId:quantity:price:currency:productName:transactionState:userDefinedParams:statusCallback:]`
* Fixed the background session reporting issue that caused long session duration
* Fixed `FlurryConsent` crashes
    
    
## Version 11.x

### Version 11.4.0 - 11/10/2021

* Introduced drop rule for user property
* Added new APIs for `Flurry`
    * Add new manual payment log API `[Flurry logPaymentTransactionWithTransactionId:productId:quantity:price:currency:productName:transactionState:userDefinedParams:statusCallback:]`
    * Add new setter APIs
        * Add `[Flurry setAppVersion:]`
        * Add `[Flurry setSessionContinueSeconds:]`
        * Add `[Flurry setCountBackgroundSessions:]`
* API deprecations
    * `[Flurry logFlurryPaymentTransactionParamsWithTransactionId:productId:quantity:price:currency:productName:transactionState:userDefinedParams:statusCallback:]`
    
* Fixed publisher segmentation registering internal listener during initialization
* Fixed FlurryConfig memory leaks during initialization
* Update Copyright (c) 2021 Yahoo

    
### Version 11.3.0 - 08/12/2021

* You asked for standard events and we are here to tell you, you are getting them! Standard Events help you track standardized actions that users take within your app – for example, making a purchase, adding a social comment, or clicking on an Ad. We are taking the guess work out on what to call the events and what parameters to pass in by providing an API to seamlessly log all of these standard actions within your app. 

* Fix missing crash report on tvOS SDK

### Version 11.2.1 - 04/06/2021

* Separates xcode11 and xcode 12 builds
* FlurryMessaging auto integration crash fix
* Fix UIApplication.endBackgroundTask(_:) risk
* Fix incorrect crash report stacktrace for log error and exception

### Version 11.2.0 - 11/30/2020

* Separates xcode11 and xcode 12 builds
* Symbolication error fix
* Background sessions fix
* App orientation crash fix

### Version 11.1.1 - 10/08/2020

* Fixed location source threading warning
* Potentially fixed interface orientation data source crash

### Version 11.1.0 - 09/15/2020

* Fixed duplicate symbol issue in crash reporter
* Upgraded APIs level for Interface orientation data source and fixed potential race condition

### Version 11.0.0 - 08/24/2020

* Flurry Analytics Support for iOS 14.0, tvOS 14.0, watchOS 7.0
* Added support for iOS 14 App Tracking Transparency. [See YDN doc here](https://developer.yahoo.com/flurry/docs/analytics/gettingstarted/ios14/att/)
* Added SKAdNetwork Conversion Value: Publishers can use Flurry to manage & understand Conversion Value. [See Blog Post](https://www.flurry.com/blog/post/626449503277531136/announcing-flurry-conversion-value-analytics-for) and [YDN doc](https://developer.yahoo.com/flurry/docs/analytics/gettingstarted/ios14/SKAdNetwork/) here.
* New APIs for `FlurrySKAdNetwork`
    * Added `[FlurrySKAdNetwork flurryUpdateConversionValueWithEvent:]`
    * Added `[FlurrySKAdNetwork flurryUpdateConversionValue:]`
* New APIs for `Flurry`
    * `[Flurry logPaymentTransactionParamsWithTransactionId:productId:quantity:price:currency:productName:transactionState:userDefinedParams:statusCallback:]`
* API Deprecations
    * `[Flurry logPaymentTransactionParamsWithTransactionId:productId:quantity:price:currency:productName:transactionState:userDefinedParams:statusCallback:]` 
* API Removals
    * `[Flurry logAllPageViewsForTarget:]`
    * `[Flurry stopLogPageViewsForTarget:]`
    * `[Flurry logPageView]`
* Fixed bugs in FlurryKVStorage for nested data types
* Fixed crash on FlurrySignalConnectionTypeDataProvider KVC issue


## Version 10.x

### Version 10.3.4 - 07/23/2020

* Fixed crash analytics issue
* Fixed App orientation data validation crash
* Removed base64 encoded params for error frame

### Version 10.3.3 - 06/24/2020

* Fixed unarchiving exception with NSSecureCoding conformed
* Fixed watchOS / iOS SDK connectivity issues

### Version 10.3.2 - 06/11/2020

* Fixed memory leaks in FlurryDataSender and FlurryDataSenderIndex
* Fixed crash in FlurryiOSUtil while getting CoreTelephony data
* Fixed missing launch options when session cold starts from push open using FlurryMessaging
* Upgraded API levels for various iOS/watchOS frameworks

### Version 10.3.1 - 04/17/2020

* Fixed crash when session cold starts
* Fixed missing set launch options when session cold start from push open

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
