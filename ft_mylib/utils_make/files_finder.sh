#!/bin/bash

# 1. Delete src_all and include_all if they exist
if [ -d "src/src_all" ]; then
  echo "Deleting existing src/src_all directory..."
  rm -rf "src/src_all"
fi

# Create the destination directories if they don't exist (they shouldn't after the previous step)
echo "Creating src/src_all and src/include_all directories..."
mkdir -p "src/src_all"

# 2. Find .c and .h files and copy them
echo "Copying .c and .h files..."
find src/ -mindepth 1 -maxdepth 5 -type f \( -name "*.c" -o -name "*.h" \) -print0 |
while IFS= read -r -d $'\0' file; do
  filename=$(basename "$file")
  filepath=$(dirname "$file")

  if [[ "$filename" == *.c ]]; then
    echo "Copying C file: $file to src/src_all/$filename"
    cp "$file" "src/src_all/"
  elif [[ "$filename" == *.h ]]; then
    echo "Copying H file: $file to src/include_all/$filename"
    cp "$file" "include2/"
  fi
done

#!/bin/bash

# Go to the specified directory
cd ft_mylib/src/src_all

# Find all .c files, sort them alphabetically, and format the output
find . -name "*.c" -print0 | sort -z | while IFS= read -r -d '' file; do
  printf "%s\t\t\\ \n" "${file:2}" 
done > log/list_files_c.txt

echo "Script completed successfully."