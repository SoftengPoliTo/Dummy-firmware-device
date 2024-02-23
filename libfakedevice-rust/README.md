# Rust libfakedevice

This code defines a library made of features which might be
present inside a firmware:

- Accessing to an hard drive
- Accessing to the network
- Getting some frames from webcam
- Writing a sound through an audio driver

It also defines typical APIs to interact with devices which might be present
in an house:

- `turn_lamp_on` to turn a lamp on
- `turn_lamp_of` to turn a lamp off

This library is used to create a tool called `fake-firmware` which collects
all APIs in a single binary.

## Versions

Two versions of this firmware has been produced. The first one contains all
`debug` symbols while the second one has all symbols stripped off.

Command to obtain the first version:

```bash
cargo build
```

Command to obtain the second version without any debug symbol

```bash
cargo build --release
```
