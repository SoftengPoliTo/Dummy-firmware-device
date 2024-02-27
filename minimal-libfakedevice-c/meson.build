project(
  'libfakedevice-c',
  'c',
  license: 'MIT',
  meson_version: '>= 0.53.0',
  default_options: ['c_std=gnu11', 'warning_level=1'],
  version: '0.1.0'
)

c = meson.get_compiler('c')

flags = [
  '-static',
  '-pedantic'
]

include_directories('include')

sources = [
  'src/feature.c',
  'src/fake-firmware.c',
]

fake_firmware = executable (
  'minimal-fake-firmware-c',
  sources,
  install: true,
  link_args: flags
)
