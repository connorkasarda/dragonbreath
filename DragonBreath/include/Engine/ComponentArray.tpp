/**
 * @file component_array.tpp
 * @brief template storage container for a type of components
 *
 * @author Connor Kasarda
 * @date 2024-02-01
 */

#ifndef COMPONENT_ARRAY_TPP
#define COMPONENT_ARRAY_TPP

namespace dragonbreath
{
    template<typename T>
    ComponentArray<T>::ComponentArray() = default;
    // ------------------------------------------------------------------------
    template<typename T>	
    void ComponentArray<T>::insertData(Entity entity, const T& component)
    {
        if (size == maxEntities)
        {
            DEV_ASSERT(false, "components array full when insertData called");
        
            return;
        }

        size_t index = size;
        components[index] = component;

        entity2IndexMap.insert(std::make_pair(entity, index));
        index2EntityMap.insert(std::make_pair(index, entity));

        ++size;
    }
    // ------------------------------------------------------------------------
    template<typename T>
    void ComponentArray<T>::removeData(Entity entity)
    {
        auto entity2IndexMapIter = entity2IndexMap.find(entity);
        if (entity2IndexMapIter == entity2IndexMap.end())
        {
            DEV_ASSERT(false, "entity not found in entity2IndexMap using " \
                "RemoveData");
        
            return;
        }

        // Efficiently transfer last component to now empty index
        size_t indexOfRemovedEntity = entity2IndexMapIter->second;
        size_t lastIndex = size - 1;
        components[indexOfRemovedEntity] =
            std::move(components[lastIndex]);

        // Update entity and index mappings for moved component
        Entity entityOfMovedComponent = index2EntityMap[lastIndex];
        entity2IndexMap.insert(
            std::make_pair(entityOfMovedComponent, indexOfRemovedEntity));
        index2EntityMap.insert(
            std::make_pair(indexOfRemovedEntity, entityOfMovedComponent));

        // Batch erase to reduce lookup operations and deletions
        entity2IndexMap.erase(entity);
        index2EntityMap.erase(lastIndex);
    
        // Reduce size to allow overwrite of old last component copy
        // when a new component is added in its place
        --size;
    }
    // ------------------------------------------------------------------------
    template<typename T>
    const T& ComponentArray<T>::getData(Entity entity) const
    {
        // Get index with find call for function to be const-correct
        auto entity2IndexMapIter = entity2IndexMap.find(entity);
        if (entity2IndexMapIter != entity2IndexMap.end())
        {
            size_t indexOfEntity = entity2IndexMapIter->second;
            return components[indexOfEntity];
        }

        // Pass back a default empty component if desired component is not
        // found in the map. Static value because we don't want repeated
        // initialization but we want a consistent default value!
        DEV_ASSERT(false, "entity not found in entity2IndexMap using " \
            "GetData");
        static const T defaultComponent {};
        return defaultComponent;
    }
    // ------------------------------------------------------------------------
    template<typename T>
    void ComponentArray<T>::entityDestroyed(Entity entity)
    {
        removeData(entity);
    }
} // namespace dragonbreath

#endif // COMPONENT_ARRAY_TPP
