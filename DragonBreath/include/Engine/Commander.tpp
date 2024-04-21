/**
 * @file commander.h
 * @brief The ECS's commander class that orchestrates managers
 *
 * @author Connor Kasarda
 * @date 2024-03-05
 */

namespace dragonbreath
{
    namespace engine
    {
        template<typename T>
        void Commander::registerComponent()
        {
            componentManager->registerComponent<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::addComponent(Entity entity, T component)
        {
            componentManager->addComponent<T>(entity, component);

            // Make sure to get entities original signature genes and update
            auto signature = entityManager->getSignature(entity);
            signature.set(componentManager->getComponentType<T>(), true);
            entityManager->setSignature(entity, signature);

            systemManager->entitySignatureChanged(entity, signature);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::removeComponent(Entity entity)
        {
            componentManager->removeComponent<T>(entity);

            auto signature = entityManager->getSignature(entity);
            signature.set(componentManager->getComponentType<T>(), false);
            entityManager->setSignature(entity, signature);

            systemManager->entitySignatureChanged(entity, signature);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        const T& Commander::getComponent(Entity entity) const
        {
            return componentManager->getComponent<T>(entity);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        ComponentType Commander::getComponentType() const
        {
            return componentManager->getComponentType<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        std::shared_ptr<T> Commander::registerSystem()
        {
            return systemManager->registerSystem<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::setSystemSignature(Signature signature)
        {
            systemManager->setSystemSignature<T>(signature);
        }
    } // namespace engine
} // namespace dragonbreath
