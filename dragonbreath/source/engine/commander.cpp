/**
 * @file commander.cpp
 * @brief The captain of the ECS that gives commands to the managers
 *
 * @author Connor Kasarda
 * @date 2024-03-04
 */

#include "commander.h"

namespace dragonbreath
{
    void Commander::Init()
    {
        mEntityManager = std::make_unique<EntityManager>();
        mComponentManager = std::make_unique<ComponentManager>();
        mSystemManager = std::make_unique<SystemManager>();
    }
    // ------------------------------------------------------------------------
    Entity Commander::createEntity()
    {
        return mEntityManager->spawnEntity();
    }
    // ------------------------------------------------------------------------
    void Commander::destroyEntity(Entity entity)
    {
        mEntityManager->despawnEntity(entity);
        mComponentManager->entityDestroyed(entity);
        mSystemManager->entityDestroyed(entity);
    }
} // namespace dragonbreath
