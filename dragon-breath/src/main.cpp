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
    coordinator.RegisterComponent<dragonbreath::Transform>();
    std::cout << "...transform component registered" << std::endl;
    return 0;
}