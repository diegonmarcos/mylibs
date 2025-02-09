#!/bin/bash
set -v
exec > ast.log 2>&1
set > env_vars.txt


# Get C++ flags.
CXXFLAGS=$(llvm-config --cxxflags)

# Get include directories (not strictly necessary if CXXFLAGS is correct, but good practice).
LINCLUDE="-I$(llvm-config --includedir)"

# Get linker flags and libraries *in the correct order*.  This is the crucial part.
LDFLAGS=$(llvm-config --ldflags)
COMP_LIBS="-lclangTooling -lclangFrontend -lclangAST -lclangParse -lclangSema -lclangAnalysis -lclangEdit -lclangLex -lclangBasic -lclangDriver -lclangCodeGen"
LIBS=$(llvm-config --libs) $(llvm-config --system-libs)

# Build the command line.
clang++ $CXXFLAGS $LINCLUDE -o clang_ast ast.cpp $LDFLAGS $COMP_LIBS $LIBS > output_file.txt

echo "CXXFLAGS: $CXXFLAGS"
echo "LINCLUDE: $LINCLUDE"
echo "LDFLAGS: $LDFLAGS"
echo "COMP_LIBS: $COMP_LIBS"
echo "LIBS: $LIBS"
