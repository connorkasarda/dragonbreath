#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

// File: entity_manager.h
// Purpose: entity manager class declarations
// Author: Connor Logan Kasarda
// Date: 2023-8-6

#include <queue>
#include <array>
#include "entity.h"
#include "signature.h"

namespace dragonbreath
{
    class EntityManager
    {
        private:
            std::queue<Entity> entityPool{};
            Entity numEntitiesAlive{};
            std::array<Signature, MAX_COMPONENTS> signatures;
        public:
            EntityManager();
            ~EntityManager();
            Entity getNumEntitiesAlive();
            Entity createEntity();
            void destroyEntity(Entity entity);
            void setSignature(Entity entity, Signature signature);
            Signature getSignature(Entity entity);
    };
}

#endif