/**
 * @file physics.h
 * @brief The physics system
 * 
 * @author Connor Kasarda
 * @date 2024-03-07
 */

#ifndef PHYSICS_H
#define PHYSICS_H

#include "system.h"

namespace dragonbreath
{
    namespace systems
    {
        /**
         * @brief The physics system class
         *
         * Plays entities that have transforms, are affected by gravity, are
         * designated as rigid bodies, and so on. Will need to initialize the
         * objects and keep them updated every frame. Inherits from System to
         * ensure Physics has a set of entities to orchestrate.
         */
        class Physics : public engine::System
        {
            
        };
    } // namespace systems
} // namespace dragonbreath

#endif // namespace dragonbreath
