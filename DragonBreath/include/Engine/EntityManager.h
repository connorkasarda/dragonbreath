/**
 * @file entity_manager.h
 * @brief Manages pool of entities
 *
 * @author Connor Kasarda
 * @date 2024-01-29
 */

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <array>
#include <queue>
#include "Entity.h"
#include "Signature.h"

namespace dragonbreath
{
    /**
     * @brief The entity manager class that orchestrates a pool of entities
     */
    class EntityManager
    {
    public:
        /**
         * @brief Constructor
         *
         * The pool of entities is populated first so that they are created
         * and ready to go as needed.
         */
        EntityManager();

        /**
         * @brief Destructor
         */
        ~EntityManager();

        /**
         * @brief Dequeues entity on standby and creates it
         *
         * @return entity The spawned entity
         */
        Entity spawnEntity();

        /**
         * @brief Destroys alive entity and enqueues to pool
         */
        void despawnEntity(Entity entity);

        /**
         * @brief Sets the signature for an entity
         */
        void setSignature(Entity entity, Signature signature);

        /**
         * @brief Retrieves the signature of an entity
         *
         * @return signature The entity's signature
         */
        Signature getSignature(Entity entity) const;
    private:
        /**
         * @brief Entities that are on standby
         */
        std::queue<Entity> entityPool {};

        /**
         * @brief The signatures for each entity
         */
        std::array<Signature, maxEntities> signatures {};

        /**
         * @brief The number of live entities
         */
        std::int16_t numEntitiesAlive {};
    }; // class Entity Manager
} // namespace dragonbreath

#endif // ENTITY_MANAGER_H
