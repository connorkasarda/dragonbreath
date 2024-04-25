/**
 * @file vector3.cpp
 * @brief Vector with 3 dimensions and operations
 *
 * author Connor Kasarda
 * date 2024-03-07
 */

#include "Vector3.h"

namespace dragonbreath
{
    Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}
    // ------------------------------------------------------------------------
    Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    // ------------------------------------------------------------------------
    Vector3 Vector3::zero = Vector3(0.0, 0.0, 0.0);
    // ------------------------------------------------------------------------
    Vector3 Vector3::operator+(Vector3 const& vector) const
    {
        return Vector3(x + vector.x, y + vector.y, z + vector.z);
    }
    // ------------------------------------------------------------------------
    Vector3& Vector3::operator+=(Vector3 const& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;

        return *this;
    }
    // ------------------------------------------------------------------------
    Vector3 Vector3::operator-(const Vector3& vector) const
    {
        return Vector3(x - vector.x, y - vector.y, z - vector.z);
    }
    // ------------------------------------------------------------------------
    Vector3& Vector3::operator-=(const Vector3& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;

        return *this;
    }
    // ------------------------------------------------------------------------
    Vector3 Vector3::operator*(const Vector3& vector) const
    {
        return Vector3(x * vector.x, y * vector.y, z * vector.z);
    }
    // ------------------------------------------------------------------------
    Vector3 Vector3::operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
    // ------------------------------------------------------------------------
    Vector3& Vector3::operator*=(const Vector3& vector)
    {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;

        return *this;
    }
    // ------------------------------------------------------------------------
    Vector3 Vector3::operator/(float scalar)
    {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }
    // ------------------------------------------------------------------------
    bool Vector3::operator==(const Vector3& vector) const
    {
        return x == vector.x && y == vector.y && z == vector.z;
    }
    // ------------------------------------------------------------------------
    bool Vector3::operator!=(const Vector3& vector) const
    {
        return x != vector.x || y != vector.y || z != vector.z;
    }
    // ------------------------------------------------------------------------
    float Vector3::getX() const
    {
        return x;
    }
    // ------------------------------------------------------------------------
    float Vector3::getY() const
    {
        return y;
    }
    // ------------------------------------------------------------------------
    float Vector3::getZ() const
    {
        return z;
    }
    // ------------------------------------------------------------------------
    void Vector3::setX(float x)
    {
        this->x = x;
    }
    // ------------------------------------------------------------------------
    void Vector3::setY(float y)
    {
        this->y = y;
    }
    // ------------------------------------------------------------------------
    void Vector3::setZ(float z)
    {
        this->z = z;
    }
} // namespace dragonbreath
