// Features APIs
use libfakedevice::features::access_audio_driver;
use libfakedevice::features::access_network;
use libfakedevice::features::access_webcam;
use libfakedevice::features::write_on_drive;

// Device APIs
use libfakedevice::device::turn_lamp_off;
use libfakedevice::device::turn_lamp_on;

// All features methods which must be searched within the firmware binary
// in order to produce the manifest information.
async fn features_apis() {
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
    features_apis().await;

    device_apis().await;
}
