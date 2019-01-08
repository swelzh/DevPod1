#
# Be sure to run `pod lib lint DevPod1.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'DevPod1'
  s.version          = '0.1.2'
  s.summary          = '这句描述也是没有意义s的'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/swelzh/DevPod1'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'swelzh' => 'lizhihua495@pingan.com.cn' }
  s.source           = { :git => 'https://github.com/swelzh/DevPod1.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'DevPod1/**/*'
  
  # s.resource_bundles = {
  #   'DevPod1' => ['DevPod1/Assets/*.png']
  # }

   s.public_header_files = 'DevPod1/Interface/**/*.h,DevPod1/Classes/**/*.h'
   s.frameworks = 'UIKit'
   s.dependency 'AFNetworking' 
   s.libraries =  'iconv','sqlite3','stdc++','z'
end
