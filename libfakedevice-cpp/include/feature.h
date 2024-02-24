#ifndef FEATURE_H
#define FEATURE_H

#include <fstream> 
#include <iostream>
#include <cmath>
#include <thread>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include "RtAudio.h"
#include <cpr/cpr.h>


/**
 * Writes a new file in the current directory.
 * 
 * This function creates a new file named "foo.txt" in the current directory 
 * and writes the text "Hello, world!" to it. It prints a success message if
 * the operation is successful.
 */
extern "C" void writeOnDrive();

/**
 * Accesses the network and downloads the body of a webpage.
 * 
 * This function makes a GET request to a Rust web page (https://www.rust-lang.org/),
 * retrieves the body of the response, and prints it. It handles errors and prints
 * an error message if the HTTP status code is not 200.
 */
extern "C" void accessNetwork();

/**
 * Accesses the webcam and extracts some frames.
 * 
 * This function opens the specified webcam device file, configures the video format
 * for the webcam, sets up a buffer for reading video data, and reads 10 frames from
 * the webcam for demonstration purposes.
 * 
 * @param webcam_path The path to the webcam device file.
 */
extern "C" void accessWebcam(const char* webcam_path);

/**
 * Accesses the audio driver and outputs a beep sound.
 * 
 * This function uses the RtAudio library to access the default audio output device,
 * configure and start an audio stream, and play a sinusoidal beep sound for 2 seconds.
 * It handles errors and prints error messages if any occur during the process.
 */
extern "C" void accessAudioDriver();


#endif // FEATURES_H
