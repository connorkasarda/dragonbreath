/**
 * @file system_manager.h
 * @brief Coordinates and manages all of the systems in the ECS
 *
 * @author Connor Kasarda
 * @date 2024-02-26
 */

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <memory>
#include <unordered_map>
#include "Debug.h"
#include "System.h"
#include "Entity.h"
#include "Signature.h"

namespace dragonbreath
{
    namespace engine
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
            std::shared_ptr<T> registerSystem();

            /**
             * @brief Sets the signature for a given system
             *
             * @param signature Signature of the system for comparisons
             */
            template<typename T>
            void setSystemSignature(Signature signature);

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
            std::unordered_map<SystemName, Signature> name2SignatureMap {};

            /**
             * @brief Mapping from the system name to the system
             */
            std::unordered_map<SystemName, std::shared_ptr<System>>
                name2SystemMap {};
        }; // class SystemManager
    } // namespace engine
} // namespace dragonbreath

#include "SystemManager.tpp"

#endif // SYSTEM_MANAGER_H
