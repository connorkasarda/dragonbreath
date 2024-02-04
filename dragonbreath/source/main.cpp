/**
 * @file main.cpp
 * @brief The dragonbreath main program
 *
 * Runs dragonbreath ECS engine code.
 *
 * @author Connor Kasarda
 * @date 2024-01-25
 */

#include <iostream>
#include "dragonbreath.h"

int main(int argc, char** argv)
{
    if (argc != 1)
    {
        std::cerr << "usage: " << argv[0] << std::endl;
        return 1;
    }
    return 0;
}
