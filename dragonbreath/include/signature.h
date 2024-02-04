/**
 * @file signature.h
 * @brief The component signature of an Entity
 *
 * The signature type is designed to reveal what component types an entity has.
 * Can think of this as the entity's profile or fingerprint - the defining
 * component types of the entity.
 *
 * @author Connor Kasarda
 * @date 2024-01-25
 */

#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <bitset>
#include "component.h"

namespace dragonbreath
{
    /**
     * @brief The entities component genes
     *
     * Each entity will have a set of components that define them. This bitset
     * will provide the ECS with a way of telling which types of components
     * the entity has. This implies that each component has an id associated
     * with it, where the id is the index in the bitset. 0 meaning entity does
     * not have that component type, 1 meaning it does.
     */
    using Signature = std::bitset<maxComponents>;
} // namespace dragonbreath

#endif // SIGNATURE_H
