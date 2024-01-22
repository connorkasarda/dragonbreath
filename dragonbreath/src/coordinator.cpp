// File: coordinator.cpp
// Purpose: mediator for component, entity, and system managers
// Author: Connor Logan Kasarda
// Date: 2023-09-26

#include "coordinator.h"

namespace dragonbreath
{
    void Coordinator::Init()
    {
        this->componentManager = std::make_unique<ComponentManager>();
        this->entityManager = std::make_unique<EntityManager>();
        this->systemManager = std::make_unique<SystemManager>();
    }
    Entity Coordinator::CreateEntity()
    {
        return this->entityManager->CreateEntity();
    }
    void Coordinator::DestroyEntity(Entity entity)
    {
        this->entityManager->DestroyEntity(entity);
        this->componentManager->EntityDestroyed(entity);
        this->systemManager->EntityDestroyed(entity);
    }
}