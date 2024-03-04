/**
 * @file system_manager.tpp
 * @brief Coordinates and manages all of the systems in the ECS
 *
 * @author Connor Kasarda
 * @date 2024-02-26
 */

#ifndef SYSTEM_MANAGER_TPP
#define SYSTEM_MANAGER_TPP

namespace dragonbreath
{
    template<typename T>
    std::shared_ptr<T> SystemManager::registerSystem()
    {
        SystemName systemName = typeid(T).name();

	auto system = std::shared_ptr<T>();
	auto result = mName2SystemMap.insert(
	    std::make_pair(systemName, system));
	    
        if (!result.second)
	{
            DEV_ASSERT(false, "registerSystem attempted registering same "\
                "system again");
		
	    return nullptr;
	}

	return system;
    }
    // ------------------------------------------------------------------------
    template<typename T>
    void SystemManager::registerSystemSignature(Signature signature)
    {
        SystemName systemName = typeid(T).name();
            
	if (mName2SystemMap.find(systemName) == mName2SystemMap.end())
	{
            DEV_ASSERT(false, "registerSystemSignature attempted setting "\
		"signature for unregistered system");

            return;
	}

	mName2SignatureMap.insert(std::make_pair(systemName, signature));
    }
    // ------------------------------------------------------------------------
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
} // namespace dragonbreath

#endif // SYSTEM_MANAGER_TPP
