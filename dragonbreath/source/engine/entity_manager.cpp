/**
 * @file entity_manager.cpp
 * @brief Manages pool of entities
 *
 * @author Connor Kasarda
 * @date 2024-01-29
 */

#include "debug.h"
#include "entity_manager.h"

namespace dragonbreath
{
    namespace engine
    {
        EntityManager::EntityManager() : mNumEntitiesAlive(0)
        {
            for (Entity entity = 0; entity < kMaxEntities; ++entity)
            {
                mEntityPool.push(entity);
            }
        }
        // ------------------------------------------------------------------------
        EntityManager::~EntityManager()
        {

        }
        // ------------------------------------------------------------------------
        Entity EntityManager::spawnEntity()
        {
            if (mNumEntitiesAlive == kMaxEntities)
        {
                DEV_ASSERT(false, "Max number of entities reached when attempting"\
                "spawnEntity function call");
            return kInvalidEntity;
        }

            Entity entity = mEntityPool.front();
            mEntityPool.pop();
            ++mNumEntitiesAlive;
            return entity;
        }
        // ------------------------------------------------------------------------
        void EntityManager::despawnEntity(Entity entity)
        {
            mSignatures[entity].reset();
            mEntityPool.push(entity);
            --mNumEntitiesAlive;
        }
        // ------------------------------------------------------------------------
        void EntityManager::setSignature(Entity entity, Signature signature)
        {
            mSignatures[entity] = signature;
        }
        // ------------------------------------------------------------------------
        Signature EntityManager::getSignature(Entity entity) const
        {
            return mSignatures[entity];
        }
    } // namespace engine
} // namespace dragonbreath
