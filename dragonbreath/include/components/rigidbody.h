/**
 * @file rigidbody.h
 * @brief Stores velocity, acceleration, and other physical properties
 * 
 * @author Connor Kasarda
 * @date 2024-03-09
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector3.h"

namespace dragonbreath
{
    namespace components
    {
        /**
         * @brief Displays physical properties of an object, especially motion
         */
        using RigidBody = struct
        {
            /**
             * @brief The x, y, z speed
             */
            math::Vector3 velocity {};

            /**
             * @brief The x, y, z acceleration
             */
            math::Vector3 Acceleration {};
        };
    } // namespace components
} // namespace dragonbreath

#endif // RIGIDBODY_H
