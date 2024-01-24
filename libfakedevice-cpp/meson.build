project(
    'libfakedevice-cpp', 
    'cpp',
    license: 'MIT',
    meson_version: '>= 0.53.0',
    default_options: ['cpp_std=c++17', 'warning_level=1'],
    version: '0.1.0'
    )

cpp = meson.get_compiler('cpp')

flags = [
    '-pedantic'
]

inc_dirs = include_directories('include')

sources = [
  'src/device.cpp',
  'src/feature.cpp',
  'src/fake-firmware.cpp',
]

# Declaration of external dependencies
libcurl_dep = dependency('libcurl', fallback: ['libcurl'])
cpr_dep = dependency('cpr', fallback : ['cpr'])
rtaudio_dep = dependency('rtaudio', fallback: ['rtaudio'])

# Declaration of executable and dependencies.
fake_firmware = executable (
    'libfakedevice_cpp',
    sources,
    include_directories: inc_dirs,
    dependencies: [cpr_dep, rtaudio_dep],
    install: true
)
