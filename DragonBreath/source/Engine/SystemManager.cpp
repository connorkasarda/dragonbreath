/**
 * @file system_manager.cpp
 * @Coordinates and manages all of the systems in the ECS
 *
 * @author Connor Kasarda
 * @date 2024-03-04
 */

#include "Debug.h"
#include "SystemManager.h"

namespace dragonbreath
{
    namespace engine
    {
        void SystemManager::entityDestroyed(Entity entity)
        {
            for (auto const& nameAndSystem : name2SystemMap)
            {
                auto const& system = nameAndSystem.second;

                system->entityUnassigned(entity);
            }
        }
        // ------------------------------------------------------------------------ 
        void SystemManager::entitySignatureChanged(Entity entity,
            Signature signature)
        {
            for (auto const& nameAndSystem : name2SystemMap)
            {
                auto const& name = nameAndSystem.first;
                auto const& system = nameAndSystem.second;

                auto name2SignatureMapIter = name2SignatureMap.find(name);
                if (name2SignatureMapIter == name2SignatureMap.end())
                {
                    DEV_ASSERT(false, "entitySignatureChanged attempted "\
                        "accessing system signature that wasn't set for system");

                    continue;
                }

                auto const& systemSignature = name2SignatureMapIter->second;

                // Use of & bit operation to quickly determine if match
                if ((signature & systemSignature) == systemSignature)
                {
                    system->entityAssigned(entity);
                }
                else
                {
                    system->entityUnassigned(entity);
                }
            }
        }
    } // namespace engine
} // namespace dragonbreath
