#!/bin/bash

if [ $# -eq 0 ]; then  # Check if no arguments are provided
  echo "Usage: $0 [-1a] [-1b] [-1c] [-1d] [-2] [-3] [-4] [-5] [-6] [-r]"
  echo "  -1a: Run libft-war-machine "
  echo "  -1b: Run libft-tester"
  echo "  -1c: Run libft-unit-test"
  echo "  -1d: Run Francinette"
  echo "  -2 : Run printfTester-master"
  echo "  -3 : Run gnl_tester"
  echo "  -4 : Run fdf_tester"
  echo "  -5 : Run minitalk_tester"
  echo "  -6 : Run pipex_tester"
  echo "  -r : Delete Tester folders"
  exit 1
fi

while [[ $# -gt 0 ]]; do
  case "$1" in
    -1a)
		# libft-war-machine
		## copy src folder
		rm -rf 0_libft
		mkdir src_tester/0_libft
		cp lib/src_lib/* 0_libft/
		## run libft-war-machine
		bash libft-war-machine/grademe.sh
		make -C 0_libft fclean
		## delete folders
		rm -rf src_tester/0_libft
		norminette
		shift
      	;;
    -1b)
		# libft-tester
		## copy src folder
		rm -rf 0_libft
		mkdir src_tester/0_libft
		cp lib/src_lib/* 0_libft/
		## run libft-tester
		make -C libft-tester
		make -C 0_libft fclean
		## delete folders
		rm -rf src_tester/0_libft
		norminette
		shift
		;;
    -1c)
		# libft-unit-test
		## copy src folder
		rm -rf 0_libft
		mkdir src_tester/0_libft
		cp lib/src_lib/* 0_libft/
		## run libft-unit-test (replace with your actual command)
		make -C libft-unit-test fclean
		make -C libft-unit-test
		make -C libft-unit-test f
		make -C 0_libft fclean
		make -C 0_libft fclean
		## delete folders
		rm -rf src_tester/0_libft
		norminette
		shift
      ;;
    -1d)
		# Francinette
		echo "Running Francinette..."
		## copy src folder
		rm -rf 0_libft
		mkdir src_tester/0_libft
		cp lib/src_lib/* 0_libft/
		## run Francinette (replace with your actual command)
		make -C 0_libft fclean
		## delete folders
		rm -rf src_tester/0_libft
		norminette
		shift
		;;
	-2)
		# printfTester-master
		echo "Running printfTester-master..."
		# PRINTF TESTER
		## printf_tester
		### Find all .c files in src_tester/printf_t and copy them to src
			rm -f src/*
			find src_tester/printf_t -name "*.*" -exec cp {} src \;
		### Run libunit make
			make
			make fclean
			rm -f src/*
		## printfTester-master
		### Copy the folder
			cp -r src_tester/printfTester-master lib/src_lib/

		### Run make
			make -C lib/src_lib/printfTester-master

		### Wait for 1 second
			sleep 1

		### Delete the folder and clean object files
			make -C lib/src_lib/printfTester-master fclean
			rm -rf lib/src_lib/printfTester-master
			norminette
		shift
		;;
    -3)
      # gnl_tester
	   echo "Running gnl_tester..."
      ## copy src folder (if needed)
		find src_tester/gnl_t/tester -name "*.*" -exec cp {} src \;
		make
		norminette
      shift
      ;;
    -4)
      # fdf_tester
	  echo "Running fdf_tester..." # Replace this with your command
      norminette
      shift
      ;;
    -5)
		# minitalk_tester
		echo "Running minitalk_tester..." # Replace this with your command
		norminette
		shift
		;;
    -6)
		# pipex_tester
		echo "Running pipex_tester..." # Replace this with your command
		norminette
		shift
		;;
    -r)
		# Delete Tester folders
		echo "Deleting Tester folders..."
		# Add your commands to delete the tester folders here
		shift
		;;
    *)
		echo "Usage: $0 [-1a] [-1b] [-1c] [-1d] [-2] [-3] [-4] [-5] [-6] [-r]"
  		echo "  -1a: Run libft-war-machine "
		echo "  -1b: Run libft-tester"
		echo "  -1c: Run libft-unit-test"
		echo "  -1d: Run Francinette"
		echo "  -2 : Run printfTester-master"
		echo "  -3 : Run gnl_tester"
		echo "  -4 : Run fdf_tester"
		echo "  -5 : Run minitalk_tester"
		echo "  -6 : Run pipex_tester"
		echo "  -r : Delete Tester folders"
		exit 1
		;;
  esac
done