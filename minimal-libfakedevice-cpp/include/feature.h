#ifndef FEATURE_H
#define FEATURE_H

#include <fstream> 
#include <iostream>
#include <iostream>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <unistd.h>

extern "C" {
/*
*
 * Writes a new file in the current directory.
 * 
 * This function creates a new file named "foo.txt" in the current directory 
 * and writes the text "Hello, world!" to it. It prints a success message if
 * the operation is successful.
 */
void writeOnDrive();

/**
 * Accesses the webcam and extracts some frames.
 * 
 * This function opens the specified webcam device file, configures the video format
 * for the webcam, sets up a buffer for reading video data, and reads 10 frames from
 * the webcam for demonstration purposes.
 * 
 * @param webcam_path The path to the webcam device file.
 */
void accessWebcam(const char* webcam_path);

}

#endif // FEATURES_H
