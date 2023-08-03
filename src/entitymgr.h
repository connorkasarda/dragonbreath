#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "entity.h"
#include <cassert>
#include <queue>

namespace DragonBreath
{
    class EntityManager
    {
        private:
            std::queue<Entity> m_entity_pool{};
            std::uint16_t m_num_entity_alive{};
        public:
            EntityManager();
            std::uint16_t getNumEntityAlive();
            Entity createEntity();
            void destroyEntity(Entity entity);
    };
}

#endif