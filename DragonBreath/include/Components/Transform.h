/**
 * @file transform.h
 * @brief Position, rotation, and scale of an entity in the virtual environment
 * 
 * @author Connor Kasarda
 * @date 2024-03-07
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector3.h"
#include "Quaternion.h"

namespace dragonbreath
{
    /**
    @brief Stores the position, orientation, and scale
    */
    using Transform = struct
    {
        /**
        @brief The x, y, z position of the object with respect to environment
        */
        Vector3 globalPosition {};
 
        /**
        @brief The w, x, y, z rotation of the object with respect to environment
        
        The rotation described in quaternions and can also give euler angles
        */
        Quaternion globalRotation {};
    };
} // namespace dragonbreath

#endif // TRANSFORM_H
