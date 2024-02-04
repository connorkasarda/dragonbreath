/**
 * @file entity.h
 * @brief Defines a game object in the ECS
 *
 * An entity is an ID that indexes the game object. This ID can then be
 * referenced by a component or the system to provide a bearing.
 *
 * @author Connor Kasarda
 * @date 2024-01-24
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>

namespace dragonbreath
{
    /**
     * @brief Defines an entity as an unsigned integer within 32 bit range
     *
     * ECS currently supports a 16 bit range for indexing game objects.
     * However, game objects with 8, 32, and 64 bit sizing may be added later
     * to add flexibility. Thus, depending on resources available, performance
     * power, or just preference, the programmer using this package can define
     * the maximum number of game objects.
     */
    using Entity = std::int16_t;

    /**
     * @brief Sets the maximum limit for number of entities in simulation
     *
     * The number of max entities is defaulted to 10000 for the unsigned 16 bit
     * indexing range defined for game objects. Of course, this could be varied
     * in the future if the type alias Entity is defined with 8, 32, or 64 bits
     * instead of the default 16 bit range.
     */
    constexpr std::int16_t kMaxEntities = 10000;
} // namespace dragonbreath

#endif // ENTITY_H
