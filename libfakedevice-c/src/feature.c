#include "../include/feature.h"

#define PI 3.14159265358979323846

void writeOnDrive() {
    FILE *file = fopen("foo.txt", "wb");
    if (file != NULL) {
        const char *data = "Hello, world!";
        fwrite(data, sizeof(char), 13, file);
        fprintf(stdout, "Successful writing to file!\n");
        fclose(file);
    } else {
        fprintf(stderr, "Unable to open file for writing!\n");
    }
}

void accessNetwork() {
    CURL *curl;
    CURLcode res;

    // Initialize cURL environment
    curl_global_init(CURL_GLOBAL_DEFAULT);
    // Initialize a cURL session
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.rust-lang.org");

        // Perform the HTTP request
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "Failed to access the network: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
    return;
}

void accessWebcam(const char* webcam_path) {
    // Open the webcam device file
    int fd = open(webcam_path, O_RDWR);
    if (fd == -1) {
        // Handle error if opening the device fails
        fprintf(stderr, "Error opening device\n");
        return;
    }

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
}


// Function for generating a sinusoidal signal
float generateSinusoidal(float frequency, float time) {
    return sin(2.0 * PI * frequency * time);
}

void audioCallback(ALuint buffer, ALuint source, ALuint sampleRate) {
    const float duration = 2.0;  // Duration of the beep in seconds
    const int numSamples = duration * sampleRate;
    float* sampleBuffer = malloc(numSamples * sizeof(float));

    if (!sampleBuffer) {
        fprintf(stderr, "Failed to allocate memory for the audio buffer\n");
        exit(EXIT_FAILURE);
    }

    // Generate a sinusoidal beep
    for (int i = 0; i < numSamples; ++i) {
        sampleBuffer[i] = generateSinusoidal(440.0, i / (float)sampleRate);
    }

    // Load the buffer with the generated samples
    alBufferData(buffer, AL_FORMAT_MONO16, sampleBuffer, numSamples * sizeof(float), sampleRate);
    free(sampleBuffer);

    // Attach the buffer to the source and play the sound
    alSourcei(source, AL_BUFFER, buffer);
    alSourcePlay(source);

    // Wait for the sound to finish
    sleep(duration);

    // Stop and detach the buffer
    alSourceStop(source);
    alSourcei(source, AL_BUFFER, 0);
}

void accessAudioDriver() {
    const ALCchar *deviceList = alcGetString(NULL, ALC_DEVICE_SPECIFIER);
    if (deviceList == NULL) {
        fprintf(stderr, "No audio devices found\n");
        exit(EXIT_FAILURE);
    }

    // Automatically choose the first available device
    const char *desiredDevice = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    if (*desiredDevice == '\0') {
        fprintf(stderr, "No audio devices found\n");
        exit(EXIT_FAILURE);
    }

    // Open the selected device
    ALCdevice* device = alcOpenDevice(desiredDevice);
    if (!device) {
        fprintf(stderr, "Failed to open audio device: %s\n", desiredDevice);
        exit(EXIT_FAILURE);
    }

    // Create a context and make it current
    ALCcontext* context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);

    ALenum error = alcGetError(device);
    if (error != ALC_NO_ERROR) {
        fprintf(stderr, "OpenAL error during context creation: %x\n", error);
        alcCloseDevice(device);
        exit(EXIT_FAILURE);
    }

    // Generate a buffer and source for the sound
    ALuint buffer, source;
    alGenBuffers(1, &buffer);
    alGenSources(1, &source);

    error = alGetError();
    if (error != AL_NO_ERROR) {
        fprintf(stderr, "OpenAL error during buffer and source generation: %x\n", error);
        alcMakeContextCurrent(NULL);
        alcDestroyContext(context);
        alcCloseDevice(device);
        exit(EXIT_FAILURE);
    }

    // Call the audio callback to play the sound
    audioCallback(buffer, source, 44100);

    // Delete the buffer and source
    alDeleteBuffers(1, &buffer);
    alDeleteSources(1, &source);

    error = alGetError();
    if (error != AL_NO_ERROR) {
        fprintf(stderr, "OpenAL error during buffer and source deletion: %x\n", error);
    }

    // Close the context and the device
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return;
}
