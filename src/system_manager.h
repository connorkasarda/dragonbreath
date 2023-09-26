#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

// File: system_manager.h
// Purpose: maintains record of registered systems and their signatures
// Author: Connor Logan Kasarda
// Date: 2023-09-26

#include <memory>
#include <unordered_map>
#include "signature.h"
#include "system.h"

namespace dragonbreath
{
    class SystemManager
    {
    public:
        template<typename T>
        std::shared_ptr<T> RegisterSystem()
        {
            const char* typeName = typeid(T).name();
            auto system = std::make_shared<T>();
            this->systems.insert({typeName, system});
            return system;
        }
        template<typename T>
        void SetSignature(Signature signature)
        {
            const char* typeName = typeid(T).name();
            this->signatures.insert({typeName, signature});
        }
        void EntityDestroyed(Entity entity);
        void EntitySignatureChanged(Entity entity, Signature entitySignature);
    private:
        std::unordered_map<const char*, Signature> signatures{};
        std::unordered_map<const char*, std::shared_ptr<System>> systems{};
    };
}

#endif