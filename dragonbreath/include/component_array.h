/**
 * @file component_array.h
 * @brief template storage container for a type of components
 *
 * @author Connor Kasarda
 * @date 1 Feb 2024
 */

#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include <utility>
#include <array>
#include <unordered_map>
#include "entity.h"

namespace dragonbreath
{
    /**
     * @brief Template storage container class for components
     */
    template<typename T>
    class ComponentArray
    {
    public:
        /**
	 * @brief Inserts component data for target entity
	 *
	 * When components regarding an entity are added, we must take
	 * care to update the mappings from entity to index and index
	 * to entity. Also, whenever a component is added, we simply
         * add it to the end of the array.
	 */
	void InsertData(Entity entity, T component)
	{
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
	 */
	void RemoveData(Entity entity)
	{
            auto entity2IndexMapIter = entity2IndexMap.find(entity);
            if (entity2IndexMapIter != entity2IndexMap.end())
            {
                // Efficiently transfer last component to now empty index
        	size_t indexOfRemovedEntity = entity2IndexMapIter->second;
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

		--size;
            }
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
	 * @return T Component data getting returned
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
            // Returns default constructed component for now...
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
#endif
