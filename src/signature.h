#ifndef SIGNATURE_H
#define SIGNATURE_H

// File: signature.h
// Purpose: signature alias
// Author: Connor Logan Kasarda
// Date: 2023-08-15

#include <bitset>
#include "component.h"

namespace DragonBreath
{
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif