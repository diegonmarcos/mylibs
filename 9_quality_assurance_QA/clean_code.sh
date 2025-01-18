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
triple_slash_marker="///"

																				# Process the file with awk
awk -v single_marker="$single_marker" \
    -v open_marker="$open_marker" \
    -v close_marker="$close_marker" \
    -v triple_slash_marker="$triple_slash_marker" '
  {
  																				# Check if the line is empty before any modifications
	is_empty = (length($0) == 0)
																				# Remove everything after "///"
    triple_slash_pos = index($0, triple_slash_marker)
    if (triple_slash_pos > 0) {
      $0 = substr($0, 1, triple_slash_pos - 1)
    }

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

																				# Print the line if not within a block, not a single-line comment, and not empty after "///" removal
    if (is_empty || length($0) > 0) {
        print (is_empty ? "" : $0)
    }
  }
' "$input_file" > "$output_file"

# Check if awk command was successful
if [ $? -ne 0 ]; then
  echo "Error: Failed to process the file with awk."
  exit 1
fi

echo "Debug lines and blocks removed. Output written to: $output_file"