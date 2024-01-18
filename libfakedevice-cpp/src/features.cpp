#include <fstream>
#include <iostream>
#include <cmath>
#include <thread>
#include "RtAudio.h"
#include <curl/curl.h>
#include <opencv2/opencv.hpp>
#include "../include/features.h"

using namespace std;
using namespace cv;

constexpr double PI = 3.14159265358979323846;

void writeOnDrive() {
    ofstream file("foo.txt", ios::out | ios::binary);
    if (file.is_open()) {
        file.write("Hello, world!", 13);
        file.close();
    } else {
        cerr << "Unable to open file for writing!" << endl;
    }

    return;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

void accessNetwork() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.rust-lang.org");

        std::string body;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            std::cout << "body = " << body << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void accessWebcam(const std::string& webcam_path) {
    VideoCapture cap(webcam_path);
    if (!cap.isOpened()) {
        std::cerr << "Error opening webcam." << std::endl;
        return;
    }

    // Configure resolution and frame format
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    // Capture 10 frames from the webcam
    for (int i = 0; i < 10; ++i) {
        Mat frame;
        cap >> frame; 

        // Check if the frame is valid
        if (frame.empty()) {
            std::cerr << "Error capturing frame." << std::endl;
            return;
        }
    }
    cap.release();
    destroyAllWindows();
}

// Function for generating a sinusoidal signal
double generateSinusoidal(double sampleRate, double frequency, double time) {
    return std::sin(2.0 * PI * frequency * time / sampleRate);
}

// Callback function for audio output
int audioCallback(void* outputBuffer, void*, unsigned int nBufferFrames,
                  double streamTime, RtAudioStreamStatus status, void* userData) {
    double* buffer = static_cast<double*>(outputBuffer);
    double sampleRate = *static_cast<double*>(userData);

    // Generates a sinusoidal beep
    for (unsigned int i = 0; i < nBufferFrames; ++i) {
        buffer[i] = generateSinusoidal(sampleRate, 440.0, streamTime);
        streamTime += 1.0 / sampleRate;
    }

    return 0;
}

void accessAudioDriver() {
    RtAudio audio;
    if (audio.getDeviceCount() < 1) {
        std::cerr << "No audio devices available." << std::endl;
    }

    // Set the audio configuration
    RtAudio::StreamParameters parameters;
    parameters.deviceId = audio.getDefaultOutputDevice();
    parameters.nChannels = 1;
    unsigned int sampleRate = 44100;
    unsigned int bufferFrames = 512;

    // Configure and start the audio stream
    try {
        audio.openStream(&parameters, nullptr, RTAUDIO_FLOAT64, sampleRate, &bufferFrames,
                         &audioCallback, &sampleRate);
        audio.startStream();
    } catch (RtAudioError& e) {
        std::cerr << "Error: " << e.getMessage() << std::endl;
    }

    // Wait a second to hear the sound
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Stop and close the audio stream
    try {
        audio.stopStream();
        audio.closeStream();
    } catch (RtAudioError& e) {
        std::cerr << "Error: " << e.getMessage() << std::endl;
    }
    return;
}
