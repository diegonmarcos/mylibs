#!/bin/bash

# Check if an input file was provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 <input_file.c>"
  exit 1
fi

input_file="$1"

# Check if the input file exists
if [ ! -f "$input_file" ]; then
  echo "Error: Input file not found: $input_file"
  exit 1
fi

input_dir="$(dirname "$input_file")"
output_file="$input_dir/$(basename "$1" .c)_clean.c"
single_marker="#debuging-line"
open_marker="<#debuging-line"
close_marker="#debuging-line>"

# Process the file with awk
awk -v single_marker="$single_marker" \
    -v open_marker="$open_marker" \
    -v close_marker="$close_marker" '
  {
    # Block removal start
    if (index($0, open_marker)) {
      in_block = 1
    }

    # Single-line removal and Skip lines within a block
    if ( (index($0, single_marker) && !index($0,open_marker)) || in_block) {
        
        #check if is close marker
        if (index($0, close_marker)) {
            in_block = 0
        }
        next
    }

    # Print the line if not within a block and not a single-line comment
    print
  }
' "$input_file" > "$output_file"

# Check if awk command was successful
if [ $? -ne 0 ]; then
  echo "Error: Failed to process the file with awk."
  exit 1
fi

echo "Debug lines and blocks removed. Output written to: $output_file"