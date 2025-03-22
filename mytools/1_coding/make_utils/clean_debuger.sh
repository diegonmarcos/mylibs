#!/bin/bash

# Check if a filename was provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename.dbg.c"
    exit 1
fi

# Get the input file
input_file="$1"

# Extract base name and create output filename
### the -d flag in cut specifies the delimiter, in this case the dot
### the -f flag specifies the field to extract
base_name=$(basename "$input_file" | cut -d. -f1)
output_file="${base_name}.c"

echo "Processing $input_file -> $output_file"

# Create clean version of the file by removing debug lines
### the -v flag in grep inverts the match, so it will remove all lines that match the pattern
grep -v "///" "$input_file" > "$output_file"

# Count removed lines
total_lines=$(wc -l < "$input_file")
clean_lines=$(wc -l < "$output_file")
removed_lines=$((total_lines - clean_lines))

echo "Done! Removed $removed_lines debug lines."
echo "Clean file saved as $output_file"