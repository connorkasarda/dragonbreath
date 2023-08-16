#ifndef DEBUG_H
#define DEBUG_H

#if defined(DEVELOPMENT)
    #define DRAGON_ASSERT(test, msg, ...) \
        do { \
            if (!(test)) { \
                error(__LINE__, __FILE__, \
                    "Assertion failed: %s\n\n" msg, \
                    #test, __VA_ARGS__); \
            } \
        } while (0)
#else
    #define DRAGON_ASSERT(test, msg, ...) ((void)0)
#endif

#endif