[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fflurry%2Fflurry-ios-sdk.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Fflurry%2Fflurry-ios-sdk?ref=badge_shield)

Flurry SDK
==========


To use FlurrySDK from cocoapods, for Analytics, Ad serving,  Apple Watch Extension, and for Tumblr in-app sharing follow the instructions:


To enable Flurry Analytics:

```
  pod 'Flurry-iOS-SDK/FlurrySDK'
```


To enable Flurry Ad serving  : 

```
  pod 'Flurry-iOS-SDK/FlurrySDK'
  pod 'Flurry-iOS-SDK/FlurryAds'
```


To use FlurrySDK for Apple Watch 1.x Extension:    
```
target :"Your Apple Watch 1.x Extension Target" do 
   pod 'Flurry-iOS-SDK/FlurryWatchSDK'
end   
```


To use FlurrySDK for Apple Watch 2.x Extension:    
```
target :"Your Apple Watch 2.x Extension Target" do 
pod 'Flurry-iOS-SDK/FlurryWatchOSSDK'
platform :watchos, '2.0'
end   
```


To use FlurrySDK for tvOS apps:

```
target :"Your TVOS Application" do
pod 'Flurry-iOS-SDK/FlurryTVOS' #tVOS Analytics Pod'
platform :tvos, '9.0'
end
```

Don't forget to read how to track events correctly in Apple Watch Extensions  in FlurryiOSAnalyticsREADMExx.pdf  



## License
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fflurry%2Fflurry-ios-sdk.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Fflurry%2Fflurry-ios-sdk?ref=badge_large)