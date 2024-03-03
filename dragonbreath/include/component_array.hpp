/**
 * @file component_array.hpp
 * @brief template storage container for a type of components
 *
 * @author Connor Kasarda
 * @date 2024-02-01
 */

#ifndef COMPONENT_ARRAY_HPP
#define COMPONENT_ARRAY_HPP

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

	/**
	 * @brief Common method to trigger when an entity is destroyed
	 *
	 * @param entity Entity that was destroyed
	 */
	virtual void entityDestroyed(Entity entity) = 0;
    }; // IComponentArray

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
	ComponentArray() = default;

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
	void insertData(Entity entity, const T& component)
	{
	    if (mSize == kMaxEntities)
	    {
                DEV_ASSERT(
	            false,
		    "components array full when insertData called");
		return;
            }

	    size_t index = mSize;
            mComponents[index] = component;

	    mEntity2IndexMap.insert(std::make_pair(entity, index));
	    mIndex2EntityMap.insert(std::make_pair(index, entity));

	    ++mSize;
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
	void removeData(Entity entity)
	{
            auto entity2IndexMapIter = mEntity2IndexMap.find(entity);
	    if (entity2IndexMapIter == mEntity2IndexMap.end())
            {
	        DEV_ASSERT(
	            false,
		    "entity not found in entity2IndexMap using RemoveData");
		return;
            }

	    // Efficiently transfer last component to now empty index
	    size_t indexOfRemovedEntity = entity2IndexMapIter->second;
	    size_t lastIndex = mSize - 1;
	    mComponents[indexOfRemovedEntity] =
	        std::move(mComponents[lastIndex]);

	    // Update entity and index mappings for moved component
	    Entity entityOfMovedComponent = mIndex2EntityMap[lastIndex];
	    mEntity2IndexMap.insert(
	        std::make_pair(entityOfMovedComponent, indexOfRemovedEntity));
	    mIndex2EntityMap.insert(
	        std::make_pair(indexOfRemovedEntity, entityOfMovedComponent));

	    // Batch erase to reduce lookup operations and deletions
	    mEntity2IndexMap.erase(entity);
	    mIndex2EntityMap.erase(lastIndex);
	
	    // Reduce size to allow overwrite of old last component copy
	    // when a new component is added in its place
	    --mSize;
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
	const T& getData(Entity entity) const
	{
            // Get index with find call for function to be const-correct
            auto entity2IndexMapIter = mEntity2IndexMap.find(entity);
            if (entity2IndexMapIter != mEntity2IndexMap.end())
            {
                size_t indexOfEntity = entity2IndexMapIter->second;
		return mComponents[indexOfEntity];
            }

	    // Pass back a default empty component if desired component is not
	    // found in the map. Static value because we don't want repeated
	    // initialization but we want a consistent default value!
	    DEV_ASSERT(
	        false,
		"entity not found in entity2IndexMap using GetData");
            static const T defaultComponent {};
            return defaultComponent;
	}

        /**
	 * @brief Called on the event of entity destruction
	 *
	 * @param entity Entity that was destroyed
	 */
        void entityDestroyed(Entity entity) override
	{
            removeData(entity);
	}
    private:
	/**
	 * @brief The array of components
	 *
	 * It's important we keep this array packed tightly for
	 * the sake of efficiency. When a component needs to be
	 * removed, last element will fill its place.
	 */
	std::array<T, kMaxEntities> mComponents {};

	/**
	 * @brief Mapping from entity ID to component array index
	 */
	std::unordered_map<Entity, size_t> mEntity2IndexMap {};

	/**
	 * @brief Mapping from component array index to entity ID
	 */
	std::unordered_map<size_t, Entity> mIndex2EntityMap {};

        /**
	 * @brief Size of the component array
         */
        size_t mSize {};
    }; // class ComponentArray
} // namespace dragonbreath

#endif // COMPONENT_ARRAY_HPP
