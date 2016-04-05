Flurry SDK
==========

### CocoaPods

To use FlurrySDK from cocoapods, for Analytics, Ad serving,  Apple Watch Extension, and for Tumblr in-app sharing follow the instructions:


To enable Flurry Analytics:

```
  pod ‘Flurry-iOS-SDK/FlurrySDK’
```


To enable Flurry Ad serving  : 

```
  pod 'Flurry-iOS-SDK/FlurrySDK'
  pod 'Flurry-iOS-SDK/FlurryAds'
```


To use FlurrySDK for Apple Watch 1.x Extension:    
```
target :"Your Apple Watch 1.x Extension Target" do 
   pod 'Flurry-iOS-SDK/FlurryWatchSDK’
end   
```


To use FlurrySDK for Apple Watch 2.x Extension:    
```
target :"Your Apple Watch 2.x Extension Target" do 
pod 'Flurry-iOS-SDK/FlurryWatchOSSDK’
platform :watchos, '2.0'
end   
```


Don't forget to read how to track events correctly in Apple Watch Extensions  in FlurryiOSAnalyticsREADMExx.pdf  


To enable Tubmlr in-app sharing: 
```
pod 'Flurry-iOS-SDK/FlurrySDK'
pod 'Flurry-iOS-SDK/FlurryAds'
pod 'Flurry-iOS-SDK/TumblrAPI'
```

### Carthage

1. Add Flurry to your project's `Cartfile`

    ```
    github "flurry/Flurry-iOS-SDK"
    ```

2. Run `carthage update` in your project directory
3. Drag the appropriate framework from `$PROJECT/Carthage/Build/` into your XCode project:
    1. **Analytics**
        1. FlurrySDK.framework
    2. **Ad Serving**
        1. FlurrySDK.framework
        2. FlurryAdsSDK.framework
    3. **Tumblr In-App Sharing**
        1. FlurrySDK.framework
        2. FlurryAdsSDK.framework
	    3. FlurryTumblrAPI.framework
4. Carthage requires a `Run Script Phase` to copy the framework(s). See [Carthage's getting started instructions](https://github.com/carthage/carthage#getting-started)
5. Import Flurry frameworks as required

```
@import FlurrySDK;
@import FlurryAdsSDK;
@import FlurryTumblrAPI;
```
