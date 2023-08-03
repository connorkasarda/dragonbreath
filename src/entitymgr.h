#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstdint>
#include <cassert>
#include <queue>

namespace DragonBreath
{
    // Datatype alias for entities, where an entity is an ID number
    using EntityID = std::uint16_t;
    const EntityID MAX_ENTITIES = 2048;

    class EntityManager
    {
        private:
            std::queue<EntityID> m_EntityPool{};
            std::uint16_t m_NumEntityAlive{};
        public:
            EntityManager();
            std::uint16_t getNumEntityAlive();
    };
}

#endif