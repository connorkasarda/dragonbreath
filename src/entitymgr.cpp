#include "entitymgr.h"

DragonBreath::EntityManager::EntityManager()
{
    for (Entity_t e = 0; e < MAX_ENTITIES; ++e)
    {
        m_EntityPool.push(e);
    }
}

uint16_t DragonBreath::EntityManager::getNumEntityAlive()
{
    return this->m_NumEntityAlive;
}