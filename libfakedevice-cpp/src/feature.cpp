#include "../include/feature.h"

using namespace std;

constexpr double PI = 3.14159265358979323846;

void writeOnDrive() {
    // Open a file named "foo.txt" for writing in binary mode
    ofstream file("foo.txt", ios::out | ios::binary);
    // Check if the file is successfully opened
    if (file.is_open()) {
        file.write("Hello, world!", 13);
        file.close();
        cout << "Successful writing to file!" << endl;
    } else {
        // Print an error message if unable to open the file
        cerr << "Unable to open file for writing!" << endl;
    }
    return;
}

void accessNetwork() {
    // Make a GET request to Rust web page
    auto response = cpr::Get(cpr::Url{"https://www.rust-lang.org/"});

    // Check for errors
    if (response.status_code == 200) {
        // Print the body of the response
        cout << "body = " << response.text << endl;
    } else {
        // Handle error
        cerr << "Error accessing network: ";
        cerr << "HTTP error code: " << response.status_code << endl;
    }
}

// Function for generating a sinusoidal signal
double generateSinusoidal(double sampleRate, double frequency, double time) {
    return sin(2.0 * PI * frequency * time / sampleRate);
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
        cerr << "No audio devices available." << endl;
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
    } catch (RtAudioErrorType& e) {
        cerr << "Audio playback failure." << endl;
    }

    // Wait a second to hear the sound
    this_thread::sleep_for(chrono::seconds(2));

    // Stop and close the audio stream
    try {
        audio.stopStream();
        audio.closeStream();
        cout << "Beep played correctly!" << endl;
    } catch (RtAudioErrorType& e) {
        cerr << "Failure to close the audio stream." << endl;
    }
    return;
}

void accessWebcam(const char* webcam_path) {
    // Open the webcam device file
    int fd = open(webcam_path, O_RDWR);
    if (fd == -1) {
        // Handle error if opening the device fails
        cerr << "Error opening device" << endl;
        return;
    }

    // Configure the video format for the webcam
    v4l2_format format{};
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix = {.width= 640, .height= 480, .pixelformat= V4L2_PIX_FMT_MJPEG};

    if (ioctl(fd, VIDIOC_S_FMT, &format) == -1) {
        // Handle error if configuring the format fails
        cerr << "Error configuring format" << endl;
        close(fd);
        return;
    }

    // Set up a buffer for reading video data
    constexpr int buffer_size = 640 * 480 * 3;
    char buffer[buffer_size];

    // Read video data from the webcam (for demonstration purposes, read 10 times)
    for (int i = 0; i < 10; ++i) {
        ssize_t bytesRead = read(fd, buffer, buffer_size);
        if (bytesRead == -1) {
            // Handle error if reading data fails
            cerr << "Error reading data" << endl;
            close(fd);
            return;
        }
    }
    // Close the webcam device file
    close(fd);
}
