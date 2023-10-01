#ifndef DEBUG_H
#define DEBUG_H

// File: debug.h
// Purpose: self-defined asserts for development debugging purposes
// Author: Connor Logan Kasarda
// Date: 2023-08-16

namespace dragonbreath
{
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
}

#endif