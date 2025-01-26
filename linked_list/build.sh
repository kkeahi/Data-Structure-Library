#!/bin/bash

# Set the output binary name
OUTPUT="main"

# Compiler and flags
CXX=g++
CXXFLAGS="-std=c++17 -Wall"

# List all the source files explicitly
SRC_FILES="main.cpp \
           singly_linked_list/SinglyLinkedList.cpp \
           doubly_linked_list/DoublyLinkedList.cpp \
           circular_linked_list/CircularLinkedList.cpp \
           circular_doubly_linked_list/CircularDoublyLinkedList.cpp"

# Build the project
echo "Compiling linked list project..."
$CXX $CXXFLAGS -o $OUTPUT $SRC_FILES

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Run ./$OUTPUT"
else
    echo "Build failed!"
fi
