project(
    'libfakedevice-cpp', 
    'cpp',
    license: 'MIT',
    meson_version: '>= 0.49.0',
    default_options: ['cpp_std=c++17', 'warning_level=1'],
    version: '0.1.0'
    )

cpp = meson.get_compiler('cpp')

flags = [
    '-pedantic'
]

# Configuring inclusion directories.
include_directories('include')

sources = [
  'src/device.cpp',
  'src/features.cpp',
  'src/fake-firmware.cpp',
]

# Declaration of external dependencies using Wrap
libcurl_dep = dependency('libcurl', fallback : ['libcurl', 'libcurlWrap'])
opencv_dep = dependency('opencv4', fallback : ['opencv', 'opencvWrap'])
rtaudio_dep = dependency('rtaudio', fallback : ['rtaudio', 'rtaudioWrap'])

# Declaration of executable and dependencies.
fake_firmware = executable (
    'libfakedevice',
    sources,
    dependencies: [libcurl_dep, opencv_dep, rtaudio_dep],
    install: true
)

# Subprojects for external dependencies using Wrap
libcurl_wrap = wrap_project('libcurl',
    url : 'https://github.com/curl/curl/releases/download/curl-8_2_1/curl-8.2.1.tar.gz',
    directory : 'subprojects/libcurl',
    sources: ['subprojects/curl/curl.h'],
    build_by_default: true
)

opencv_wrap = wrap_project('opencv',
    url : 'https://github.com/opencv/opencv/archive/refs/tags/4.6.0.tar.gz',
    directory : 'subprojects/opencv',
    sources: ['subprojects/opencv4/opencv2/opencv.hpp'],
    build_by_default: true
)

rtaudio_wrap = wrap_project('rtaudio',
    url : 'https://github.com/thestk/rtaudio/archive/refs/tags/5.2.0.tar.gz',
    directory : 'subprojects/rtaudio',
    sources: ['subprojects/rtaudio/RtAudio.h'],
    build_by_default: true
)

# Add external dependencies to the main project
subproject('libcurl', default_options : ['libcurl:enabled=true'])
subproject('opencv', default_options : ['opencv:enabled=true'])
subproject('rtaudio', default_options : ['rtaudio:enabled=true'])
