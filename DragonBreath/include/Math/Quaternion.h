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
        inline Quaternion() : w(0.0), x(0.0), y(0.0), z(0.0) {}
    
        /**
        @brief Constructor with w, x, y, z arguments passed
        */
        inline Quaternion(float _w, float _x, float _y, float _z)
            : w(_w), x(_x), y(_y), z(_z) {}

        /**
        @brief the identity quaternion (denoted "1").

        Multiplying any quaternion q by the identity quaternion simply returns
        the same quaternion q:
                        
                                    1 * q = q * 1 = q

        I.e. the identity quaternion serves as a neutral element for quaternion
        multiplications.
        */
        static const Quaternion identity;

        /**
        @brief the zero quaternion (denoted "0").

        Adding the zero quaternion to any quaternion q results in the same
        quaternion q:

                                    0 + q = q + 0 = q

        The zero quaternion serves as an additive identity.
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
        @brief Performs quaternion multiplication.

        @param rhs The RHS quaternion

        @return Product of quaternion multiplication
        */
        Quaternion operator*(const Quaternion& rhs) const;
 
        /**
        @brief Checks equality between 2 quaternions.

        @param rhs The RHS quaternion

        @return Result of equality check
        */
        inline bool operator==(const Quaternion& rhs) const
        {
            return w == rhs.w &&
                   x == rhs.x &&
                   y == rhs.y &&
                   z == rhs.z;
        }        

        /**
        @brief Converts the components of this quaternion such that this
        quaternion's resulting magnitude equals 1.

        To do compute this, we need to divide each component by the magnitude
        of the quaternion, denoted ||q|| = sqrt(w^2 + x^2 + y^2 + z^2). Thus,
        the versor v (normalized quaternion) is equal to this:

                                    v = q / ||q||

        This function manipulates the components of this quaternion internally.
        */
        void normalize();

        /**
        @brief Produces a new quaternion that represents the normalized version
        of this quaternion without changing any of the internal components.

        This is used with the toEulerAngles() function such that we get this
        quaternion's normalized form without changing the internals.

        @return the normalized quaternion
        */
        Quaternion toNormalized() const;

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
        inline void set(float _w, float _x, float _y, float _z)
        {
            w = _w;
            x = _x;
            y = _y;
            z = _z;
        }

        /**
        @brief Produces a string representation of the quaternion's components.
        
        @return the quaternion in string format
        */
        std::string toString() const;
    private:
        /**
        @brief w is the scalar value or real part simply multiplied by 1
        */
        float w {};

        /**
        @brief x is the coefficient multiplied by the quaternion unit i
        */
        float x {};

        /**
        @brief y is the coefficient multiplied by the quaternion unit j
        */
        float y {};

        /**
        @brief z is the coefficient multiplied by the quaternion unit k
        */
        float z {};
    }; // class Quaternion
} // namespace dragonbreath

#endif
