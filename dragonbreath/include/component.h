/**
 * @file component.h
 * @brief alias for types of components
 *
 * Defines the range of possible component types the ECS can support. In
 * addition, sets a max limit on number of component types allowed.
 * Components themselves are exterior to this file and are defined as structs
 * without behavior.
 *
 * @author Connor Kasarda
 * @date 24 Jan 2024
 */

#ifndef COMPONENT_H
#define COMPONENT_H

namespace dragonbreath
{
    /**
     * @brief The component type's unique identifier
     *
     * The number of component types should be small, so using just 8 bits
     * for the possible range of component types is sufficient.
     */
    using ComponentType = std::int8_t;

    /**
     * @brief Maximum number of allowed component types
     *
     * Keeps range of component types small. May need to adjust in the future.
     */
    constexpr std::int8_t maxComponents = 64;
} // namespace dragonbreath

#endif // COMPONENT_H
