#!/bin/bash

# CONSOLIDATION OF FILES.c and FILES.h INTO ONE FOLDER AS SYMBLINK
run () {
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
    ln -s "../${file#src/}" "src/src_all/$filename" || echo "Error creating symbolic link for $file"
done
# FILENAMES LIST OUTPUT .TXT for usage into MAKE source=
# Go to the specified directory (add a check or use absolute path)
cd src/src_all
# Find all.c files, sort them alphabetically, and format the output
find. -name "*.c" -print0 | sort -z | while IFS= read -r -d '' file; do
    printf "%s\t\t\\ \n" "${file:2}" 
done > log/list_files_c.txt
echo "Script completed successfully."
}

help() {
	bold=$(tput bold)
	gray=$(tput setaf 8)
	green=$(tput setaf 2)
    reset=$(tput sgr0)
	echo
    echo "${gray}############################################################################${reset}"
    echo "${gray}### CONSOLIDATION OF FILES${green}.c${gray} and FILES${green}.h${gray} WITH SYMBLINK Bash Shell Script ###${reset}"
    echo "${gray}############################################################################${reset}"
    echo
    echo "${gray}USAGE:${reset}"
    echo "  $0 [option]"
    echo
    echo "${gray}OPTIONS:${reset}"
    echo "  -h, --help    Display this help message."
    echo
    echo "${gray}DESCRIPTION:${reset}"
    echo "  This script consolidates .c and .h files into one folder as symbolic links."
    echo "  It performs the following actions:"
    echo "  1. Deletes the ${bold}src/src_all${reset} directory if it exists."
    echo "  2. Creates a new ${bold}src/src_all directory.${reset}"
    echo "  3. Finds all .c files in the src/ directory and creates symbolic links in src/src_all."
    echo "  4. Generates a list of all .c files and saves it to ${bold}log/list_files_c.txt.${reset}"
	echo
}


############
### MAIN ###
############
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
	help
elif [[ "$1" == "-h" || "$1" == "--help" ]]; then
	help
else
	run
fi


# colors
bold=$(tput bold)
reset=$(tput sgr0)
red=$(tput setaf 1)
green=$(tput setaf 2)
yellow=$(tput setaf 3)
blue=$(tput setaf 4)
magenta=$(tput setaf 5)
cyan=$(tput setaf 6)
white=$(tput setaf 7)
gray=$(tput setaf 8)
