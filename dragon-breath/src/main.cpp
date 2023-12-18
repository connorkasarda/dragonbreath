// File: main.cpp
// Purpose: main function for linker
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <iostream>
#include "coordinator.h"
#include "components.h"
#include <curl/curl.h>

dragonbreath::Coordinator coordinator;

int main(int argc, char** argv)
{
    coordinator.Init();
    std::cout << "coordinator initialized." << std::endl;
    return 0;
}
