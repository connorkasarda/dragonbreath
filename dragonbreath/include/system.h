/**
 * @file system.h
 * @brief Defines the base class that all systems inherit
 *
 * @author Connor Kasarda
 * @date 2024-02-23
 */

#include <set>
#include "entity.h"

namespace dragonbreath
{
    class System
    {
    public:
        /**
	 * @brief Inserts entity when signature matches this system
	 * 
	 * @param entity Entity assigned to system
	 */
	void entityAssigned(Entity entity);

	/**
	 * @brief Removes entity when entity is deleted
	 *
	 * @param entity Entity that was destroyed
	 */
	void entityDestroyed(Entity entity);
    protected:
	/**
	 * @brief Entities that system affects
	 *
	 * Remember, this is a super class to be inherited by all systems, so
	 * we need our entities to be accessible to the subclasses, AKA systems.
	 * The functionality that a set has is enough for inserting and
	 * deleting entities.
	 */
        std::set<Entity> mEntities;
    }; // class System
} // namespace dragonbreath
