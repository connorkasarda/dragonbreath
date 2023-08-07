#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

// File: entity_manager.h
// Purpose: entity manager class declarations
// Author: Connor Logan Kasarda
// Date: 2023-8-6

#include <cassert>
#include <queue>
#include "entity.h"

namespace DragonBreath
{
    class EntityManager
    {
        private:
            std::queue<Entity> m_entity_pool{};
            Entity m_num_entities_alive{};
        public:
            EntityManager();
            Entity getNumEntitiesAlive();
            Entity createEntity();
            void destroyEntity(Entity entity);
    };
}

#endif