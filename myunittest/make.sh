#!/bin/bash

lib_inc="/home/diego/Documents/Git/mylibs/mylibc/inc"
lib_addss="/home/diego/Documents/Git/mylibs/mylibc"
lib_name="mylibc"

### CLEANING
if [ "$1" = "clean" ]; then
	rm -rf tests/gnl/tests/*.md
	rm -rf tests/gnl/tests/*.log
	rm -rf tests/gnl/tests/*_out
	rm -rf tests/gnl/tests/*_dbg
	rm -rf tests/gnl/tests/*_vlg
	return
fi

### COMPILING DEPS
(cd tests/gnl && bash make.sh)

### COMPILING
##-O0 -fno-inline -fno-omit-frame-pointer -fno-optimize-sibling-calls
mkdir -p obj
clang \
-c -g3 \
src/myunit.c \
-I"${lib_inc}" \
-o obj/myunit.o

### LINKING
clang \
obj/myunit.o \
tests/gnl/obj/get_next_line.o \
-L"${lib_addss}" -l"${lib_name}" \
-o get_next_line.out

if [ "$1" = "run" ]; then
	./get_next_line.out
fi


### EXECUTING
#./get_next_line.out

