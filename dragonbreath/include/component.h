/**
 * @file component.h
 * @brief alias for types of components
 *
 * Defines the range of possible component types the ECS can support. In
 * addition, sets a max limit on number of component types allowed.
 * Similar to how an entity is just an ID, a component will just be a type.
 * However, it should be noted that the component defined here is just the
 * component types ID. The actual component is a struct created later.
 *
 * @author Connor Kasarda
 * @date 24 Jan 2024
 */

#ifndef COMPONENT_H
#define COMPONENT_H

namespace dragonbreath
{
    /**
     * @brief Index assigned to a component type
     *
     * The number of component types should be small, so using just 8 bits
     * for the possible range of component types is sufficient.
     */
    using Component = std::uint8_t;

    /**
     * @brief Maximum number of allowed component types
     *
     * Keeps range of component types small. May need to adjust in the future.
     */
    constexpr Component MAX_COMPONENTS = 64;
} // namespace dragonbreath

#endif // COMPONENT_H
