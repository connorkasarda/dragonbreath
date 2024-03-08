/**
 * @file component_manager.cpp
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-03-04
 */

#include "component_manager.h"

namespace dragonbreath
{
    ComponentManager::ComponentManager() : mComponentTypeIDAssigner(0) {}
    // ------------------------------------------------------------------------
    ComponentManager::~ComponentManager() = default;
    // ------------------------------------------------------------------------
    void ComponentManager::entityDestroyed(Entity entity)
    {
        for (auto const& pair : mName2ArrayMap)
        {
            auto const& componentArray = pair.second;

            componentArray->entityDestroyed(entity);
        }
    }
} // namespace dragonbreath
