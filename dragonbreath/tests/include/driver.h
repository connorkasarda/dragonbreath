/**
 * @file driver.h
 * @brief Forces functionality that all tester/driver classes should have
 *
 * @author Connor Kasarda
 * @date 2024-02-04
 */

#ifndef DRIVER_H
#define DRIVER_H

namespace dragonbreath
{
    /**
     * @brief Interface for tester/driver classes
     *
     * Tester classes need to implement setup and teardown functions.
     */
    class IDriver
    {
    public:
        /**
         * @brief Default destructor
         */
        virtual ~IDriver() = default;

        /**
         * @brief Prepares environment before any test cases run
         */
        virtual void setUp() = 0;

        /**
         * @brief Cleans up resources and states after test cases run
         */
        virtual void tearDown() = 0;
    }; // class IDriver
} // namespace dragonbreath

#endif // DRIVER_H
