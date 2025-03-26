#!bin/bash

lib_inc="/home/diego/Documents/Git/mylibs/mylibc/inc"
lib_addss="/home/diego/Documents/Git/mylibs/mylibc"
lib_name="mylibc"

clang \
-c -g3 \
src/get_next_line.c \
-Iinc -I"$lib_inc" \
-o obj/get_next_line.o

# -O0 -fno-inline -fno-omit-frame-pointer -fno-optimize-sibling-calls
