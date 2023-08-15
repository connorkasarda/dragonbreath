#ifndef COMPONENT_H
#define COMPONENT_H

// File: component.h
// Purpose: component aliases and constants
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <cstdint>

namespace DragonBreath
{
    using Component = std::uint8_t;
    const Component MAX_COMPONENTS = 128;
}

#endif