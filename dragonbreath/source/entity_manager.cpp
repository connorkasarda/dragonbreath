/**
 * @file entity_manager.cpp
 * @brief Manages pool of entities
 *
 * @author Connor Kasarda
 * @date 29 Jan 2024
 */

#include "entity_manager.h"

namespace dragonbreath
{
    EntityManager::EntityManager()
    {
        for (Entity entity = 0; entity < maxEntities; ++entity)
        {
            entityPool.push(entity);
        }
    };
    // ------------------------------------------------------------------------
    EntityManager::~EntityManager()
    {

    }
    // ------------------------------------------------------------------------
    Entity EntityManager::SpawnEntity()
    {
        Entity entity = entityPool.front();
        entityPool.pop();
        ++numEntitiesAlive;
        return entity;
    }
    // ------------------------------------------------------------------------
    void EntityManager::DespawnEntity(Entity entity)
    {
        signatures[entity].reset();
        entityPool.push(entity);
        --numEntitiesAlive;
    }
    // ------------------------------------------------------------------------
    void EntityManager::SetSignature(Entity entity, Signature signature)
    {
        signatures[entity] = signature;
    }
    // ------------------------------------------------------------------------
    Signature EntityManager::GetSignature(Entity entity) const
    {
        return signatures[entity];
    }
} // namespace dragonbreath
