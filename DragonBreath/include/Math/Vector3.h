/**
 * @file vector3.h
 * @brief vector with 3 dimensions and operations
 * 
 * @author Connor Kasarda
 * @date 2024-03-07
 */

#ifndef VECTOR3_H
#define VECTOR3_H

namespace dragonbreath
{
    /**
     * @brief holds x, y, z dimensions and provides operations
     */
    class Vector3
    {
    public:
        /**
         * @brief Constructor without parameters
         */
        Vector3() : x(0.0), y(0.0), z(0.0) {}

        /**
         * @brief Constructor with parameters
         *
         * @param x Value of x
         * @param y Value of y
         * @param z Value of z
         */
        Vector3(float _x,float _y,float _z) : x(_x), y(_y), z(_z) {}

        /**
        @brief The zero vector3
        */
        static const Vector3 zero;

        /**
        @brief The one vector3
        */
        static const Vector3 one;

        /**
         * @brief Add 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator+(Vector3 const& vector) const
        {
            return Vector3(x + vector.x, y + vector.y, z + vector.z);
        }

        /**
         * @brief Add-and-assign 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator+=(const Vector3& vector)
        {
            x += vector.x;
            y += vector.y;
            z += vector.z;

            return *this;
        }
        
        /**
         * @brief Sub 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator-(const Vector3& vector) const
        {
            return Vector3(x - vector.x, y - vector.y, z - vector.z);
        }
        
        /**
         * @brief Sub-and-assign vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator-=(const Vector3& vector)
        {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;

            return *this;
        }
        
        /**
         * @brief Multiply vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator*(const Vector3& vector) const
        {
            return Vector3(x * vector.x, y * vector.y, z * vector.z);
        }
        
        /**
         * @brief Multiply vector by scalar
         *
         * @param scalar Neighboring scalar
         * @return Resulting Vector3
         */
        Vector3 operator*(float scalar) const
        {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }
        
        /**
         * @brief Multiply-and-assign vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator*=(const Vector3& vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;

            return *this;
        }
        
        /**
         * @brief Divide vector by scalar
         *
         * @param scalar Neighboring scalar
         * @return Resulting Vector3
         */
        Vector3 operator/(float scalar)
        {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }
        
        /**
         * @brief Test equality of vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting boolean
         */
        bool operator==(const Vector3& vector) const
        {
            return x == vector.x && y == vector.y && z == vector.z;
        }
        
        /**
         * @brief Test inquality of vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting boolean
         */
        bool operator!=(const Vector3& vector) const
        {
            return x != vector.x || y != vector.y || z != vector.z;
        }
        
        /**
         * @brief Retrieves x value
         *
         * @return x value
         */
        float getX() const
        {
            return x;
        }
        
        /**
         * @brief Retrieves y value
         *
         * @return y value
         */
        float getY() const
        {
            return y;
        }
        
        /**
         * @brief Retrieves z value
         *
         * @return z value
         */
        float getZ() const
        {
            return z;
        }
        
        /**
         * @brief Sets x value
         *
         * @param x Desired x value
         */
        void setX(float _x)
        {
            x = _x;
        }
        
        /**
         * @brief Sets y value
         *
         * @param y Desired y value
         */
        void setY(float _y)
        {
            y = _y;
        }
        
        /**
         * @brief Sets z value
         *
         * @param z Desired z value
         */
        void setZ(float _z)
        {
            z = _z;
        }
    private:
        /**
         * @brief x value
         */
        float x {};
        
        /**
         * @brief y value
         */
        float y {};
        
        /**
         * @brief z value
         */
        float z {};
    }; // class Vector3
} // namespace dragonbreath

#endif // VECTOR3_H
