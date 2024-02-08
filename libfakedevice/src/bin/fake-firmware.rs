// Features APIs
use libfakedevice::features::access_audio_driver;
use libfakedevice::features::access_network;
use libfakedevice::features::access_webcam;
use libfakedevice::features::write_on_drive;

// Device APIs
use libfakedevice::device::turn_lamp_off;
use libfakedevice::device::turn_lamp_on;

// A method defined directly in the firmware and not in the library.
pub fn write_on_drive_from_firmware() -> std::io::Result<()> {
    use std::fs::File;
    use std::io::prelude::*;

    let mut file = File::create("foo_firmware.txt")?;
    file.write_all(b"Hello, world!")?;
    Ok(())
}

pub async fn features_apis() {
    // Write something on drive
    write_on_drive().unwrap();

    // Access the network downloading the content of a page
    access_network().await.unwrap();

    // Access webcam
    access_webcam("/dev/video0").unwrap();

    // Access audio driver
    access_audio_driver();
}

async fn device_apis() {
    // Turn a lamp on
    turn_lamp_on().await;

    // Turn lamp off
    turn_lamp_off().await;
}

#[tokio::main]
async fn main() {
    write_on_drive_from_firmware().unwrap();

    features_apis().await;

    device_apis().await;
}
