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
 * @date 2024-01-24
 */

#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

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
     * @brief The name of the component type
     *
     * Unordered map key perfomance improves with const char* as opposed to
     * std::string. That's becauase it can be converted to a size_t, of which
     * allows the hashing to be more efficient. We are also grabbing the
     * component name from the template typename.
     */
    using ComponentName = const char *;

    /**
     * @brief Maximum number of allowed component types
     *
     * Keeps range of component types small. May need to adjust in the future.
     */
    constexpr std::int8_t kMaxComponents = 64;

    /**
     * @brief False value returned if component type not retrieved
     */
    constexpr ComponentType kInvalidComponentType = -1;
} // namespace dragonbreath

#endif // COMPONENT_H
