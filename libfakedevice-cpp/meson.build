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
