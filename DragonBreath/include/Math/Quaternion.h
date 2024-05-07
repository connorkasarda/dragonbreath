#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
#include <string>

namespace dragonbreath
{
    /**
    Quaternions represent rotations in the following form: a + bi + cj + dk
        ~ Coefficients a, b, c, and d are real numbers
        ~ 1, i, j, and k are the basis {vectors, elements}
        ~ vector part: bi + cj + dk
        ~ scalar part: a

    Basis vectors meet the following requirements ...
        1. Basis vectors span the entire vector space's dimensionality
        2. Basis vectors are linearly independent
            Ex: v_1 = <1, 0> and v_2 = <2, 0> in 2D space ARE NOT linearly
                dependent
            Ex: v_3 = <1, 0> and v_4 = <0, 1> in 2D space ARE linearly
                dependent
        3. Every vector in the vector space can be represented as a unique
           combination of the basis vectors
            Ex: Let's say i = <1, 0> and j = <0, 1>
                Then v_5 = <3, 4> = 3i + 4j    
    */
    class Quaternion
    {
    public:
        /**
        @brief Constructor with no arguments passed
        */
        Quaternion() : w(0.0), x(0.0), y(0.0), z(0.0) {}
        // TODO Add initialization of euler angles
    
        /**
        @brief Constructor with w, x, y, z arguments passed
        */
        Quaternion(float _w, float _x, float _y, float _z)
            : w(_w), x(_x), y(_y), z(_z) {}
        // TODO Add initialization of euler angles

        /**

        */
        static const Quaternion identity;

        /**

        */
        static const Quaternion zero;

        /**
        @brief Quaternion representations can be retreived from the Body 3-2-1
        sequence. Where the body rotates performs a yaw (Body-Z), then a pitch
        (Body-Y), and finally a roll (Body-X).

        Hopefully eulerAngles is composed of radians!

        @param eulerAngles Vector3 containing the roll, pitch, and yaw

        @return the quaternion rotation representation from euler angles
        */
        static Quaternion fromEulerAngles(const Vector3& eulerAngles);

        /**
        @brief Produces a quaternion from roll, pitch, and yaw. All of which are the
        components of euler angles. Will do this in a Body 3-2-1 sequence.

        Also, need to make sure that roll, pitch, yaw angles are in radians!

        @param roll Float component for the x-wise rotation
        @param pitch Float component for the y-wise rotation
        @param yaw Float component for the z-wise rotation

        @return the quaternion rotation representation from roll, pitch, yaw
        */
        static Quaternion fromRollPitchYaw(float roll, float pitch, float yaw);

        /**
        @brief Produces a euler angle representation of the quaternion. Euler
        angles will consist of the roll, pitch, and yaw in radians.

        It is important to note that typically the quaternion needs to be
        normalized before it is converted into euler angles.

        @return the euler angle representation of the quaternion
        */
        Vector3 toEulerAngles() const;

        /**
        @brief Updates the quaternion's components after construction.

        @param w_ W component of the quaternion
        @param x_ X component of the quaternion
        @param y_ Y component of the quaternion
        @param z_ Z component of the quaternion
        */
        void set(float _w, float _x, float _y, float _z);

        /**
        @brief Produces a string representation of the quaternion's components.
        
        @return the quaternion in string format
        */
        std::string toString() const;
    private:
        /**

        */
        float w {};

        /**

        */
        float x {};

        /**

        */
        float y {};

        /**

        */
        float z {};
    }; // class Quaternion
} // namespace dragonbreath

#endif
