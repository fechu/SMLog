
Pod::Spec.new do |s|

  s.name         = "SMLog"
  s.version      = "1.0.0"
  s.summary      = "Small logging library for logging message with different log levels."

  s.description  = <<-DESC
		    Small logging library for logging messages with different log levels. 
                   DESC

  s.homepage     = "https://github.com/fechu/SMLog"
  s.license      = "MIT"


  s.author             = { "Sandro Meier" => "sandro.meier@fidelisfactory.ch" }

  s.platform     = :ios

  s.source       = { :git => "https://github.com/fechu/SMLog.git", :tag => "1.0.0" }
  s.source_files  = "*.{h,m}"
  s.requires_arc = true


end
