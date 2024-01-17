#include <fstream>
#include <iostream>
#include "../include/features.hpp"

using namespace std;

void writeOnDrive() {
    ofstream file("foo.txt", ios::out | ios::binary);
    if (file.is_open()) {
        file.write("Hello, world!", 13);
        file.close();
    } else {
        cerr << "Unable to open file for writing!" << endl;
    }

    return;
}
