// File: entitymanager.cpp
// Purpose: entity manager class implementations
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include "entitymanager.h"

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
        // Add dragon assert HERE if debugging in development
        Entity entity = this->entityPool.front();
        this->entityPool.pop();
        ++this->numEntitiesAlive;
        return entity;
    }

    void EntityManager::destroyEntity(Entity entity)
    {
        // Add dragon assert HERE if debugging in development
        this->entityPool.push(entity);
        --this->numEntitiesAlive;
    }

    void EntityManager::setSignature(Entity entity, Signature signature)
    {
        // Add dragon assert HERE if debugging in development
        this->signatures[entity] = signature;
    }

    Signature EntityManager::getSignature(Entity entity)
    {
        // Add dragon assert HERE if debugging in development
        return this->signatures[entity];
    }
}