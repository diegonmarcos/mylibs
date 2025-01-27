#!/bin/bash

# 1. Delete src_all if it exists
if [ -d "src/src_all" ]; then
    echo "Deleting existing src/src_all directory..."
    rm -rf "src/src_all"
fi

# Create the destination directory
echo "Creating src/src_all directory..."
mkdir -p "src/src_all"

# 2. Find.c files and create symbolic links
echo "Creating symbolic links for.c files..."
find src/ -mindepth 1 -maxdepth 5 -type f -name "*.c" -print0 |
while IFS= read -r -d $'\0' file; do
    filename=$(basename "$file")
    echo "Creating symbolic link for $file in src/src_all/$filename"
    ln -s "$file" "src/src_all/$filename" || echo "Error creating symbolic link for $file"
done

# --- Second script ---

#!/bin/bash

# Go to the specified directory (add a check or use absolute path)
cd ft_mylib/src/src_all

# Find all.c files, sort them alphabetically, and format the output
find. -name "*.c" -print0 | sort -z | while IFS= read -r -d '' file; do
    printf "%s\t\t\\ \n" "${file:2}" 
done > log/list_files_c.txt

echo "Script completed successfully."