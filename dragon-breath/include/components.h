#ifndef COMPONENTS_H
#define COMPONENTS_H

// File: components.h
// Purpose: place where all component type structs are written
// Author: Connor Logan Kasarda
// Date: 2023-10-08

#include "vec3.h"

namespace dragonbreath
{
    struct Transform
    {
        Vec3 position;
        Vec3 rotation;
    };
}

#endif