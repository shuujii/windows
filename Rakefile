require 'rbconfig'

task :default => :all

desc "build all"
task :all

desc "run all"
task :run => :all

desc "run all with printing source file"
task :run_with_print => :all do
  puts
  puts "---"
  puts File.read(Dir["src/*.c"][0])
  puts "---"
  puts
  Rake::Task[:run].invoke
end

Dir.glob("src/*.c") do |src|
  base_exe = File.basename(src, ".*")
  exe = "bin/#{base_exe}#{RbConfig::CONFIG['EXEEXT']}"

  desc "build #{base_exe}"
  task base_exe => exe
  file exe => src do |t|
    cflags = ENV['CFLAGS']
    mkpath "bin"
    if RbConfig::CONFIG['host_os'] =~ /mswin(?!ce)|mingw|bccwin/
#      cmd = "cl /nologo /W3 /D_CRT_SECURE_NO_WARNINGS #{src} /link /out:#{exe}"
      cmd = "cl /W3 /D_CRT_SECURE_NO_WARNINGS #{cflags} #{src} /link /out:#{exe}"
    else
      cmd = "clang -Wall #{cflags} -o #{exe} #{src}"
    end
#    puts "$ #{cmd}"
    sh cmd
  end

  task :all => exe

  task :run do
    sh exe
  end
end
