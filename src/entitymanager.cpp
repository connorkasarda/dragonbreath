// File: entity_manager.cpp
// Purpose: entity manager class implementations
// Author: Connor Logan Kasarda
// Date: 2023-08-06

#include "entitymanager.h"

dragonbreath::EntityManager::EntityManager()
{
    for (Entity e = 0; e < MAX_ENTITIES; ++e)
    {
        this->entityPool.push(e);
    }
}

dragonbreath::EntityManager::~EntityManager()
{
    while (!entityPool.empty())
    {
        this->entityPool.pop();
    }
}

std::int16_t dragonbreath::EntityManager::getNumEntitiesAlive()
{
    return this->numEntitiesAlive;
}

dragonbreath::Entity dragonbreath::EntityManager::createEntity()
{
    // Add dragon assert HERE if debugging in development
    Entity entity = this->entityPool.front();
    this->entityPool.pop();
    ++this->numEntitiesAlive;
    return entity;
}

void dragonbreath::EntityManager::destroyEntity(
    dragonbreath::Entity entity
)
{
    // Add dragon assert HERE if debugging in development
    this->entityPool.push(entity);
    --this->numEntitiesAlive;
}

void dragonbreath::EntityManager::setSignature(
    dragonbreath::Entity entity,
    dragonbreath::Signature signature
)
{
    // Add dragon assert HERE if debugging in development
    this->signatures[entity] = signature;
}

dragonbreath::Signature dragonbreath::EntityManager::getSignature(
    dragonbreath::Entity entity
)
{
    // Add dragon assert HERE if debugging in development
    return this->signatures[entity];
}