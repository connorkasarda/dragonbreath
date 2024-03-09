/**
 * @file transform.h
 * @brief Position, rotation, and scale of an entity in the virtual environment
 * 
 * @author Connor Kasarda
 * @date 2024-03-07
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3.h"

namespace dragonbreath
{
    namespace components
    {
        /**
         * @brief Stores the position, orientation, and scale
         */
        using Transform = struct
        {
            /**
             * @brief The x, y, z position of the object
             */
            math::Vector3 position {};
     
            /**
             * @brief The x, y, z rotation of the object
             */
            math::Vector3 rotation {};
        };
    } // namespace components
} // namespace dragonbreath

#endif // TRANSFORM_H
