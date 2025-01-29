#!/bin/bash

# Set the output binary name
OUTPUT="main"

# Compiler and flags
CXX=g++
CXXFLAGS="-std=c++17 -Wall"

# List all the source files explicitly
SRC_FILES="main.cpp \
           Stack.cpp"

# Build the project
echo "Compiling linked list project..."
$CXX $CXXFLAGS -o $OUTPUT $SRC_FILES

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Run ./$OUTPUT"
else
    echo "Build failed!"
fi
