Pod::Spec.new do |s|
  s.name = "DevPod1"
  s.version = "0.1.3"
  s.summary = "\u8FD9\u53E5\u63CF\u8FF0\u4E5F\u662F\u6CA1\u6709\u610F\u4E49s\u7684"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"swelzh"=>"lizhihua495@pingan.com.cn"}
  s.homepage = "https://github.com/swelzh/DevPod1"
  s.description = "TODO: Add long description of the pod here."
  s.frameworks = "UIKit"
  s.source = { :path => '.' }

  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'ios/DevPod1.framework'
end
