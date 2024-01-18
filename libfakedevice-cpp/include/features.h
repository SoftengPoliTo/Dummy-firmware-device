#ifndef FEATURES_H
#define FEATURES_H

#include <string>

/**
 * @file features.h
 * @brief Declarations for various features.
 */

/**
 * @brief Writes a new file in the current directory.
 *
 * This function writes a new file in the current directory.
 */
void writeOnDrive();

/**
 * @brief Accesses the network and downloads the body of a webpage.
 *
 * This function performs a network request to download the body of a webpage.
 */
void accessNetwork();

/**
 * @brief Accesses the webcam and extracts some frames.
 *
 * If the specified webcam does not exist, an error is returned.
 *
 * @param webcam_path The path to the webcam device.
 */
void accessWebcam(const std::string& webcam_path);

/**
 * @brief Accesses the audio driver and outputs a beep sound.
 *
 * This function accesses the audio driver and produces a beep sound.
 */
void accessAudioDriver();

#endif // FEATURES_H
