# Determine OS and set compiler accordingly
OS_NAME := $(shell uname -s)

ifeq ($(OS_NAME),Linux)
# Variables specific to Linux
	CC = gcc
	CFLAGS = -Wall -g
	LIBS = -lm
else ifeq ($(OS_NAME),Darwin) # macOS
# Variables specific to macOS
	CC = clang
	CFLAGS = -Wall -g
	LIBS = -framework CoreFoundation
else ifeq ($(OS_NAME),Windows_NT) # Windows (using MinGW or Cygwin)
# Variables specific to Windows
	CC = gcc
	CFLAGS = -Wall
	LIBS = -lws2_32
else
# Default or fallback variables
	CC = cc
	CFLAGS = -Wall
	LIBS =
endif

any: min_heap.cpp huffman.cpp
	$(CC) $(CFLAGS) huffman.cpp -o huffman