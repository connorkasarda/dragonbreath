// File: componentarray.cpp
// Purpose: component-packed array class implementations
// Author: Connor Logan Kasarda
// Date: 2023-09-15

#include "component_array.h"

namespace dragonbreath
{   
    template <typename T>
    void ComponentArray<T>::InsertData(Entity entity, T component)
    {
        std::size_t newIndex = this.size;
        this->entityToIndexMap[entity] = newIndex;
        this->indexToEntityMap[newIndex] = entity;
        this->componentArray[newIndex] = component;
        ++this.size;
    }
    template <typename T>
    void ComponentArray<T>::RemoveData(Entity entity)
    {
        std::size_t removedEntityIndex = this->entityToIndexMap[entity];
        std::size_t lastComponentIndex = this->size - 1;
        this->componentArray[removedEntityIndex] = 
            this->componentArray[lastComponentIndex];
        Entity lastComponentEntity = this->indexToEntityMap[lastComponentIndex];
        this->entityToIndexMap[lastComponentEntity] = removedEntityIndex;
        this->indexToEntityMap[removedEntityIndex] = lastComponentEntity;
        this->entityToIndexMap.erase(entity);
        this->indexToEntityMap.erase(lastComponentIndex);
        --this->size;
    }
    template <typename T>
    T& ComponentArray<T>::GetData(Entity entity)
    {
        return this->componentArray[this->entityToIndexMap[entity]];
    }
    template <typename T>
    void ComponentArray<T>::EntityDestroyed(Entity entity)
    {
        if (this->entityToIndexMap.find(entity) != this->entityToIndexMap.end())
        {
            RemoveData(entity);
        }
    }
}