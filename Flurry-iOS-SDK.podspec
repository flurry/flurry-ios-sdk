#
# Be sure to run `pod lib lint Flurry-iOS-SDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Flurry-iOS-SDK'
  s.version          = '8.2.1'
  s.summary          = 'Flurry SDK for iOS'
  s.license          = { :type => 'Commercial', :file => 'Licenses/Flurry-LICENSE.txt' }
  s.description      = 'FlurrySDK consists of: Flurry for analytics tracking and reporting. Flurry Ads for Native, Full Screen Ads integration'
  s.homepage = 'http://developer.yahoo.com/flurry'
  s.author           = { 'Flurry' => 'integration@flurry.com' }
  s.source           = { :git => 'https://github.com/flurry/Flurry-iOS-SDK.git', :tag => s.version.to_s }
  s.requires_arc = false
  s.platforms   = { :ios => "8.0", :watchos => "2.0" }
  s.default_subspec = 'FlurrySDK'

  s.subspec 'FlurrySDK' do |ss|
    ss.source_files = [
      'Flurry/Flurry.h',
      'Flurry/FlurrySessionBuilder.h',
      'Flurry/FlurryEmpty.m'
    ]

    ss.platform   = :ios, '8.0'
    ss.frameworks = 'Foundation', 'SystemConfiguration', 'UIKit', 'Security'
    ss.weak_framework = 'WatchConnectivity'
    ss.vendored_libraries = "Flurry/libFlurry_8.2.1.a"
  end

  s.subspec 'FlurryWatchSDK' do |ss|
    ss.source_files = [
      'Flurry/Flurry.h',
      'Flurry/FlurryWatch.h',
      'Flurry/FlurrySessionBuilder.h',
      'Flurry/FlurryWatchEmpty.m',
      'Flurry/FlurryEmpty.m'
    ]

    ss.platform   = :ios, '8.0'
    ss.frameworks = 'Foundation', 'WatchConnectivity', 'SystemConfiguration', 'UIKit', 'Security'
    ss.vendored_libraries = "Flurry/libFlurry_8.2.1.a"
  end

  s.subspec 'FlurryWatchOSSDK' do |ss|
    ss.source_files = [
      'Flurry/FlurryWatch.h',
      'Flurry/Flurry.h',
      'Flurry/FlurrySessionBuilder.h',
      'Flurry/FlurryWatchEmpty.m'
    ]

    ss.platform   = :watchos, '2.0'
    ss.frameworks = 'Foundation', 'WatchConnectivity'
    ss.vendored_libraries = "Flurry/libFlurryWatch_8.2.1.a"
  end

  s.subspec 'FlurryTVOS' do |ss|
     ss.source_files = [
       'Flurry/Flurry.h',
       'Flurry/FlurrySessionBuilder.h',
       'Flurry/FlurryEmpty.m'
     ]

     ss.platform   = :tvos, '9.0'
     ss.frameworks = 'Foundation', 'SystemConfiguration', 'UIKit', 'Security'
     ss.vendored_libraries = "Flurry/libFlurryTVOS_8.2.1.a"
   end

  s.subspec 'FlurryAds' do |ss|
    ss.source_files = [
      'FlurryAds/**/*.h',
      'FlurryAds/FlurryAdsEmpty.m'
    ]
    ss.libraries = 'z'

    ss.platform   = :ios, '8.0'
    ss.frameworks = 'CoreGraphics', 'CoreMedia', 'MediaPlayer', 'AVFoundation', 'CoreTelephony'
    ss.weak_frameworks = 'AdSupport', 'StoreKit'
    ss.vendored_libraries = "FlurryAds/libFlurryAds_8.2.1.a"
    ss.dependency 'Flurry-iOS-SDK/FlurrySDK'
  end

  s.subspec 'TumblrAPI' do |ss|
    ss.source_files = [
      'FlurryTumblrAPI/FlurryTumblr.h',
      'FlurryTumblrAPI/FlurryTumblrDelegate.h',
      'FlurryAds/FlurryAdsEmpty.m'
    ]

    ss.platform   = :ios, '8.0'
    ss.dependency 'Flurry-iOS-SDK/FlurrySDK'
    ss.dependency 'Flurry-iOS-SDK/FlurryAds'
  end

end
