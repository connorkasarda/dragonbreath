/**
 * @file component_manager.hpp
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-02-07
 */

#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include "component_array.hpp"

namespace dragonbreath
{
    /**
     * @brief Manages all of the registered components of the ECS
     */
    class ComponentManager
    {
    public:
        /**
	 * @brief Constructor
	 */
	ComponentManager() : mComponentTypeIDAssigner(0)
	{

	}

	/**
	 * @brief Destructor
	 */
	~ComponentManager() = default;

	/**
	 * @brief Registers a new component type
	 *
	 * Typically, wouldn't want to use typeid(T).name() because it can be
	 * unpredictable and far from human readable. However, the output is
	 * not for the eyes of a human -- just the computer. Therefore, its
	 * use here is okay.
	 */
        template<typename T>
	void registerComponent()
	{
	    // Typically, want to avoid typeid usage but output does not need
	    // to be human readable so its use is acceptable here.
            ComponentName regdCompName = typeid(T).name();
            
	    if (mName2TypeMap.find(regdCompName) != mName2TypeMap.end())
	    {
                DEV_ASSERT(
	            false,
		    "registerComponent tried adding existing component");
		return;
	    }

            mName2TypeMap.insert(
		std::make_pair(regdCompName, mComponentTypeIDAssigner)); 
            mName2ArrayMap.insert(
                std::make_pair(
		    regdCompName, std::make_shared<ComponentArray<T>>()));

	    ++mComponentTypeIDAssigner;
	}

	/**
	 * @brief Adds component to the appropriate component array
	 *
	 * @param entity Entity component belongs to
	 * @param component Component to add to component array
	 */
	template<typename T>
        void addComponent(Entity entity, T component)
	{
            getComponentArray<T>()->insertData(entity, component);
	}

	/**
	 * @brief Removes component from the appropriate component array
	 *
	 * @param component Component to be removed
	 */
	template<typename T>
	void removeComponent(T component)
	{
            getComponentArray<T>()->removeData(component);
	}

	/**
	 * @brief Called whenever an entity is destroyed to trigger removal
	 *
	 * @param entity Entity that was destroyed
	 */
	void entityDestroyed(Entity entity)
	{
            for (auto const& pair : mName2ArrayMap)
	    {
                auto const& componentArray = pair.second;

		componentArray->entityDestroyed(entity);
	    }
	}
    private:
        /**
	 * @brief Mapping from component type name to the component type
	 */
        std::unordered_map<ComponentName, ComponentType> mName2TypeMap {};

	/**
	 * @brief Mapping from component type name to the component array
	 */
	std::unordered_map<ComponentName, std::shared_ptr<IComponentArray>>
            mName2ArrayMap {};

        /**
	 * @brief Keeps track of the component types
	 *
	 * Latest value is assigned to newly assigned component. Works
	 * similarly to a counter.
	 */
	ComponentType mComponentTypeIDAssigner {};

	/**
	 * @brief Helper function returning the component array based on T
	 *
	 * We need to do this with care. Since polymorphism was used to allow
	 * all specialized ComponentArray objects to be stored in the same
	 * mapping, the shared_ptr to the IComponentArray needs to be
	 * downcasted so that the shared_ptr has the derived classes info in
	 * the form of ComponentArray<T>.
	 *
	 * @return shared pointer to the specialized component array
	 */
	template<typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray() const
	{
            ComponentName compName = typeid(T).name();
            
            auto name2ArrayMapIter = mName2ArrayMap.find(compName);

	    if (name2ArrayMapIter == mName2ArrayMap.end())
	    {
                DEV_ASSERT(
	            false,
		    "getComponentArray tried accessing array of unregistered "\
		    "component type");
		
		return nullptr;
	    }

            return std::static_pointer_cast<ComponentArray<T>>(
	        name2ArrayMapIter->second);
	}	
    }; // class ComponentManager
} // namespace dragonbreath

#endif // COMPONENT_MANAGER_HPP