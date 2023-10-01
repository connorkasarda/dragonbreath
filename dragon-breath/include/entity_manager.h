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
    public:
        EntityManager();
        ~EntityManager();
        std::int16_t GetNumEntitiesAlive();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity);
    private:
        std::queue<Entity> entityPool{};
        std::int16_t numEntitiesAlive{};
        std::array<Signature, MAX_COMPONENTS> signatures{};
    };
}

#endif