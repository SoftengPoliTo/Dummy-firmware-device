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
- Writes a new file named 
```plaintext 
foo.txt
``` 
in the current directory.

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

Before building and running the project, ensure you have the following dependencies installed on your system.

### Meson

Meson is used as the build system for this project. To install Meson, run the following commands:

```bash
sudo apt update
sudo apt install meson
```

The use of the following command is also recommended:

```bash
sudo meson wrap update-db
```

to update the dependency database managed by `wrapdb`. `wrapdb` is a Meson component that manages the download and management of dependency packages.

### CLang++

CLang++ is used as the compiler for this project. Install Clang++ using the following commands:

```bash
sudo apt update
sudo apt install clang
```

### Other dependencies

The project relies on the following external libraries:

1. [cURL](https://github.com/curl/curl): Used for network access. Install it using:
```bash
sudo apt update
sudo apt install curl libcurl4-openssl-dev openssl
```

2. [openal](https://github.com/kcat/openal-soft): Used for audio generation. Install it using:
```bash
sudo apt update
sudo apt install libopenal-dev
```

## Build and Run the project

The complete compilation procedure can be started by running `./autorun.sh`. You can launch the project by running `./libfakedevice_c`.
