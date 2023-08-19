# File: Makefile
# Purpose: compiles codeinto dragonbreath executable
# Author: Connor Logan Kasarda
# Date: 2023-08-06

# For development debugging purposes, add "-DDEVELOPMENT" flag in CFLAGS

CC := g++ # name of compiler
CFLAGS := -Wall -Werror -std=c++17 # compiler's enabled flags
TARGET := dragonbreath # target's name

all: $(TARGET) # default target's name

SRCS := $(wildcard *.cpp) # finds and sets source files
OBJS := $(SRCS:.cpp=.o) # finds and sets header files

%.o: %.cpp # how to compile source files
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) # how to link object files into executable
	$(CC) $(CFLAGS) $^ -o $@

DEPS := $(OBJS:.o=.d) # automatic dependency generation

%.d: %.cpp
	@$(CC) $(CFLAGS) -MM $< -MF $@

-include $(DEPS)

clean: # how to clean directory of executable, dependencies, and object files
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean # phony targets