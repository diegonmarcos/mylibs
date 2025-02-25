#!/usr/bin/env zsh

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

### COMPILERS WITH LIB
# --- Compile FILES with Library
function cl {
	lib_header="/home/diego/Documents/Git/libft_xtend/ft_mylib/include"
	lib_addss="/home/diego/Documents/Git/libft_xtend"
	lib_name="ft_mylib"
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "$(basename "$1" .c).out"
	./"$(basename "$1" .c).out" "${@}"
}

# --- Compile FILE+ARG with Library and Execute
function clx {
	lib_header="/home/diego/Documents/Git/libft_xtend/ft_mylib/include"
	lib_addss="/home/diego/Documents/Git/libft_xtend"
	lib_name="ft_mylib"
	clang -g3 "$1" -I"${lib_header}" -L"${lib_addss}" -l"${lib_name}" -o "$(basename "$1" .c).out"
	./"$(basename "$1" .c).out" "${@:2}"
}

### DEBUGE
# --- LLDB
function cdb {
  echo -e "\n\n\n##########################"
  echo -e "##### LLDB ##########"
  echo -e "##########################\n\n"
  clang "$1" -o "$(basename "$1" .c)_dbD.db.out" -g
  lldb ./"$(basename "$1" .c)_dbD.db.out" "${@:2}"
}

### MAKE UTILS
# --- CODE CLEANER
function code_cleaner {
	folder="/home/diego/Documents/Git/libft_xtend/ft_mylib/src/9_Quality_Assurance/Code_Cleaner"
	file="clean_code.sh"
	"$folder/$file" "$@"
}

# --- Search Recursively and Consolidate with Symb Link
function file_consol_lns {
	folder="/home/diego/Documents/Git/libft_xtend/tools/0_Coding/Make_Utils"
	file="files_lns.sh"
	"$folder/$file" "$@"
}
