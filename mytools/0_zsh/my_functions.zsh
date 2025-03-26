#!/usr/bin/env zsh


#path_to_my_git="/home/diego/Documents/Git/"
path_to_my_git="/sgoinfre/goinfre/Perso/dinepomu/MyFiles_/git/"
				

### COMPILERS no LIB
# --- Compile FILES
function c {
	clang -g3 "$@" -o "$(basename "$1" .c).out"
	./"$(basename "$1" .c).out" "${@}"
}

# --- Compile FILE+ARG and Execute
function cx {
  clang -g3 "$1" -o "$(basename "$1" .c).out"
  ./"$(basename "$1" .c).out" "${@:2}"
}

# --- Compile FILE+ARG with Library and Execute
function cv {
#Variables
	valg_args="--leak-check=full --show-leak-kinds=all --track-origins=yes -s --log-file=valgrind_output.txt"
	program="./$(basename "$1" .c).out"
	output=" > /dev/null 2>&1"
	input="${@:2}"
#Main
	clang -g3 "$1" -o "$(basename "$1" .c).out"
	eval "valgrind ${valg_args} ${program} ${output} ${input}"
	grep "$1": valgrind_output.txt
}



### COMPILERS WITH LIB
# --- Compile FILES with Library
function cl {
	lib_header="${path_to_my_git}mylibs/mylibc/inc"
	lib_addss="${path_to_my_git}mylibs/mylibc"
	lib_name="mylibc"
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "$(basename "$1" .c).out"
	./"$(basename "$1" .c).out" "${@}"
}

# --- Compile FILE+ARG with Library and Execute
function clx {
	lib_header="${path_to_my_git}mylibs/mylibc/inc"
	lib_addss="${path_to_my_git}mylibs/mylibc"
	lib_name="mylibc"
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "$(basename "$1" .c).out"
	./"$(basename "$1" .c).out" "${@:2}"
}

# --- Compile FILE+ARG with Library and Execute
function clv {
#Variables
	lib_header="${path_to_my_git}mylibs/mylibc/inc"
	lib_addss="${path_to_my_git}mylibs/mylibc"
	lib_name="mylibc"
	valg_args="--leak-check=full --show-leak-kinds=all --track-origins=yes -s --log-file=valgrind_output.txt"
	program="./$(basename "$1" .c).out"
	output=" > /dev/null 2>&1"
	input="${@:2}"
#Main
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "$(basename "$1" .c).out"
	eval "valgrind ${valg_args} ${program} ${output} ${input}"
	grep "$1": valgrind_output.txt
}



### DEBUG
# --- LLDB
function cdb {
	echo -e "\n\n\n################################################################"
	echo -e "##### CLANG LLDB #####################################################"
	echo -e "# b main or b [function_name]\t# Set a breakpoint at the start of the 'main' function"
	echo -e "# r\t\t# Run the program"
	echo -e "# "
	echo -e "# s\t\t# Step over the current line (execute it as one step)"
	echo -e "# finish\t\t# Step out of the current function"
	echo -e "# "
	echo -e "# n\t\t# Step into the next line (enter functions if called)"
	echo -e "# "
	echo -e "# v\t\t# View all local variables (useful after hitting a breakpoint)"
	echo -e "# bt\t\t# View the current call stack"
	echo -e "# "
	echo -e "# c\t\t# Continue execution after hitting a breakpoint"
	echo -e "# "
	echo -e "# gui\t\t# Launch the LLDB graphical user interface (full screen)"
	echo -e "#######################################################################\n\n"
	output_name="$(basename "$1" .c)_dbD.db.out"
	clang -g3 "$1" -l"${lib_name}" -o "${output_name}"
	lldb ./"${output_name}" "${@:2}" -o "b main" -o "run" -o "v"
}

# --- CLANG_LLDB
function cldb {
	echo -e "\n\n\n################################################################"
	echo -e "##### CLANG LLDB #####################################################"
	echo -e "# b main or b [function_name]\t# Set a breakpoint at the start of the 'main' function"
	echo -e "# r\t\t# Run the program"
	echo -e "# "
	echo -e "# s\t\t# Step over the current line (execute it as one step)"
	echo -e "# finish\t\t# Step out of the current function"
	echo -e "# "
	echo -e "# n\t\t# Step into the next line (enter functions if called)"
	echo -e "# "
	echo -e "# v\t\t# View all local variables (useful after hitting a breakpoint)"
	echo -e "# bt\t\t# View the current call stack"
	echo -e "# "
	echo -e "# c\t\t# Continue execution after hitting a breakpoint"
	echo -e "# "
	echo -e "# gui\t\t# Launch the LLDB graphical user interface (full screen)"
	echo -e "#######################################################################\n\n"
	output_name="$(basename "$1" .c)_dbD.db.out"
	lib_header="${path_to_my_git}mylibs/mylibc/inc"
	lib_addss="${path_to_my_git}mylibs/mylibc"
	lib_name="mylibc"
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "${output_name}"
	lldb ./"${output_name}" "${@:2}" -o "b main" -o "run" -o "v"
}

