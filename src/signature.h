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
    // Keeps track of entity's components
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif