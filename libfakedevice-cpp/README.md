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

## Build and Run

1. Build the project using Meson:
   ```bash
   # Navigate to the project directory
   cd /path/to/your/project/libfakedevice-cpp

   # Configure and install dependencies and project.
   env CXX=clang++ meson setup build # to use clang as compiler
   cd build
   ninja
   ninja install
   ```
2. Run the project:
   ```bash
    ./libfakedevice
   ```

## Dependencies

1. [libcurl](https://github.com/curl/curl)
2. [opencv](https://github.com/opencv/opencv)
3. [RtAudio](https://github.com/thestk/rtaudio)
