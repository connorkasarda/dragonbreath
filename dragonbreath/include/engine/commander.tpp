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
            mComponentManager->registerComponent<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::addComponent(Entity entity, T component)
        {
            mComponentManager->addComponent<T>(entity, component);

            // Make sure to get entities original signature genes and update
            auto signature = mEntityManager->getSignature(entity);
            signature.set(mComponentManager->getComponentType<T>(), true);
            mEntityManager->setSignature(entity, signature);

            mSystemManager->entitySignatureChanged(entity, signature);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::removeComponent(Entity entity)
        {
            mComponentManager->removeComponent<T>(entity);

            auto signature = mEntityManager->getSignature(entity);
            signature.set(mComponentManager->getComponentType<T>(), false);
            mEntityManager->setSignature(entity, signature);

            mSystemManager->entitySignatureChanged(entity, signature);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        const T& Commander::getComponent(Entity entity) const
        {
            return mComponentManager->getComponent<T>(entity);
        }
        // ------------------------------------------------------------------------
        template<typename T>
        ComponentType Commander::getComponentType() const
        {
            return mComponentManager->getComponentType<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        std::shared_ptr<T> Commander::registerSystem()
        {
            return mSystemManager->registerSystem<T>();
        }
        // ------------------------------------------------------------------------
        template<typename T>
        void Commander::setSystemSignature(Signature signature)
        {
            mSystemManager->setSystemSignature<T>(signature);
        }
    } // namespace engine
} // namespace dragonbreath
