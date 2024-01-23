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

