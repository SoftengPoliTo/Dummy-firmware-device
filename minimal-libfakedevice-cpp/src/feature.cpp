#include "../include/feature.h"

using namespace std;

extern "C" void writeOnDrive() {
    // Open a file named "foo.txt" for writing in binary mode
    ofstream file("foo.txt", ios::out | ios::binary);
    // Check if the file is successfully opened
    if (file.is_open()) {
        file << "Hello, world!\n";
        file << "Ciao, mondo!\n";
     	file.close();
    } else {
        // Print an error message if unable to open the file
        cerr << "Unable to open file for writing!" << endl;
    }
    return;
}

extern "C" void accessWebcam(const char* webcam_path) {
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



