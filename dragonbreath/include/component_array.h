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
#include "debug.h"
#include "entity.h"

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
    };// IComponentArray

    /**
     * @brief Template storage container class for components
     */
    template<typename T>
    class ComponentArray : public IComponentArray
    {
    public:
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
	void InsertData(Entity entity, const T& component)
	{
            DRAGON_ASSERT(
	        size == maxEntities,
		"components array full when insertion attempted");

	    size_t index = size;
            components[index] = component;

	    entity2IndexMap[entity] = index;
	    index2EntityMap[index] = entity;

	    ++size;
	}

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
	void RemoveData(Entity entity)
	{
	    DRAGON_ASSERT(
	        entity2IndexMap.find(entity) == entity2IndexMap.end(),
		"entity not found in entity2IndexMap using RemoveData");

	    // Efficiently transfer last component to now empty index
	    size_t indexOfRemovedEntity = entity2IndexMap[entity];
	    size_t lastIndex = size - 1;
	    components[indexOfRemovedEntity] =
	        std::move(components[lastIndex]);

	    // Update entity and index mappings for moved component
	    Entity entityOfMovedComponent = index2EntityMap[lastIndex];
	    entity2IndexMap[entityOfMovedComponent] = indexOfRemovedEntity;
	    index2EntityMap[indexOfRemovedEntity] = entityOfMovedComponent;

	    // Batch erase to reduce lookup operations and deletions
	    entity2IndexMap.erase(entity);
	    index2EntityMap.erase(lastIndex);
	
	    // Reduce size to allow overwrite of old last component copy
	    // when a new component is added in its place
	    --size;
	}

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
	T& GetData(Entity entity) const
	{
            // Get index with find call for function to be const-correct
            auto entity2IndexMapIter = entity2IndexMap.find(entity);
            if (entity2IndexMapIter != entity2IndexMap.end())
            {
                size_t indexOfEntity = entity2IndexMapIter->second;
		return components[indexOfEntity];
            }

	    DRAGON_ASSERT(
	        false,
		"entity not found in entity2IndexMap using GetData");

            return T {};
	}

	// TODO Is a function needed for when an entity is destroyed?
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

#endif // COMPONENT_ARRAY_H
