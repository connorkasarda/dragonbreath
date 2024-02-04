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

    #if defined(DEVELOPMENT)
        #define DRAGON_ASSERT(test, msg, ...) \
            do { \
                if (!(test)) { \
                    dragonbreath::error(__LINE__, __FILE__, \
                        "Assertion failed: %s\n\n" msg, \
                        #test, ##__VA_ARGS__); \
                } \
            } while (0)
    #else
        #define DRAGON_ASSERT(test, msg, ...) ((void)0)
    #endif
} // namespace dragonbreath

#endif // DEBUG_H