# --- GCC_GDB
function cldbg {
	echo -e "\n\n\n################################################################"
	echo -e "##### GCC GDB #####################################################"
	echo -e "# b main or b [function_name]\t# Set a breakpoint at the start of the 'main' function"
	echo -e "# r\t\t# Run the program"
	echo -e "# "
	echo -e "# s\t\t# Step over the current line (execute it as one step)"
	echo -e "# finish\t\t# Step out of the current function"
	echo -e "# "
	echo -e "# n\t\t# Step into the next line (enter functions if called)"
	echo -e "# "
	echo -e "# info locals\t\t# View all local variables (useful after hitting a breakpoint)"
	echo -e "# bt\t\t# View the current call stack"
	echo -e "# "
	echo -e "# c\t\t# Continue execution after hitting a breakpoint"
	echo -e "# "
	echo -e "# gui\t\t# Launch the LLDB graphical user interface (full screen)"
	echo -e "#######################################################################\n\n"
	output_name="$(basename "$1" .c)_dbD.db.out"
	lib_header="${path_to_my_git}mylibs/mylibc/inc"
	lib_addss="${path_to_my_git}mylibs/mylibc"
	lib_name="mylibc"
	gcc -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "${output_name}"
	gdb ./"${output_name}" "${@:2}" -ex "b main" -ex "run" -ex "info locals"
}


### MAKE UTILS
# --- CODE CLEANER
function code_cleaner {
	folder="${path_to_my_git}libft_xtend/ft_mylib/src/9_Quality_Assurance/Code_Cleaner"
	file="clean_code.sh"
	"$folder/$file" "$@"
}

# --- CODE CLEANER
function clean_debuger {
	folder="${path_to_my_git}mylibs/mytools/1_coding/make_utils"
	file="clean_debuger.sh"
	"$folder/$file" "$@"
}

# --- Search Recursively and Consolidate with Symb Link
function file_consol_lns {
	folder="${path_to_my_git}mylibs/mytools/1_coding/make_utils"
	file="files_lns.sh"
	"$folder/$file" "$@"
}









# --- Compile and proofing Clang flasg checker
function ce {
  # --- Clang/gcc flags
  echo -e "\n\n\n##########################"
  echo -e "##### Clang Flags ########"
  echo -e "##########################"

  echo -e "\n##Clang Wall Wextra - fsyntaxOnly"
  echo -e "############################################\n"
  clang -fsyntax-only -Wall -Wextra "$1"

  echo -e "\n##Clang Fron-End Semantic - fsyntaxOnly"
  echo -e "############################################\n"
  clang -fsyntax-only -Wformat -Warray-bounds -Wnull-dereference -Wvla -ftrapv "$1" 2>&1

  echo -e "\n###Clang Static Analyzer"
  echo -e "#########################\n"
  clang --analyze -Xanalyzer -analyzer-checker=core "$1" 2>&1

  # --- Run with ASan ---
  echo -e "\n\n\n##########################"
  echo -e "##### ASanitizer #########"
  echo -e "##########################\n\n"
  clang "$1" -o "$(basename "$1" .c)_dbA.db.out" -g -fsanitize=address -fsanitize-recover=address
  ./"$(basename "$1" .c)_dbA.db.out" "${@:2}" 2> asan_output.txt ; grep "$1" asan_output.txt

  # --- Run Valgrind ---
  echo -e "\n\n\n##########################"
  echo -e "##### Valgrind ###########"
  echo -e "##########################\n\n"
  clang "$1" -o "$(basename "$1" .c)_dbV.db.out" -g
  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v --log-file=valgrind_output.txt ./"$(basename "$1" .c)_dbV.db.out" "${@:2}" > /dev/null ; grep "$1": valgrind_output.txt

  rm asan_output.txt
  rm valgrind_output.txt
  rm *.db.out
  rm *.plist
  rm .out

}