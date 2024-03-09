/**
 * @file component_manager.tpp
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-02-07
 */

#ifndef COMPONENT_MANAGER_TPP
#define COMPONENT_MANAGER_TPP

namespace dragonbreath
{
    namespace engine
    {
        template<typename T>
        void ComponentManager::registerComponent()
        {
        // Typically, want to avoid typeid usage but output does not need
        // to be human readable so its use is acceptable here.
            ComponentName regdCompName = typeid(T).name();
                
        if (mName2TypeMap.find(regdCompName) != mName2TypeMap.end())
        {
                DEV_ASSERT(false, "registerComponent tried adding existing "\
                    "component");
            
               return;
        }

            mName2TypeMap.insert(
            std::make_pair(regdCompName, mComponentTypeIDAssigner)); 
            mName2ArrayMap.insert(
                std::make_pair(
            regdCompName, std::make_shared<ComponentArray<T>>()));

        ++mComponentTypeIDAssigner;
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void ComponentManager::addComponent(Entity entity, T component)
        {
            getComponentArray<T>()->insertData(entity, component);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void ComponentManager::removeComponent(Entity entity)
        {
            getComponentArray<T>()->removeData(entity);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        const T& ComponentManager::getComponent(Entity entity) const
        {
            return getComponentArray<T>()->getData(entity);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        ComponentType ComponentManager::getComponentType() const
        {
            ComponentName compName = typeid(T).name();

            auto name2TypeMapIter = mName2TypeMap.find(compName);
            if (name2TypeMapIter == mName2TypeMap.end())
            {
                DEV_ASSERT(false, "getComponentType tried accessing component "\
                    "type that was not registered yet");

                return kInvalidComponentType;
            }

            return name2TypeMapIter->second;
        }
        // ------------------------------------------------------------------------
        template<typename T>
        std::shared_ptr<ComponentArray<T>>
            ComponentManager::getComponentArray() const
        {
            ComponentName compName = typeid(T).name();
            
            auto name2ArrayMapIter = mName2ArrayMap.find(compName);

        if (name2ArrayMapIter == mName2ArrayMap.end())
        {
                DEV_ASSERT(false, "getComponentArray tried accessing array "\
                    "of unregistered component type");
            
                return nullptr;
        }

            return std::static_pointer_cast<ComponentArray<T>>(
            name2ArrayMapIter->second);
        }
    } // namespace engine	
} // namespace dragonbreath

#endif // COMPONENT_MANAGER_TPP
