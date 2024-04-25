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
        Vector3();

        /**
         * @brief Constructor with parameters
         *
         * @param x Value of x
         * @param y Value of y
         * @param z Value of z
         */
        Vector3(float x, float y, float z);

        /**
        @brief The zero vector3
        */
        static Vector3 zero;

        /**
         * @brief Add 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator+(Vector3 const& vector) const;

        /**
         * @brief Add-and-assign 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator+=(const Vector3& vector);
        
        /**
         * @brief Sub 3D vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator-(const Vector3& vector) const;
        
        /**
         * @brief Sub-and-assign vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator-=(const Vector3& vector);
        
        /**
         * @brief Multiply vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3 operator*(const Vector3& vector) const;
        
        /**
         * @brief Multiply vector by scalar
         *
         * @param scalar Neighboring scalar
         * @return Resulting Vector3
         */
        Vector3 operator*(float scalar) const;
        
        /**
         * @brief Multiply-and-assign vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting Vector3
         */
        Vector3& operator*=(const Vector3& vector);
        
        /**
         * @brief Divide vector by scalar
         *
         * @param scalar Neighboring scalar
         * @return Resulting Vector3
         */
        Vector3 operator/(float scalar);
        
        /**
         * @brief Test equality of vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting boolean
         */
        bool operator==(const Vector3& vector) const;
        
        /**
         * @brief Test inquality of vectors
         *
         * @param vector Neighboring Vector3
         * @return Resulting boolean
         */
        bool operator!=(const Vector3& vector) const;
        
        /**
         * @brief Retrieves x value
         *
         * @return x value
         */
        float getX() const;
        
        /**
         * @brief Retrieves y value
         *
         * @return y value
         */
        float getY() const;
        
        /**
         * @brief Retrieves z value
         *
         * @return z value
         */
        float getZ() const;
        
        /**
         * @brief Sets x value
         *
         * @param x Desired x value
         */
        void setX(float x);
        
        /**
         * @brief Sets y value
         *
         * @param y Desired y value
         */
        void setY(float y);
        
        /**
         * @brief Sets z value
         *
         * @param z Desired z value
         */
        void setZ(float z);
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
