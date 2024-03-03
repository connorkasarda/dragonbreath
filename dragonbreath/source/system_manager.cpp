/**
 * @file system_manager.cpp
 * @brief Manages of the ECS systems
 *
 * @author Connor Kasarda
 * @date 2024-03-02
 */

#include "system_manager.hpp"

namespace dragonbreath
{
    void SystemManager::entityDestroyed(Entity entity)
    {
        for (auto const& nameAndSystem : mName2SystemMap)
	{
            auto const& system = nameAndSystem.second;

	    system->entityUnassigned(entity);
	}
    }    
    // ------------------------------------------------------------------------
    void SystemManager::entitySignatureChanged(Entity entity,
        Signature signature)
    {
        for (auto const& nameAndSystem : mName2SystemMap)
	{
	    auto const& name = nameAndSystem.first;
	    auto const& system = nameAndSystem.second;

	    auto name2SignatureMapIter = mName2SignatureMap.find(name);
	    if (name2SignatureMapIter == mName2SignatureMap.end())
	    {
                DEV_ASSERT(false, "entitySignatureChanged attempted accessing"\
		    "system signature that wasn't set for system");

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
    } // class SystemManager
} // namespace dragonbreath
