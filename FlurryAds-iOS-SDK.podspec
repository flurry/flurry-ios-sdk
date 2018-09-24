#
# Be sure to run `pod lib lint FlurryAds-iOS-SDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FlurryAds-iOS-SDK'
  s.version          = '1.1.0'
  s.summary          = 'Flurry SDK for iOS'
  s.license          = { :type => 'Commercial', :file => 'Licenses/Flurry-LICENSE.txt' }
  s.description      = 'FlurrySDK consists of: Flurry for analytics tracking and reporting. Flurry Ads for Native, Full Screen Ads integration'
  s.homepage = 'http://developer.yahoo.com/flurry'
  s.author           = { 'Flurry' => 'integration@flurry.com' }
  s.source           = { :git => 'https://github.com/flurry/FlurryAds-iOS-SDK.git', :tag => s.version.to_s }
  s.requires_arc = false
  s.platforms   = { :ios => "8.0" }
  s.default_subspec = 'FlurryAds'

  s.subspec 'FlurryAds' do |ss|
    ss.source_files = [
      'FlurryAds/**/*.h',
      'FlurryAds/FlurryAdsEmpty.m'
    ]
    ss.libraries = 'z'

    ss.platform   = :ios, '8.0'
    ss.frameworks = 'CoreGraphics', 'CoreMedia', 'MediaPlayer', 'AVFoundation', 'CoreTelephony', 'WebKit', 'SystemConfiguration'
    ss.weak_frameworks = 'AdSupport', 'StoreKit', 'SafariServices'
    ss.vendored_libraries = 'FlurryAds/libFlurryAds_#{s.version}.a'
    ss.dependency 'Flurry-iOS-SDK/FlurrySDK',  '~> 9.0.0'

  end
end
