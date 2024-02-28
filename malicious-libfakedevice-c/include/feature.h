#ifndef FEATURE_H
#define FEATURE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <linux/videodev2.h>
#include <curl/curl.h>


void writeOnDrive();
void accessWebcam(const char* webcam_path);


#endif // FEATURE_H
