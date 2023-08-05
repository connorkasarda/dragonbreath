#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cassert>
#include <queue>
#include "Entity.h"

namespace DragonBreath
{
    class EntityManager
    {
        private:
            std::queue<Entity> m_entity_pool{};
            std::uint16_t m_num_entities_alive{};
        public:
            EntityManager();
            std::uint16_t getNumEntitiesAlive();
            Entity createEntity();
            void destroyEntity(Entity entity);
    };
}

#endif