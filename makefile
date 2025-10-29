# Determine OS and set compiler accordingly
OS_NAME := $(shell uname -s)

ifeq ($(OS_NAME),Linux)
# Variables specific to Linux
	CC = g++
	CFLAGS = --std=c++17 -Wall -g
	LIBS = -lm
else ifeq ($(OS_NAME),Darwin) # macOS
# Variables specific to macOS
	CC = clang++
	CFLAGS = --std=c++17 -Wall -g
	LIBS = -framework CoreFoundation
else ifeq ($(OS_NAME),Windows_NT) # Windows (using MinGW or Cygwin)
# Variables specific to Windows
	CC = g++
	CFLAGS = --std=c++17 -Wall
	LIBS = -lws2_32
else
# Default or fallback variables
	CC = gcc
	CFLAGS = --std=c++17 -Wall
	LIBS =
endif

any: node.h min_heap.h huffman.cpp
	$(CC) $(CFLAGS) huffman.cpp -o huffman
	./huffman

.PHONY: clean
clean:
	rm -f *.o huffman