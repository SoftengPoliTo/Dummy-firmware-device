#include "../include/feature.h"

using namespace std;

int main(){

    // Write something on drive
    writeOnDrive();
    
    // Access webcam
    accessWebcam("/dev/video0");

    return 0;
}
