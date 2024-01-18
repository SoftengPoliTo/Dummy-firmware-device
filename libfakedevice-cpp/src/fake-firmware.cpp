#include "../include/device.h"
#include "../include/features.h"

int main(){

    // Write something on drive
    writeOnDrive();

    // Accesses to the network and downloads the body of a webpage
    accessNetwork();

    // Access webcam
    accessWebcam("/dev/video0");

    // Access audio driver
    accessAudioDriver();
    
    // Turn a lamp on   
    turnLampOn();
    // Turn lamp off
    turnLampOff();

    return 0;
}
