// File: main.cpp
// Purpose: main function for linker
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <iostream>
#include "coordinator.h"
#include "components.h"

dragonbreath::Coordinator coordinator;

int main(int argc, char** argv)
{
    coordinator.Init();
    std::cout << "...coordinator initialized" << std::endl;
    // register a component of your own type!
    // std::cout << "...???? component registered" << std::endl;
    return 0;
}