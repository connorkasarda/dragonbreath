/**
 * @file component_array.h
 * @brief template storage container for some type of components
 *
 * @author Connor Kasarda
 * @date 1 Feb 2024
 */

#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

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
		 * to entity.
		 */
		void InsertData(Entity entity, T component)
		{
			// Place new component at last index
			size_t index = size;
			components[index] = component;

			// Update entity and index mappings
			entity2Index[entity] = index;
			index2Entity[index] = entity;

			// Update array size information
			++size;
		}

		/**
		 * @brief Removes component data regarding target entity
		 *
		 * To keep array tightly packed, the component in the last
		 * index is shifted to the index of the removed component.
		 */
		void RemoveData(Entity entity)
		{
			// Swap removed component with last component
			size_t index2Replace = entity2IndexMap[entity];
			size_t lastIndex = size - 1;
			components[index2Replace] = components[lastIndex];
			
			// Update mappings for moved component
			entityOfMovedComponent = index2Entity[lastIndex];
			entity2IndexMap[entityOfMovedComponent] = index2Replace;
			index2EntityMap[index2Replace] = entityOfMovedComponent;

			// Remove old mappings
			entity2IndexMap[entity].erase();
			index2EntityMap[lastIndex].erase();

			// Update array size information
			--size;
		}

		/**
		 * @brief Retrieves the component data for entity
		 *
		 * @return T Component data getting returned
		 */
		T& GetData(Entity entity)
		{
			size_t indexOfEntity = entity2IndexMap[entity];
			return components[indexOfEntity];
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
	}

#endif
