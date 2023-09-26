#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

// File: component_manager.h
// Purpose: manages component arrays when component added or removed
// Author: Connor Logan Kasarda
// Date: 2023-09-25

#include <unordered_map>
#include <memory>
#include "component.h"
#include "component_array.h"

namespace dragonbreath
{
    class ComponentManager
    {
        private:
            std::unordered_map<const char*, Component> componentTypes{};
            std::unordered_map
            <
                const char*,
                std::shared_ptr<IComponentArray>
            >
            componentArrays{};
            Component nextComponentType{};
            template<typename T>
            std::shared_ptr<ComponentArray<T>> GetComponentArray()
            {
                const char* typeName = typeid(T).name();
                return std::static_pointer_cast<ComponentArray<T>>
                (
                    this->componentArrays[typeName]
                );
            }
        public:
            template<typename T>
            void RegisterComponent()
            {
                const char* typeName = typeid(T).name();
                this->componentTypes.insert
                (
                    {typeName, this->nextComponentType}
                );
                this->componentArrays.insert
                (
                    {typeName, std::make_shared<ComponentArray<T>>()}
                );
                ++nextComponentType;
            }
            template<typename T>
            Component GetComponentType()
            {
                const char* typeName = typeid(T).name();
                return this->componentTypes[typeName];
            }
            template<typename T>
            void AddComponent(Entity entity, T component)
            {
                GetComponentArray<T>()->InsertData(entity, component);
            }
            template<typename T>
            void RemoveComponent(Entity entity)
            {
                GetComponentArray<T>()->RemoveData(entity);
            }
            template<typename T>
            T& GetComponent(Entity entity)
            {
                return GetComponentArray<T>()->GetData(entity);
            }
            void DestroyEntity(Entity entity);
    };
}

#endif