// File: entity_manager.cpp
// Purpose: entity manager class implementations
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include "entity_manager.h"

namespace dragonbreath
{
    EntityManager::EntityManager()
    {
        for (Entity e = 0; e < MAX_ENTITIES; ++e)
        {
            this->entityPool.push(e);
        } 
    }

    EntityManager::~EntityManager()
    {
        while (!entityPool.empty())
        {
            this->entityPool.pop();
        }
    }

    std::int16_t EntityManager::GetNumEntitiesAlive()
    {
        return this->numEntitiesAlive;
    }

    Entity EntityManager::CreateEntity()
    {
        DRAGON_ASSERT
        (
            this->numEntitiesAlive < MAX_ENTITIES,
            "maximum number of alive entities reached"
        );
        Entity entity = this->entityPool.front();
        this->entityPool.pop();
        ++this->numEntitiesAlive;
        return entity;
    }

    void EntityManager::DestroyEntity(Entity entity)
    {
        this->signatures[entity].reset();
        this->entityPool.push(entity);
        --this->numEntitiesAlive;
    }

    void EntityManager::SetSignature(Entity entity, Signature signature)
    {
        this->signatures[entity] = signature;
    }

    Signature EntityManager::GetSignature(Entity entity)
    {
        return this->signatures[entity];
    }
}