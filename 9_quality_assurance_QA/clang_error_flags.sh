alias gcl='git clone'
alias push='git add . && git commit -m "update" && git push'
alias norm="norminette -R CheckForbiddenSourceHeader CheckDefine"

function c {
  clang "$1" -o "$(basename "$1" .c).out"
}

function cx {
  clang "$1" -o "$(basename "$1" .c).out"
  ./"$(basename "$1" .c).out" "${@:2}"
}

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
  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v --log-file=valgrind_output.txt ./"$(basename "$1" .c)_dbV.db.out" "${@:2}" > /dev/null | grep "$1": valgrind_output.txt

  rm asan_output.txt
  rm valgrind_output.txt
  rm *.db.out
  rm *.plist

}

function cdb {
  # --- LLDB
  echo -e "\n\n\n##########################"
  echo -e "##### LLDB ##########"
  echo -e "##########################\n\n"
  clang "$1" -o "$(basename "$1" .c)_dbD.db.out" -g
  lldb ./"$(basename "$1" .c)_dbD.db.out" "${@:2}"
}
