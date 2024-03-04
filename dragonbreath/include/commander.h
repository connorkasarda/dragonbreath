/**
 * @file commander.h
 * @brief The captain of the ECS that gives commands to all of the managers
 *
 * @author Connor Kasarda
 * @date 2024-03-01
 */

#ifndef COMMANDER_H
#define COMMANDER_H

#include <memory>
#include "entity.h"
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"

namespace dragonbreath
{
    /**
     * @brief The commanding class that orchestrates ECS managers
     */
    class Commander
    {
    public:
        /**
	 * @brief Init function that prepares pointers to managers
	 */
	void Init();

        /**
	 * @brief spawns entity using the entity manager
	 */
	Entity spawnEntity();

	/**
	 * @brief removes entity using the entity manager
	 */
	void despawnEntity(Entity entity);

        // TODO
    private:
        /**
	 * @brief The entity manager
	 */
        std::unique_ptr<EntityManager> mEntityManager {};

	/**
	 * @brief The component manager
	 */
	std::unique_ptr<ComponentManager> mComponentManager {};
	
	/**
	 * @brief The system manager
	 */
	std::unique_ptr<SystemManager> mSystemManager {};
    }; // class Commander
} // namespace dragonbreath

#endif // COMMANDER_H
