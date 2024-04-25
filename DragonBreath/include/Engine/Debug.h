/**
 * @file debug.h
 * @brief Defines assert macro for development purposes
 *
 * @author Connor Kasarda
 * @date 2024-01-30
 */

#ifndef DEBUG_H
#define DEBUG_H

namespace dragonbreath
{
    /**
     * @brief Behavior that occurs when assert catches an error
     */
    void error(int line, const char* file, const char* format, ...);

    // Define assertion macro for development
    #if defined(DEVELOPMENT)
        #define DEV_ASSERT(test, msg, ...) \
            do { \
                if (!(test)) { \
                    dragonbreath::error(__LINE__, __FILE__, \
                        "Assertion failed: %s\n\n" msg, \
                        #test, ##__VA_ARGS__); \
                } \
            } while (0)
    #else
        #define DEV_ASSERT(test, msg, ...) ((void)0)
    #endif

    // Define assertion macro for testing
    #if defined(TESTING)
        #define TEST_ASSERT(test) \
            do { \
            if (!(test)) { \
                    dragonbreath::error( \
                __LINE__, \
                __FILE__, \
                "Test failed: %s\n" \
                        #test); \
                } \
            } while (0)
    #else
        #define TEST_ASSERT(test) ((void)0)
    #endif
} // namespace dragonbreath

#endif // DEBUG_H
