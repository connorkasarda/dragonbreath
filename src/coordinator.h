#ifndef COORDINATOR_H
#define COORDINATOR_H

// File: coordinator.h
// Purpose: mediator for component, entity, and system managers
// Author: Connor Logan Kasarda
// Date: 2023-09-26

#include <memory>
#include "entity.h"
#include "component.h"
#include "component_manager.h"
#include "entity_manager.h"
#include "system_manager.h"

namespace dragonbreath
{
    class Coordinator
    {
    public:
        void Init();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        template<typename T>
        void RegisterComponent()
        {
            this->componentManager->RegisterComponent<T>();
        }
        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            this->componentManager->AddComponent<T>(entity, component);
            auto signature = this->entityManager->getSignature(entity);
            signature.set(this->componentManager->GetComponentType<T>(), true);
            this->entityManager->setSignature(entity, signature);
            this->systemManager->EntitySignatureChanged(entity, signature);
        }
        template<typename T>
        void RemoveComponent(Entity entity)
        {
            this->componentManager->RemoveComponent<T>(entity);
            auto signature = this->entityManager->GetSignature(entity);
            signature.set(this->componentManager->GetComponentType<T>(), false);
            this->entityManager->setSignature(entity, signature);
            this->systemManager->EntitySignatureChanged(entity, signature);
        }
        template<typename T>
        T& GetComponent(Entity entity)
        {
            return this->componentManager->GetComponent<T>(entity);
        }
        template<typename T>
        Component GetComponentType()
        {
            return this->componentManager->GetComponentType<T>();
        }
        template<typename T>
        std::shared_ptr<T> RegisterSystem()
        {
            return this->systemManager->RegisterSystem<T>();
        }
        template<typename T>
        void SetSystemSignature(Signature signature)
        {
            this->systemManager->SetSignature<T>(signature);
        }
    private:
        std::unique_ptr<ComponentManager> componentManager;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<SystemManager> systemManager;
    };
}

#endif