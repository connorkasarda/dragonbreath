/**
 * @file component_array.h
 * @brief template storage container for a type of components
 *
 * @author Connor Kasarda
 * @date 2024-02-01
 */

#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include <utility>
#include <array>
#include <unordered_map>
#include "Debug.h"
#include "Entity.h"

namespace dragonbreath
{
    /**
     * @brief Common interface for all types of component arrays
     *
     * Unavoidable situation with having a common interface for all
     * component arrays to use. Need this when iterating through every 
     * component array for each component type. Allows all component 
     * arrays to be stored in same list.
     */
    class IComponentArray
    {
    public:
        /**
         * @brief Destructor
         */
        virtual ~IComponentArray() = default;

        /**
         * @brief Common method to trigger when an entity is destroyed
         *
         * @param entity Entity that was destroyed
         */
        virtual void entityDestroyed(Entity entity) = 0;
    }; // class IComponentArray

    /**
     * @brief Template storage container class for components
     */
    template<typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        /**
         * @brief Constructor
         */
        ComponentArray();

        /**
         * @brief Inserts component data for target entity
         *
         * When components regarding an entity are added, we must take
         * care to update the mappings from entity to index and index
         * to entity. Also, whenever a component is added, we simply
         * add it to the end of the array.
         *
         * @param entity Entity of the component to insert
         * @param component Component data to insert
         */
        void insertData(Entity entity, const T& component);

        /**
         * @brief Removes component data regarding target entity
         *
         * To keep array tightly packed, the component in the last
         * index is shifted to the index of the removed component.
         * Take care to update the mappings and keep track of the
         * component array's size. When a component is removed, it's
         * just left in the array until it is overridden by a component
         * that's added in the future.
         *
         * @param entity Entity of component data to remove
         */
        void removeData(Entity entity);

        /**
         * @brief Retrieves the component data for entity
         *
         * Functions that simply retrieve data should remain const-correct
         * given that a retrieval should not change the state of the object.
         * However, if a key is not found, an unordered_map will add the key
         * and change the object. We don't want that. This is avoided by using
         * the find call on the unordered_map and checking first.
         *
         * @param entity Entity of component data to be returned
         * @return Component data getting returned
         */
        const T& getData(Entity entity) const;

        /**
         * @brief Called on the event of entity destruction
         *
         * @param entity Entity that was destroyed
         */
        void entityDestroyed(Entity entity) override;
    private:

        /**
         * @brief The array of components
         *
         * It's important we keep this array packed tightly for
         * the sake of efficiency. When a component needs to be
         * removed, last element will fill its place.
         */
        std::array<T, maxEntities> components {};

        /**
         * @brief Mapping from entity ID to component array index
         */
        std::unordered_map<Entity, size_t> entity2IndexMap {};

        /**
         * @brief Mapping from component array index to entity ID
         */
        std::unordered_map<size_t, Entity> index2EntityMap {};

        /**
         * @brief Size of the component array
         */
        size_t size {};
    }; // class ComponentArray
} // namespace dragonbreath

#include "ComponentArray.tpp"

#endif // COMPONENT_ARRAY_H
