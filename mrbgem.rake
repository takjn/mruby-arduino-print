MRuby::Gem::Specification.new('mruby-print') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Jun Takeda'
  spec.summary = 'standard print/puts/p for mruby-arduino environments'
  spec.description = 'Redirecting print/puts/p to Arduino Serial.This gem is intended to be compatible with standard mruby-print.'

  spec.add_dependency('mruby-arduino')
end
