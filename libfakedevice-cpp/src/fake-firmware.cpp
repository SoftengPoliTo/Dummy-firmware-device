#include "../include/device.h"
#include "../include/features.h"

int main(){

    // Turn a lamp on   
    turnLampOn();
    // Turn lamp off
    turnLampOff();

    // Write something on drive
    writeOnDrive();

    // Access audio driver
    accessAudioDriver();

    // Accesses to the network and downloads the body of a webpage
    accessNetwork();

    // Access webcam
    accessWebcam("/dev/video1");
    
    return 0;
}
