#!/bin/bash

replace_spaces_with_tabs() {
  local input_file="$1"
  local output_file="$2"

  if [[ ! -f "$input_file" ]]; then
    echo "Error: File '$input_file' not found."
    return 1
  fi

  # Replace 16 spaces with 4 tabs
  sed 's/                /\t\t\t\t/g' "$input_file" > "$output_file"

  # Replace 12 spaces with 3 tabs
  sed -i 's/            /\t\t\t/g' "$output_file"

  # Replace 8 spaces with 2 tabs
  sed -i 's/        /\t\t/g' "$output_file"

  # Replace 4 spaces with 1 tab
  sed -i 's/    /\t/g' "$output_file"

  echo "Spaces replaced with tabs in '$output_file'."
}

remove_spaces_after_declarations() {
  local input_file="$1"
  local output_file="$2"

  if [[ ! -f "$input_file" ]]; then
    echo "Error: File '$input_file' not found."
    return 1
  fi

  # Remove spaces after specific keywords, only if not already followed by a tab
  sed -E 's/^( *)(char|int|t_list)( +)/\1\2\t/g' "$input_file" > "$output_file"

  echo "Spaces after declarations replaced with tabs in '$output_file'."
}

remove_comments_and_debug_lines() {
  local input_file="$1"
  local output_file="$2"

  if [[ ! -f "$input_file" ]]; then
    echo "Error: File '$input_file' not found."
    exit 1
  fi

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
          # Check if is close marker
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
  if [[ $? -ne 0 ]]; then
    echo "Error: Failed to process the file with awk."
    exit 1
  fi

  echo "Debug lines and blocks removed. Output written to: $output_file"
}

# Check if a filename is provided
if [[ $# -eq 0 ]]; then
  echo "Error: No filename provided."
  echo "Usage: $0 <filename> [output_filename]"
  exit 1
fi

input_file="$1"
output_file="$(basename "$1" | sed 's/_dbg//')"  			# Remove the "_dbg" pattern from the filename
#output_file="$(basename "$1" .c)_clean.c" 					# Use a default output filename if not provided


# Create temporary output files
temp_output_file1="$(basename "$1" .c)_tmp1.c"
temp_output_file2="$(basename "$1" .c)_tmp2.c"

# Call the functions with the filename as argument
replace_spaces_with_tabs "$input_file" "$temp_output_file1"
remove_spaces_after_declarations "$temp_output_file1" "$temp_output_file2"
#remove_spaces_after_declarations $input_file" "$temp_output_file2"
remove_comments_and_debug_lines "$temp_output_file2" "$output_file"

# Remove temporary output files
rm "$temp_output_file1"
rm "$temp_output_file2"