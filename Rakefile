require 'rbconfig'

Dir.glob("src/*.c") do |src|
  base_exe = File.basename(src, ".*")
#  exe = File.join("bin", "#{base_exe}#{RbConfig::CONFIG['EXEEXT']}")
  exe = "bin/#{base_exe}#{RbConfig::CONFIG['EXEEXT']}"

  desc base_exe
  task base_exe => exe
  file exe => src do |t|
    mkpath "bin"
    if RbConfig::CONFIG['host_os'] =~ /mswin(?!ce)|mingw|bccwin/
      cmd = "cl.exe /W3 #{src} /link /out:#{exe}"
    else
      cmd = "clang -Wall -o #{exe} #{src}"
    end
    puts "$ #{cmd}"
    sh cmd
  end
end
