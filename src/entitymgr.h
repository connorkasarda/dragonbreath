#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstdint>
#include <cassert>
#include <queue>

namespace DragonBreath
{
    using Entity_t = std::uint16_t;
    const Entity_t MAX_ENTITIES = 2048;

    class EntityManager
    {
        private:
            std::queue<Entity_t> m_EntityPool{};
            std::uint16_t m_NumEntityAlive{};
        public:
            EntityManager();
            std::uint16_t getNumEntityAlive();
    };
}

#endif