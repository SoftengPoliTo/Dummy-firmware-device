/// Writes a new file in the current directory
pub fn write_on_drive() -> std::io::Result<()> {
    use std::fs::File;
    use std::io::prelude::*;

    let mut file = File::create("foo.txt")?;
    file.write_all(b"Hello, world!")?;
    Ok(())
}

/// Accesses to the network and downloads the body of a webpage
pub async fn access_network() -> reqwest::Result<()> {
    // Get the boy of the main Rust webpage
    let body = reqwest::get("https://www.rust-lang.org")
        .await?
        .text()
        .await?;

    // Print the main Rust page on stdout
    println!("body = {:?}", body);

    Ok(())
}

/// Accesses to webcam and extracts some frames.
///
/// If a webcam does not exist, it returns an error.
pub fn access_webcam(webcam_path: &str) -> rscam::Result<()> {
    // Creates a new context
    let mut webcam = rscam::new(webcam_path)?;

    // Access to webcam using a specific configuration
    webcam.start(&rscam::Config {
        interval: (1, 30), // 30 fps.
        resolution: (640, 480),
        format: b"MJPG",
        ..Default::default()
    })?;

    // Capture 10 frames from webcam
    for _ in 0..10 {
        webcam.capture()?;
    }

    Ok(())
}

/*/// Accesses to the audio driver and outputs a beep sound
pub fn access_audio_driver() {
    // Retrieve host
    let host = cpal::default_host();

    // Retrieve device
    let device = host.default_output_device().unwrap();

    // Retrieve device configuration
    let config = device.default_output_config().unwrap();

    // Run beep according to sample format accepted by the retrieved device
    match config.sample_format() {
        cpal::SampleFormat::I8 => run::<i8>(&device, &config.into()),
        cpal::SampleFormat::I16 => run::<i16>(&device, &config.into()),
        cpal::SampleFormat::I32 => run::<i32>(&device, &config.into()),
        cpal::SampleFormat::I64 => run::<i64>(&device, &config.into()),
        cpal::SampleFormat::U8 => run::<u8>(&device, &config.into()),
        cpal::SampleFormat::U16 => run::<u16>(&device, &config.into()),
        cpal::SampleFormat::U32 => run::<u32>(&device, &config.into()),
        cpal::SampleFormat::U64 => run::<u64>(&device, &config.into()),
        cpal::SampleFormat::F32 => run::<f32>(&device, &config.into()),
        cpal::SampleFormat::F64 => run::<f64>(&device, &config.into()),
        sample_format => panic!("Unsupported sample format '{sample_format}'"),
    }
}

use cpal::{
    traits::{DeviceTrait, HostTrait, StreamTrait},
    FromSample, Sample, SizedSample,
};

fn run<T>(device: &cpal::Device, config: &cpal::StreamConfig)
where
    T: SizedSample + FromSample<f32>,
{
    // Retrieve sample rate
    let sample_rate = config.sample_rate.0 as f32;
    // Retrieve device channels
    let channels = config.channels as usize;

    // Produce a sinusoid of maximum amplitude.
    let mut sample_clock = 0f32;
    let mut next_value = move || {
        sample_clock = (sample_clock + 1.0) % sample_rate;
        (sample_clock * 440.0 * 2.0 * std::f32::consts::PI / sample_rate).sin()
    };

    let err_fn = |err| eprintln!("an error occurred on stream: {}", err);

    // Send the sinusoid of maximum amplitude as a stream to the device
    let stream = device
        .build_output_stream(
            config,
            move |data: &mut [T], _: &cpal::OutputCallbackInfo| {
                write_data(data, channels, &mut next_value)
            },
            err_fn,
            None,
        )
        .unwrap();

    // Play the data content present in the buffer
    stream.play().unwrap();

    // Stop the thread for one second in order to check out the latencies
    std::thread::sleep(std::time::Duration::from_millis(1000));
}

fn write_data<T>(output: &mut [T], channels: usize, next_sample: &mut dyn FnMut() -> f32)
where
    T: Sample + FromSample<f32>,
{
    // Write each sample on the data frame retrieved dividing the output buffer
    // according to the output channels
    for frame in output.chunks_mut(channels) {
        let value: T = T::from_sample(next_sample());
        for sample in frame.iter_mut() {
            *sample = value;
        }
    }
}*/
