/**
 * @file component_manager.h
 * @brief Manages components with respect to component arrays
 *
 * @author Connor Kasarda
 * @date 2024-02-07
 */

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <type_traits>
#include "component.h"
#include "component_array.h"

namespace dragonbreath
{
    /**
     * @brief Manages the component arrays for each registered component type
     */
    class ComponentManager
    {
    public:
        /**
	 * @brief Constructor
	 */
	ComponentManager() : mComponentTypeCounter(0)
	{

	}

	/**
	 * @brief Destructor
	 */
	~ComponentManager() = default;

	/**
	 * @brief Registers a new component
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
	    // to be human readable so its use is allowed here.
            ComponentName regdCompName = typeid(T).name();
            
	    if (mName2TypeMap.find(regdCompName) != mName2TypeMap.end())
	    {
                DEV_ASSERT(
	            false,
		    "registerComponent tried adding existing component");
	    }

            mName2TypeMap.insert(
		std::make_pair(regdCompName, mComponentTypeCounter 
            mName2ArrayMap.insert(
                std::make_pair(
		    regdCompName, std::make_shared<ComponentArray<T>>()));

	    ++mComponentTypeCounter;
	}

        // TODO add component, remove component?, ...
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
	ComponentType mComponentTypeCounter {};
    }; // class ComponentManager
} // namespace dragonbreath

#endif // COMPONENT_MANAGER_H
