/**
 * @file entity_manager_driver.h
 * @brief Challenges capabilities of the EntityManager
 *
 * @author Connor Kasarda
 * @date 2024-02-04
 */

#ifndef ENTITY_MANAGER_DRIVER_H
#define ENTITY_MANAGER_DRIVER_H

#include "debug.h"
#include "driver.h"

namespace dragonbreath
{
    /**
     * @brief Puts the EntityManager class to the test
     */
    class EntityManagerDriver : public IDriver
    {
    public:
        /**
         * @brief Performs setup for test cases
         */
        void setUp() override;

        /**
         * @brief Performs cleanup after test cases
         */
        void tearDown() override;

	// TODO Methods for each feature or capability to test
    }; // class EntityManagerDriver
} // namespace dragonbreath

#endif // ENTITY_MANAGER_DRIVER_H
