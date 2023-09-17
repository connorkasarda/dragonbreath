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
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
    };
    template<typename T>
    class ComponentArray : public IComponentArray
    {
        private:
            std::array<T, MAX_ENTITIES> componentArray;
            std::unordered_map<Entity, size_t> entityToIndexMap;
            std::unordered_map<size_t, Entity> indexToEntityMap;
            size_t size;
        // ADD FUNCTION NAMES HERE
    };
}

#endif