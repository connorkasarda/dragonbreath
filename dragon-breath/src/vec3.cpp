// File: vec3.cpp
// Purpose: defines a vector 3 component type
// Author: Connor Logan Kasarda
// Date: 2023-10-08

#include "vec3.h"

namespace dragonbreath
{
    Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f)
    {

    }
    Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z)
    {

    }
    Vec3 Vec3::operator+(Vec3 const& rhs) const
    {
        return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
    }
    Vec3 Vec3::operator-(Vec3 const& rhs) const
    {
        return Vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
    }
    Vec3 Vec3::operator*(Vec3 const& rhs) const
    {
        return Vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
    }
    Vec3 Vec3::operator/(Vec3 const& rhs) const
    {
        return Vec3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
    }
}