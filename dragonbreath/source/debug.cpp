/**
 * @file debug.cpp
 * @brief Defines error response behavior for assert
 *
 * @author Connor Kasarda
 * @date 30 Jan 2024
 */

#include <cstdio>
#include <cstdarg>
#include "debug.h"

namespace dragonbreath
{
    void error(int line, const char* file, const char* format, ...)
    {
        va_list args;
        va_start(args, format);
        std::fprintf(stderr, "[%s:%d] ", file, line);
        std::vfprintf(stderr, format, args);
        va_end(args);
        std::fprintf(stderr, "\n");
    }
}
