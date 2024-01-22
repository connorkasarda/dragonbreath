#ifndef VEC_3_H
#define VEC_3_H

// File: vec3.h
// Purpose: defines a vector 3 component type
// Author: Connor Logan Kasarda
// Date: 2023-10-08

namespace dragonbreath
{
    class Vec3
    {
    public:
        Vec3();
        Vec3(float x, float y, float z);
        Vec3 operator+(Vec3 const& rhs) const;
        Vec3 operator-(Vec3 const& rhs) const;
        Vec3 operator*(Vec3 const& rhs) const;
        Vec3 operator/(Vec3 const& rhs) const;
    private:
        float x;
        float y;
        float z;
    };
}

#endif