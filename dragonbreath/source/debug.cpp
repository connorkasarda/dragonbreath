/**
 * @file debug.cpp
 * @brief Defines error response behavior for assert
 *
 * @author Connor Kasarda
 * @date 2024-01-30
 */

#include <cstdio>
#include <cstdarg>
#include "debug.h"

namespace dragonbreath
{
    /**
     * @brief Called when dragon assert macro is engaged
     */
    void error(int line, const char* file, const char* format, ...)
    {
        va_list args;
        va_start(args, format);
        std::fprintf(stderr, "[%s:%d] ", file, line);
        std::vfprintf(stderr, format, args);
        va_end(args);
        std::fprintf(stderr, "\n");
    }
} // namespace dragonbreath
