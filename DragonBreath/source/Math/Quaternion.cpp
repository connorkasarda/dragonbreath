#include "Quaternion.h"

namespace dragonbreath
{
    Quaternion::Quaternion() : x(0.0), y(0.0), z(0.0), w(1.0) {}
    // TODO Add the equivalent eulerAngles to start with
    // ------------------------------------------------------------------------
    Quaternion::Quaternion(float _x, float _y, float _z, float _w) : 
        x(_x), y(_y), z(_z), w(_w) {}
    // TODO Add the equivalent eulerAngles to start with
} // namespace dragonbreath
