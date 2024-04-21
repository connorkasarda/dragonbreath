/**
 * @file component_manager.cpp
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-03-04
 */

#include "ComponentManager.h"

namespace dragonbreath
{
    namespace engine
    {
        ComponentManager::ComponentManager() : componentTypeIDAssigner(0) {}
        // ------------------------------------------------------------------------
        ComponentManager::~ComponentManager() = default;
        // ------------------------------------------------------------------------
        void ComponentManager::entityDestroyed(Entity entity)
        {
            for (auto const& pair : name2ArrayMap)
            {
                auto const& componentArray = pair.second;

                componentArray->entityDestroyed(entity);
            }
        }
    } // namespace engine
} // namespace dragonbreath
