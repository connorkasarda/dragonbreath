/**
 * @file commander.h
 * @brief The captain of the ECS that gives commands to all of the managers
 *
 * @author Connor Kasarda
 * @date 2024-03-01
 */

#ifndef COMMANDER_H
#define COMMANDER_H

#include <memory>
#include "Entity.h"
#include "Signature.h"
#include "Component.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"

namespace dragonbreath
{
    /**
     * @brief The commanding class that directs all of the managers
     */
    class Commander
    {
    public:
        /**
         * @brief Initializes all of the managers' pointers
         */
        void init();

        /**
         * @brief Calls the entity manager to create an entity
         *
         * @return The entity that was spawned/created
         */
        Entity createEntity();

        /**
         * @brief Destroys an entity via entity manager
         *
         * @param entity The entity to destroy
         */
        void destroyEntity(Entity entity);

        /**
         * @brief Registers a new component type
         */
        template<typename T>
        void registerComponent();

        /**
         * @brief Adds a component that's tied to entity
         *
         * @param entity The entity component belongs to
         * @param component The component to add
         */
        template<typename T>
        void addComponent(Entity entity, T component);

        /**
         * @brief Removes a component
         *
         * @param component The component to be removed
         */
        template<typename T>
        void removeComponent(Entity entity);

        /**
         * @brief Retrieves the component
         *
         * @param entity The entity component is attached to
         * @return The component retrieved
         */
        template<typename T>
        const T& getComponent(Entity entity) const;

        /**
         * @brief Retrieves the component type
         */
        template<typename T>
        ComponentType getComponentType() const;

        /**
         * @brief registers a new system with ECS
         */
        template<typename T>
        std::shared_ptr<T> registerSystem();

        /**
         * @brief Sets the signature for the target system
         *
         * @param signature The signature to be set for target system
         */
        template<typename T>
        void setSystemSignature(Signature signature);
    private:
        /**
         * @brief Pointer to the entity manager
         */
        std::unique_ptr<EntityManager> entityManager {};

        /**
         * @brief Pointer to the component manager
         */
        std::unique_ptr<ComponentManager> componentManager {};

        /**
         * @brief Pointer to the system manager
         */
        std::unique_ptr<SystemManager> systemManager {};
    }; // class Commander
} // namespace dragonbreath

#include "Commander.tpp"

#endif // COMMANDER_H
