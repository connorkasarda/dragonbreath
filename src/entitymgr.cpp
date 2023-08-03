#include "entitymgr.h"

DragonBreath::EntityManager::EntityManager()
{
    for (Entity e = 0; e < MAX_ENTITIES; ++e)
    {
        this->m_entity_pool.push(e);
    }
}

uint16_t DragonBreath::EntityManager::getNumEntityAlive()
{
    return this->m_num_entity_alive;
}

Entity DragonBreath::EntityManager::createEntity()
{
    assert(this->m_num_entity_alive < MAX_ENTITIES && "Too many entities.");
    Entity entity = this->m_entity_pool.front();
    this->m_entity_pool.pop();
    ++this->m_num_entity_alive;
    return entity;
}

void DragonBreath::EntityManager::destroyEntity(Entity entity)
{
    assert(entity < MAX_ENTITIES && "Entity out of range");
    this->m_entity_pool.push(entity);
    --this->m_num_entity_alive;
}