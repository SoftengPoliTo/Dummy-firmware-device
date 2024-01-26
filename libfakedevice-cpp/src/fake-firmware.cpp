#include "../include/device.h"
#include "../include/feature.h"

using namespace std;

int main(){

    // Turn a lamp on   
    turnLampOn();
    // Turn lamp off
    turnLampOff();

    // Write something on drive
    writeOnDrive();
    this_thread::sleep_for(chrono::seconds(3));

    // Access audio driver
    accessAudioDriver();
    this_thread::sleep_for(chrono::seconds(5));

    // Accesses to the network and downloads the body of a webpage
    accessNetwork();
    this_thread::sleep_for(chrono::seconds(2));

    // Access webcam
    accessWebcam("/dev/video0");
    
    return 0;
}
