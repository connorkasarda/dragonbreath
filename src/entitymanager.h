#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

// File: entitymanager.h
// Purpose: entity manager class declarations
// Author: Connor Logan Kasarda
// Date: 2023-8-6

#include <queue>
#include <array>
#include "entity.h"
#include "signature.h"
#include "debug.h"

namespace dragonbreath
{
    class EntityManager
    {
        private:
            std::queue<Entity> entityPool{};
            std::int16_t numEntitiesAlive{};
            std::array<Signature, MAX_COMPONENTS> signatures{};
        public:
            EntityManager();
            ~EntityManager();
            std::int16_t getNumEntitiesAlive();
            Entity createEntity();
            void destroyEntity(Entity entity);
            void setSignature(Entity entity, Signature signature);
            Signature getSignature(Entity entity);
    };
}

#endif