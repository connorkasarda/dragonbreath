#ifndef ENTITY_H
#define ENTITY_H

// File: types.h
// Purpose: entity type aliases and constants
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <cstdint>

namespace DragonBreath
{
    // Entities are only IDs
    using Entity = std::uint16_t;
    const Entity MAX_ENTITIES = 2048;
}

#endif