#include "../include/feature.h"

void writeOnDrive() {
    FILE *file = fopen("foo.txt", "wb");

    fclose(file);
}

