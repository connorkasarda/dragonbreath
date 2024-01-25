/**
 * @file profile.h
 * @brief The component profile of an Entity
 *
 * The profile type is designed to reveal what component types an entity has.
 * Can think of this as the entity's signature or fingerprint - the defining
 * components of the entity.
 *
 * @author Connor Kasarda
 * @date 25 Jan 2024
 */

#ifndef PROFILE_H
#define PROFILE_H

#include <bitset>
#include "component.h"

namespace dragonbreath
{
    /**
     * @brief The entities component genes
     *
     * Each entity will have a set of components that define them. This bitset
     * will provide the system with a way of telling which types of components
     * the entity has. This implies that each component has an id associated
     * with it, where the id is the index in the bitset. 0 meaning entity does
     * not have that component type, 1 meaning it does.
     */
    using Profile = std::bitset<MAX_COMPONENT_TYPES>;
} // namespace dragonbreath

#endif // PROFILE_H
