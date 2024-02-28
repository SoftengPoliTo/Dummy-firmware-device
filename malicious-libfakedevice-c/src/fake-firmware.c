#include "../include/device.h"
#include "../include/feature.h"

int main(){

    // Write something on drive
    writeOnDrive();

    // Access webcam
    accessWebcam("/dev/video0");
    
    // Turn a lamp on   
    turnLampOn();
    // Turn lamp off
    turnLampOff();

    return 0;
}
