#include "LibSL.h"
#include <iostream>
#include <fstream>

int main() {
    const std::string filePath = "D:/PROjects/libsl-project/examples/badExample.lsl";

    if (LibSL::parseFromFile(filePath)) {

        return 0;

    } else {
        std::cerr << "Failed to parse file!" << std::endl;
        return 1;
    }
}