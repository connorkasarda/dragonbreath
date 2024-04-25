/**
 * @file rigidbody.h
 * @brief Stores velocity, acceleration, and other physical properties
 * 
 * @author Connor Kasarda
 * @date 2024-03-09
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3.h"

namespace dragonbreath
{
    /**
     * @brief Displays physical properties of an object, especially motion
     */
    using RigidBody = struct
    {
        /**
         * @brief The x, y, z speed
         */
        Vector3 velocity {};

        /**
         * @brief The x, y, z acceleration
         */
        Vector3 acceleration {};
    };
} // namespace dragonbreath

#endif // RIGIDBODY_H
