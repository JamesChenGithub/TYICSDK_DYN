
Pod::Spec.new do |s|


  s.name         = "TYICSDK_Dyn"
  s.version      = "2.0.305"
  s.summary      = "TYICSDK"
  s.description  = <<-DESC
                      腾讯云互动教育极简单接入apaas方案
                   DESC
  s.homepage     = "https://github.com/JamesChenGithub/TYICSDK_Dyn"
  s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = "alexichen"
  s.platform     = :ios
  s.platform     = :ios, "9.0"

  valid_archs = ['armv7','arm64', 'x86_64']
  s.xcconfig = {
    'VALID_ARCHS' =>  valid_archs.join(' '),
  }


  s.source       = { :git => "https://github.com/JamesChenGithub/TYICSDK_Dyn.git", :tag => "#{s.version}" }
  #s.resource = 'tyicimage.bundle'
  # the framework upload to Cocoa Pods
  s.vendored_frameworks = 'TYICSDK.framework'
  s.frameworks = 'Foundation', 'Accelerate'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  # s.dependency 'TXLiteAVSDK_TRTC', '7.2.8940'

end
