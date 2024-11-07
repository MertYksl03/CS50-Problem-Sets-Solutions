#!/bin/bash

# Define the source file and output executable
SOURCE_FILE="credit.c"
OUTPUT_EXECUTABLE="credit"

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
  echo "Source file $SOURCE_FILE does not exist."
  exit 1
fi

echo "Compiling $SOURCE_FILE..."
gcc "$SOURCE_FILE" -o "$OUTPUT_EXECUTABLE" -lcs50

if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

echo "Running $OUTPUT_EXECUTABLE..."
./"$OUTPUT_EXECUTABLE"
