# libfakedevice-cpp

This C++ project, **libfakedevice-cpp**, provides functionalities for device control, file manipulation, network access, webcam usage, and audio generation. Below, you'll find an overview of the project's components.


## APIs

### 1. Device Control (`device.h` and `device.cpp`)

#### `turnLampOn()`
- Turns on the lamp.
- Returns `true` if the lamp is successfully turned on.

#### `turnLampOff()`
- Turns off the lamp.
- Returns `false` if the lamp is successfully turned off.

### 2. Features (`features.h` and `features.cpp`)

#### `writeOnDrive()`
- Writes a new file named "foo.txt" in the current directory.

#### `accessNetwork()`
- Accesses the network and downloads the body of the Rust programming language webpage.

#### `accessWebcam(const std::string& webcam_path)`
- Accesses the webcam specified by `webcam_path` and captures 10 frames.
- Displays an error if the webcam doesn't exist.

#### `accessAudioDriver()`
- Accesses the audio driver and produces a one-second beep sound.

### 3. Fake Firmware (`fake-firmware.cpp`)
- Integrates and utilizes functionalities from both `device` and `features`.
- Demonstrates the combined usage of features in a simulated firmware.

## Automatic Build 

The complete compilation procedure can be started by running `./install_and_build.sh`. This script will take care of the necessary installations, including Meson (used to orchestrate the build process) and Clang++ (used as the compiler), if they are not already present in the operating system. Next, the process will continue with configuration and, optionally, installation of dependencies, followed by the compilation of the project itself.

To make changes to the code and subsequently recompile it, simply run the `ninja` command within the build directory.

After the build process, you can run the product file by accessing to the build folder and running `./libfakedevice`.

## Manual Build

It is important to note that although the compilation procedure can be automated to simplify the process, the portability of execution may be affected by the diversity of operating environments and system permissions. Therefore, becoming familiar with the manual installation procedure is advantageous, as it provides a deeper understanding of specific dependencies and system-specific configurations.

1. Install Meson and CLang:
   ```bash
   sudo apt-get update
   sudo apt-get install meson

   # Configure and install dependencies and project.
   sudo apt-get update
   sudo apt-get install clang
   ```
2. Build the project using Meson:
   ```bash
   # Navigate to the project directory
   cd /path/to/your/project/libfakedevice-cpp

   # Configure and install dependencies and project.
   env CXX=clang++ meson setup build # to use clang as compiler
   cd build
   ninja
   ```
3. Run the project:
   ```bash
    ./libfakedevice
   ```


## Dependencies

1. [libcurl](https://github.com/curl/curl)
2. [opencv](https://github.com/opencv/opencv)
3. [rtaudio](https://github.com/thestk/rtaudio)
