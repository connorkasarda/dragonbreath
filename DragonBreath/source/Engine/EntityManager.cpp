/**
 * @file entity_manager.cpp
 * @brief Manages pool of entities
 *
 * @author Connor Kasarda
 * @date 2024-01-29
 */

#include "Debug.h"
#include "EntityManager.h"

namespace dragonbreath
{   
    EntityManager::EntityManager() : numEntitiesAlive(0)
    {
        for (Entity entity = 0; entity < maxEntities; ++entity)
        {
            entityPool.push(entity);
        }
    }
    // ------------------------------------------------------------------------
    EntityManager::~EntityManager()
    {

    }
    // ------------------------------------------------------------------------
    Entity EntityManager::spawnEntity()
    {
        if (numEntitiesAlive == maxEntities)
        {
            DEV_ASSERT(false, "Max number of entities reached when attempting"\
                "spawnEntity function call");
            
            return invalidEntity;
        }

        Entity entity = entityPool.front();
        entityPool.pop();
        ++numEntitiesAlive;
        return entity;
    }
    // ------------------------------------------------------------------------
    void EntityManager::despawnEntity(Entity entity)
    {
        signatures[entity].reset();
        entityPool.push(entity);
        --numEntitiesAlive;
    }
    // ------------------------------------------------------------------------
    void EntityManager::setSignature(Entity entity, Signature signature)
    {
        signatures[entity] = signature;
    }
    // ------------------------------------------------------------------------
    Signature EntityManager::getSignature(Entity entity) const
    {
        return signatures[entity];
    }
} // namespace dragonbreath
