project(
    'minimal-libfakedevice-cpp', 
    'cpp',
    license: 'MIT',
    meson_version: '>= 0.53.0',
    default_options: ['cpp_std=c++17', 'warning_level=1'],
    version: '0.1.0'
    )

cpp = meson.get_compiler('cpp')

flags = [
    '-pedantic',
    '-static',
]

inc_dirs = include_directories('include')

sources = [
  'src/feature.cpp',
  'src/fake-firmware.cpp',
]

# Declaration of executable and dependencies.
fake_firmware = executable (
    'minimal-fake-firmware-cpp',
    sources,
    include_directories: inc_dirs,
    install: true,
    link_args: flags
)
