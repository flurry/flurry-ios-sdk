# Be sure to run `pod lib lint Flurry-iOS-SDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Flurry-iOS-SDK'
  s.version          = '12.3.1'
  s.summary          = 'Flurry SDK for iOS'
  s.license          = { :type => 'Commercial', :file => 'Licenses/Flurry-LICENSE.txt' }
  s.description      = 'FlurrySDK consists of: Flurry for analytics tracking and reporting.'
  s.homepage = 'http://developer.yahoo.com/flurry'
  s.author           = { 'Flurry' => 'integration@flurry.com' }
  s.source           = { :git => 'https://github.com/flurry/Flurry-iOS-SDK.git', :tag => s.version.to_s }
  s.platforms        = { :ios => '10.0', :tvos => '10.0' }
  s.requires_arc     = false
  s.pod_target_xcconfig = { 'ONLY_ACTIVE_ARCH' => 'YES' }
  s.user_target_xcconfig = { 'ONLY_ACTIVE_ARCH' => 'YES' }
  s.default_subspec  = 'FlurrySDK'
 

  s.subspec 'FlurrySDK' do |ss|
    ss.ios.deployment_target = '10.0'
    ss.ios.frameworks = 'Foundation', 'SystemConfiguration', 'UIKit', 'Security'
    ss.ios.vendored_frameworks = 'Flurry_iOS_SDK.xcframework'
    ss.ios.dependency 'Flurry-iOS-SDK/CrashReporter'

    ss.tvos.deployment_target = '10.0'
    ss.tvos.frameworks = 'Foundation', 'SystemConfiguration', 'UIKit', 'Security'
    ss.tvos.vendored_frameworks = 'Flurry_iOS_SDK.xcframework'
    ss.tvos.dependency 'Flurry-iOS-SDK/CrashReporter'
  end

  s.subspec 'FlurryTVOS' do |ss|
    ss.platform   = :tvos, '10.0'
    ss.frameworks = 'Foundation', 'SystemConfiguration', 'UIKit', 'Security'
    ss.tvos.vendored_frameworks = 'Flurry_iOS_SDK.xcframework'
    ss.tvos.dependency 'Flurry-iOS-SDK/CrashReporter'
  end

   s.subspec 'FlurryConfig' do |ss|
    ss.platform   = :ios, '10.0'
    ss.ios.vendored_frameworks = 'Flurry_Config.xcframework'
    ss.dependency 'Flurry-iOS-SDK/FlurrySDK'
  end

   s.subspec 'FlurryMessaging' do |ss|
    ss.ios.deployment_target = '10.0'
    ss.ios.vendored_frameworks = "Flurry_Messaging.xcframework"
    
    ss.tvos.deployment_target = '10.0'
    ss.tvos.vendored_frameworks = "Flurry_Messaging.xcframework"
    
    ss.dependency 'Flurry-iOS-SDK/FlurrySDK'
  end

   s.subspec 'CrashReporter' do |ss|
    ss.ios.deployment_target = '10.0'
    ss.tvos.deployment_target = '10.0'
    ss.vendored_frameworks = "CrashReporter.xcframework"
  end
end

