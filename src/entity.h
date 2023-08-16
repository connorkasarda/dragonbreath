#ifndef ENTITY_H
#define ENTITY_H

// File: entity.h
// Purpose: entity type aliases and constants
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include <cstdint>

namespace dragonbreath
{
    // Entities are only IDs
    using Entity = std::int16_t;
    const Entity MAX_ENTITIES = 2048;
}

#endif