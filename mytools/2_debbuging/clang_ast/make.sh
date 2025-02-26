#!/bin/bash
set -v
set > ast.log
exec >> ast.log 2>&1


# Check if llvm-config is available
if ! command -v llvm-config &> /dev/null
then
	if [ -d "/usr/lib/llvm-18/bin" ]; then
  	export PATH="/usr/lib/llvm-18/bin:$PATH"
	fi
	if ! command -v llvm-config &> /dev/null
	then
		echo "llvm-config could not be found"
		exit 1
	fi
fi
# Check if clang++ is available
if ! command -v clang++ &> /dev/null
then
	echo "clang++ could not be found"
	exit 1
fi



# Get C++ flags.
CXXFLAGS=$(llvm-config --cxxflags)

# Get include directories (not strictly necessary if CXXFLAGS is correct, but good practice).
LINCLUDE="-I$(llvm-config --includedir)"

# Get linker flags and libraries *in the correct order*.
// ... existing code ...

# Get linker flags and libraries *in the correct order*.
LDFLAGS=$(llvm-config --ldflags)
COMP_LIBS="-lclangDynamicASTMatchers \
-lclangASTMatchers \
-lclangTooling \
-lclangToolingCore \
-lclangFrontend \
-lclangParse \
-lclangSema \
-lclangAnalysis \
-lclangEdit \
-lclangRewrite \
-lclangRewriteFrontend \
-lclangSerialization \
-lclangCodeGen \
-lclangDriver \
-lclangAST \
-lclangLex \
-lclangBasic \
-lclangAPINotes \
-lclangFormat \
-lclangIndex \
-lclangSupport \
-lclangCrossTU \
-lclangToolingInclusions \
-lclangToolingASTDiff \
-lclangTransformer \
-lclangFrontendTool"

LIBS="-lLLVMSupport $(llvm-config --libs all) $(llvm-config --system-libs) -lpthread -lz -lcurses -lzstd"

echo "CXXFLAGS: $CXXFLAGS"
echo "LINCLUDE: $LINCLUDE"
echo "LDFLAGS: $LDFLAGS"
echo "COMP_LIBS: $COMP_LIBS"
echo "LIBS: $LIBS"

# Build the command line.
clang++ $CXXFLAGS $LINCLUDE -o clang_ast ast.cpp \
	$LDFLAGS \
	$COMP_LIBS \
	$LIBS

