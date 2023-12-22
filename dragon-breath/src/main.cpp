// File: main.cpp
// Purpose: main function for linker
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <iostream>
#include "coordinator.h"
#include "prompter.h"

const char* OPENAI_API_KEY = "<PUT KEY HERE>";
const char* OPENAI_API_URL = "<PUT URL HERE>";

int main(int argc, char** argv)
{
    std::cout << "DRAGONBREATH" << std::endl;
    dragonbreath::Coordinator coordinator;
    coordinator.Init();
    std::cout << "step 1.: coordinator initiated" << std::endl;
    dragonbreath::Prompter prompter(OPENAI_API_KEY, OPENAI_API_URL);
    std::cout << "step 2.: prompter initiated" << std::endl;
    return 0;
}
