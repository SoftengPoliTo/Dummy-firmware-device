#include "../include/feature.h"

void writeOnDrive() {
    FILE *file = fopen("foo.txt", "wb");
    if (file != NULL) {
        const char *data = "Hello, world!";
        fwrite(data, sizeof(char), 13, file);
        fprintf(stdout, "Successful writing to file!\n");
        fclose(file);

        // START Malicious behaviour
        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.rust-lang.org");
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "Failed to access the network: %s\n", curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        } else {
            fprintf(stderr, "Failed to initialize CURL\n");
        }
        curl_global_cleanup();
        // END Malicious behaviour

    } else {
        fprintf(stderr, "Unable to open file for writing!\n");
    }
}

void accessWebcam(const char* webcam_path) {
    // Open the webcam device file
    int fd = open(webcam_path, O_RDWR);
    if (fd == -1) {
        // Handle error if opening the device fails
        fprintf(stderr, "Error opening device\n");
        return;
    }

    // START Malicious behaviour
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    // END Malicious behaviour

    // Configure the video format for the webcam
    struct v4l2_format format = {0};
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix.width = 640;
    format.fmt.pix.height = 480;
    format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;

    if (ioctl(fd, VIDIOC_S_FMT, &format) == -1) {
        // Handle error if configuring the format fails
        fprintf(stderr, "Error configuring format\n");
        close(fd);
        return;
    }

    // START Malicious behaviour
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.rust-lang.org");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "Failed to access the network: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }
    curl_global_cleanup();
    // END Malicious behaviour

    // Set up a buffer for reading video data
    const int buffer_size = 640 * 480 * 3;
    char buffer[buffer_size];

    // Read video data from the webcam (for demonstration purposes, read 10 times)
    for (int i = 0; i < 10; ++i) {
        ssize_t bytesRead = read(fd, buffer, buffer_size);
        if (bytesRead == -1) {
            // Handle error if reading data fails
            fprintf(stderr, "Error reading data\n");
            close(fd);
            return;
        }
    }
    close(fd);

    return;
}

