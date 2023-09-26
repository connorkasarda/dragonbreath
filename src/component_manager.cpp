// File: component_manager.cpp
// Purpose: manages component arrays when component added or removed
// Author: Connor Logan Kasarda
// Date: 2023-09-25

#include "component_manager.h"

namespace dragonbreath
{
    void ComponentManager::EntityDestroyed(Entity entity)
    {
        for (auto const& pair : this->componentArrays)
        {
            auto const& component = pair.second;
            component->EntityDestroyed(entity);
        }
    }
}