// File: system_manager.cpp
// Purpose: maintains record of registered systems and their signatures
// Author: Connor Logan Kasarda
// Date: 2023-09-26

#include "system_manager.h"

namespace dragonbreath
{
    void SystemManager::EntityDestroyed(Entity entity)
    {
        for (auto const& pair : this->systems)
        {
            auto const& system = pair.second;
            system->entities.erase(entity);
        }
    }
    void SystemManager::EntitySignatureChanged
    (
        Entity entity,
        Signature entitySignature
    )
    {
        for (auto const& pair : this->systems)
        {
            auto const& type = pair.first;
            auto const& system = pair.second;
            auto const& systemSignature = this->signatures[type];
            if ((entitySignature & systemSignature) == systemSignature)
            {
                system->entities.insert(entity);
            }
            else
            {
                system->entities.erase(entity);
            }
        }
    }
}