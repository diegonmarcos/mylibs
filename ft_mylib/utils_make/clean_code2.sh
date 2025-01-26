#!/bin/bash

# filepath: /home/diego/Documents/Git/DevelopmentProjects/42_Common/C2_push_swap/2.CODE/src/push_swap/dbg/clean_code.sh

replace_spaces_with_tabs() {
  local input_file="$1"
  local output_file="$2"

  if [[ ! -f "$input_file" ]]; then
    echo "Error: File '$input_file' not found."
    return 1
  fi

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
  sed -E 's/^( *)(char|int|t_list)( +)/\1\2\t/g' "$input_file" > "$output_file.tmp"
  mv "$output_file.tmp" "$output_file"

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

process_file() {
  local input_file="$1"
  local output_file="$(basename "$input_file" | sed 's/_dbg//')"

  echo "Processing file: $input_file -> $output_file"

  remove_comments_and_debug_lines "$input_file" "$output_file"
  remove_spaces_after_declarations "$output_file" "$output_file"
  replace_spaces_with_tabs "$output_file" "$output_file"
}

move_files_up() {
  local files=("$@")
  for file in "${files[@]}"; do
    local output_file="$(basename "$file" | sed 's/_dbg//')"
    mv "$output_file" ../
    echo "Moved $output_file to parent directory."
  done
}

if [[ "$1" == "all" ]]; then
  files=($(find . -type f -name "*.c"))
  for file in "${files[@]}"; do
    process_file "$file"
  done
  move_files_up "${files[@]}"
else
  for input_file in "$@"; do
    process_file "$input_file"
  done
  move_files_up "$@"
fi