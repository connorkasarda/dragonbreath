#ifndef SIGNATURE_H
#define SIGNATURE_H

// File: signature.h
// Purpose: signature alias
// Author: Connor Logan Kasarda
// Date: 2023-08-15

#include <bitset>
#include "component.h"

namespace dragonbreath
{
    // Keeps track of which components an entity has
    // Example:
        // Transform = bit 0
        // RigidBody = bit 1
        // Gravity = bit 2
        // and so on ...
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif