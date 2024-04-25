/**
 * @file system.cpp
 * @brief Implements the base class that all systems inherit
 *
 * @author Connor Kasarda
 * @date 2024-02-26
 */

#include "Debug.h"
#include "System.h"

namespace dragonbreath
{
    void System::entityAssigned(Entity entity)
    {
        auto insertResult = entities.insert(entity);

        DEV_ASSERT(insertResult.second, "entityAssigned tried assigning the " \
            "same entity again");
    }
    // ------------------------------------------------------------------------
    void System::entityUnassigned(Entity entity)
    {
        auto eraseResult = entities.erase(entity);

        DEV_ASSERT(eraseResult > 0, "entityDestroyed tried removing " \
            "unassigned entity");
    }
} // namespace dragonbreath
