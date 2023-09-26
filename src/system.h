#ifndef SYSTEM_H
#define SYSTEM_H

// File: system.h
// Purpose: operates on list of entities with certain signature of components
// Author: Connor Logan Kasarda
// Date: 2023-09-26

#include <set>
#include "entity.h"

namespace dragonbreath
{
    class System
    {
    public:
        std::set<Entity> entities;
    };
}

#endif