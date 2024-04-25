/**
 * @file commander.cpp
 * @brief The captain of the ECS that gives commands to the managers
 *
 * @author Connor Kasarda
 * @date 2024-03-04
 */

#include "Commander.h"

namespace dragonbreath
{
    void Commander::init()
    {
        entityManager = std::make_unique<EntityManager>();
        componentManager = std::make_unique<ComponentManager>();
        systemManager = std::make_unique<SystemManager>();
    }
    // ------------------------------------------------------------------------
    Entity Commander::createEntity()
    {
        return entityManager->spawnEntity();
    }
    // ------------------------------------------------------------------------
    void Commander::destroyEntity(Entity entity)
    {
        entityManager->despawnEntity(entity);
        componentManager->entityDestroyed(entity);
        systemManager->entityDestroyed(entity);
    }
} // namespace dragonbreath
