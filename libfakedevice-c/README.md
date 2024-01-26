# libfakedevice-c

This C project, **libfakedevice-c**, provides functionalities for device control, file manipulation, network access, webcam usage, and audio generation. Below, you'll find an overview of the project's components.

## APIs

### 1. Device Control (`device.h` and `device.c`)

#### `turnLampOn()`
- Turns on the lamp.
- Returns `true` if the lamp is successfully turned on.

#### `turnLampOff()`
- Turns off the lamp.
- Returns `false` if the lamp is successfully turned off.

### 2. Features (`feature.h` and `feature.c`)

#### `writeOnDrive()`
- Writes a new file named `foo.txt` in the current directory.

#### `accessNetwork()`
- Accesses the network and downloads the body of the Rust programming language webpage.

#### `accessWebcam(const char* webcam_path)`
- Accesses the webcam specified by `webcam_path` and captures 10 frames.
- Displays an error if the webcam doesn't exist.

#### `accessAudioDriver()`
- Accesses the audio driver and produces a two-seconds beep sound.

### 3. Fake Firmware (`fake-firmware.c`)
- Integrates and utilizes functionalities from both `device` and `feature`.
- Demonstrates the combined usage of features in a simulated firmware.

## Dependencies

Before building and running the project, make sure that `Meson` and `Clang` are installed on your system. In particular, `Meson` (https://mesonbuild.com/) is used as a tool to build the project, while `Clang` (https://clang.llvm.org/) is used as a compiler for the project. We also suggest updating the `wrapdb` (https://mesonbuild.com/Wrap-dependency-system-manual.html) used by Meson to retrieve the dependencies presented in the next section.

### Other dependencies

Before running the project, you must ensure that you have all external dependencies installed correctly. Instructions for installing the necessary dependencies on a Linux system are provided below. Be sure to run these commands before proceeding with compiling and running the project.

1. [cURL](https://github.com/curl/curl): Used for network access. You can install it on Linux using:
```bash
sudo apt update
sudo apt install curl libcurl4-openssl-dev openssl
```

2. [openal](https://github.com/kcat/openal-soft): Used for audio generation. You can install it on Linux using:
```bash
sudo apt update
sudo apt install libopenal-dev
```

## Build and Run the project

The complete compilation procedure can be started by running `./autorun.sh`. You can launch the project by running `./binaries/fake-firmware-c`.
