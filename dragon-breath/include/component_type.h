#ifndef COMPONENT_TYPE_H
#define COMPONENT_TYPE_H

// File: component_type.h
// Purpose: component aliases and constants
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <cstdint>

namespace dragonbreath
{
    using ComponentType = std::int8_t;
    const ComponentType MAX_COMPONENTS = 32;
}

#endif