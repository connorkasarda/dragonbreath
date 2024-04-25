/**
 * @file component_manager.h
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-02-07
 */

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <memory>
#include <unordered_map>
#include "Component.h"
#include "ComponentArray.h"

namespace dragonbreath
{
    /**
     * @brief Manages all of the registered components of the ECS
     */
    class ComponentManager
    {
    public:
        /**
         * @brief Constructor
         */
        ComponentManager();

        /**
         * @brief Destructor
         */
        ~ComponentManager();

        /**
         * @brief Registers a new component type
         *
         * Typically, wouldn't want to use typeid(T).name() because it can be
         * unpredictable and far from human readable. However, the output is
         * not for the eyes of a human -- just the computer. Therefore, its
         * use here is okay.
         */
        template<typename T>
        void registerComponent();

        /**
         * @brief Adds component to the appropriate component array
         *
         * @param entity Entity component belongs to
         * @param component Component to add to component array
         */
        template<typename T>
        void addComponent(Entity entity, T component);

        /**
         * @brief Removes component from the appropriate component array
         *
         * @param component Component to be removed
         */
        template<typename T>
        void removeComponent(Entity entity);

        /**
         * @brief Retrieves the target component from component array
         *
         * @param entity The entity component is attached to
         */
        template<typename T>
        const T& getComponent(Entity entity) const;
        
        /**
         * @brief Retrieves the component type
         *
         * @return The component type
         */
        template<typename T>
        ComponentType getComponentType() const;

        /**
         * @brief Called whenever an entity is destroyed to trigger removal
         *
         * @param entity Entity that was destroyed
         */
        void entityDestroyed(Entity entity);
    private:
        /**
         * @brief Mapping from component type name to the component type
         */
        std::unordered_map<ComponentName, ComponentType> name2TypeMap {};

        /**
         * @brief Mapping from component type name to the component array
         */
        std::unordered_map<ComponentName, std::shared_ptr<IComponentArray>>
            name2ArrayMap {};

        /**
         * @brief Keeps track of the component types
         *
         * Latest value is assigned to newly assigned component. Works
         * similarly to a counter.
         */
        ComponentType componentTypeIDAssigner {};

        /**
         * @brief Helper function returning the component array based on T
         *
         * We need to do this with care. Since polymorphism was used to allow
         * all specialized ComponentArray objects to be stored in the same
         * mapping, the shared_ptr to the IComponentArray needs to be
         * downcasted so that the shared_ptr has the derived classes info in
         * the form of ComponentArray<T>.
         *
         * @return shared pointer to the specialized component array
         */
        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray() const;
    }; // class ComponentManager
} // namespace dragonbreath

#include "ComponentManager.tpp"

#endif // COMPONENT_MANAGER_H
