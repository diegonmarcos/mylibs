#!/bin/bash

lib_header="/home/diego/Documents/Git/mylibs/mylibc/inc"
lib_addss="/home/diego/Documents/Git/mylibs/mylibc"
lib_name="mylibc"


### COMPILING DEPS
(cd tests/gnl && bash make.sh)

### COMPILING
##-O0 -fno-inline -fno-omit-frame-pointer -fno-optimize-sibling-calls
mkdir -p obj
clang \
-c -g3 \
src/myunit.c \
-I"${lib_header}" \
-o obj/myunit.o

### LINKING
clang \
obj/myunit.o \
tests/gnl/obj/get_next_line.o \
-L"${lib_addss}" -l"${lib_name}" \
-o get_next_line.out

### EXECUTING
#./get_next_line.out

