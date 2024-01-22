// File: main.cpp
// Purpose: main function for linker
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <iostream>
#include "coordinator.h"

int main(int argc, char** argv)
{
    if (argc != 1) {
        std::cerr << "usage: " << argv[0] << std::endl;
        return 1;
    }
    dragonbreath::Coordinator coordinator;
    coordinator.Init();
    return 0;
}
