#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

// File: componentarray.h
// Purpose: packed array of components
// Author: Connor Logan Kasarda
// Date: 2023-09-17

#include "entity.h"
#include <array>
#include <unordered_map>

namespace dragonbreath
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
    };
    template<typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        void InsertData(Entity entity, T component)
        {
            std::size_t newIndex = this.size;
            this->entityToIndexMap[entity] = newIndex;
            this->indexToEntityMap[newIndex] = entity;
            this->componentArray[newIndex] = component;
            ++this.size;
        }
        void RemoveData(Entity entity)
        {
            std::size_t removedEntityIndex = this->entityToIndexMap[entity];
            std::size_t lastComponentIndex = this->size - 1;
            this->componentArray[removedEntityIndex] = 
                this->componentArray[lastComponentIndex];
            Entity lastComponentEntity = this->indexToEntityMap
            [
                lastComponentIndex
            ];
            this->entityToIndexMap[lastComponentEntity] = removedEntityIndex;
            this->indexToEntityMap[removedEntityIndex] = lastComponentEntity;
            this->entityToIndexMap.erase(entity);
            this->indexToEntityMap.erase(lastComponentIndex);
            --this->size;
        }
        T& GetData(Entity entity)
        {
            return this->componentArray[this->entityToIndexMap[entity]];
        }
        void EntityDestroyed(Entity entity)
        {
            if
            (
                this->entityToIndexMap.find(entity) != 
                    this->entityToIndexMap.end()
            )
            {
                RemoveData(entity);
            }
        }
    private:
        std::array<T, MAX_ENTITIES> componentArray;
        std::unordered_map<Entity, std::size_t> entityToIndexMap;
        std::unordered_map<std::size_t, Entity> indexToEntityMap;
        std::size_t size;
    };
}

#endif