/**
 * @file system_manager.hpp
 * @brief Coordinates and manages all of the systems in the ECS
 *
 * @author Connor Kasarda
 * @date 2024-02-26
 */

#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include "debug.h"
#include "system.h"
#include "entity.h"
#include "signature.h"

namespace dragonbreath
{
    /**
     * @brief Object that manages the systems in the ECS
     */
    class SystemManager
    {
    public:
        /**
	 * @brief Introduces new system type to manager and registers it
	 */
        template<typename T>
        std::shared_ptr<T> registerSystem()
	{
            SystemName systemName = typeid(T).name();

	    auto system = std::shared_ptr<T>();
	    auto result = mName2SystemMap.insert(
	        std::make_pair(systemName, system));
	    
            if (!result.second)
	    {
                DEV_ASSERT(false, "registerSystem attempted registering "\
		    "same system again");
		
	        return nullptr;
	    }

	    return system;
	}	

	/**
	 * @brief Sets the signature for a given system
	 *
	 * @param signature Signature of the system for comparisons
	 */
	template<typename T>
	void registerSystemSignature(Signature signature)
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

	/**
	 * @brief Triggered when an entity is destroyed
	 */
        void entityDestroyed(Entity entity);

	/**
	 * @brief Triggered when component added to entity due to new component
	 */
	void entitySignatureChanged(Entity entity, Signature signature);
    private:
	/**
	 * @brief Mapping from the system name to the signature
	 */
        std::unordered_map<SystemName, Signature> mName2SignatureMap {};

	/**
	 * @brief Mapping from the system name to the system
	 */
	std::unordered_map<SystemName, std::shared_ptr<System>>
            mName2SystemMap {};
    }; // class SystemManager
} // namespace dragonbreath

#endif // SYSTEM_MANAGER_HPP
