// File: debug.cpp
// Purpose: debug macro implementations for development
// Author: Connor Logan Kasarda
// Date: 2023-08-19

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