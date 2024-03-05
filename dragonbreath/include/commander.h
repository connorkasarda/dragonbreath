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
#include "entity.h"
#include "signature.h"
#include "component.h"
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"

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
        void Init();

        /**
         * @brief Calls the entity manager to create an entity
         *
         * @return The entity that was spawned/created
         */
        Entity createEntity();

        /**
         * @brief Destroys an entity via entity manager
         */
        void destroyEntity();

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
        void removeComponent(T component);

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
        std::unique_ptr<EntityManager> mEntityManager {};

        /**
         * @brief Pointer to the component manager
         */
        std::unique_ptr<ComponentManager> mComponentManager {};

        /**
         * @brief Pointer to the system manager
         */
        std::unique_ptr<SystemManager> mSystemManager {};
    }; // class Commander
} // namespace dragonbreath

#endif // COMMANDER_H
