// File: entitymanager.cpp
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

    std::int16_t EntityManager::getNumEntitiesAlive()
    {
        return this->numEntitiesAlive;
    }

    Entity EntityManager::createEntity()
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

    void EntityManager::destroyEntity(Entity entity)
    {
        this->signatures[entity].reset();
        this->entityPool.push(entity);
        --this->numEntitiesAlive;
    }

    void EntityManager::setSignature(Entity entity, Signature signature)
    {
        this->signatures[entity] = signature;
    }

    Signature EntityManager::getSignature(Entity entity)
    {
        return this->signatures[entity];
    }
}