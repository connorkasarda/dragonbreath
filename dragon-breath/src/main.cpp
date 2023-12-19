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
    std::cout << "DRAGONBREATH" << std::endl;
    coordinator.Init();
    std::cout << "init step 1.: coordinator" << std::endl;
    CURL* curl = curl_easy_init();
    std::cout << "init step 2.: curl" << std::endl;
    return 0;
}
