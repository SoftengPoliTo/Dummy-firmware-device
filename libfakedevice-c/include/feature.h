#ifndef FEATURE_H
#define FEATURE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <math.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <time.h>
#include <unistd.h>
#include <linux/videodev2.h>
#include <curl/curl.h>



void writeOnDrive();
void accessNetwork();
void accessWebcam(const char* webcam_path);
void accessAudioDriver();

#endif // FEATURE_H
