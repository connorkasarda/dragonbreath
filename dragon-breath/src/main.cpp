// File: main.cpp
// Purpose: main function for linker
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <iostream>
#include "coordinator.h"
#include "prompter.h"

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <api_key> <api_url>" << std::endl;
        return 1;
    }
    const char* openaiAPIkey = argv[1];
    const char* openaiAPIURL = argv[2];
    std::cout << "DRAGONBREATH" << std::endl;
    std::cout << "    OPENAI" << std::endl;
    std::cout << "        API KEY: " << openaiAPIkey << std::endl;
    std::cout << "        API URL: " << openaiAPIURL << std::endl;
    std::cout << "    PROMPTER" << std::endl;
    dragonbreath::Prompter prompter(openaiAPIkey, openaiAPIURL);
    std::cout << "        CONSTRUCTED" << std::endl;
    std::cout << "    COORDINATOR" << std::endl;
    dragonbreath::Coordinator coordinator;
    coordinator.Init();
    std::cout << "        INITIALIZED" << std::endl;
    return 0;
}
