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
        auto result = name2SystemMap.insert(
        std::make_pair(systemName, system));
        
        if (!result.second)
        {
            DEV_ASSERT(false, "registerSystem attempted registering same " \
                "system again");
        
            return nullptr;
        }

        return system;
    }
    // ------------------------------------------------------------------------
    template<typename T>
    void SystemManager::setSystemSignature(Signature signature)
    {
        SystemName systemName = typeid(T).name();
            
        if (name2SystemMap.find(systemName) == name2SystemMap.end())
        {
            DEV_ASSERT(false, "registerSystemSignature attempted setting " \
                "signature for unregistered system");

            return;
        }

        name2SignatureMap.insert(std::make_pair(systemName, signature));
    }
} // namespace dragonbreath

#endif // SYSTEM_MANAGER_TPP
