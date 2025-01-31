# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:09:01 by dinepomu          #+#    #+#              #
#    Updated: 2025/01/31 12:53:43 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 MAKEFILE                                     #
# **************************************************************************** #

# Notes:
# - This Makefile is a template for a project with the following structure:
#   1. Headers.h, files all them must be placed inside the folder "include".
#   2. Library.a, files all them must be inside of the folder "libs"
#   3. The library makefile must be inside of the folder "libs/mylib"

#my_project/
#├── include/
#│   ├── main.h
#│   └── mylib.h
#│
#├── libs/
#│   ├── mylib/
#│   │   ├── src/
#│   │   │   └── mylib.c
#│   │   │── objs/
#│   │   │   └── mylib.o
#│   │   └── Makefile		<-- (1) Sub-Makefile for the library
#│   └── libmylib.a			<-- (2) Library file outside mylib directory
#│
#├── objs/
#│   ├── main.o
#│   ├── main_utils.o
#│   ├── main_utils1.o
#│   └── main_utils2.o
#│
#├── src/
#│   └── main.c
#│       ├── UtilsA/
#│       │   ├── main_utils.c
#│       │   └── main_utils1.c
#│       └── UtilsB/
#│          └── main_utils2.c
#│
#└── Makefile

# **************************************************************************** #
# **************************************************************************** #
###IS PROGRAM?
IS_PROGRAM_AND_NOT_LIB = 0
INCLUDE_LIB = 0
BUILD_LIBRARY = 0

.SILENT:

#IS_LIB_STATIC_AND_NOT_DYNAMIC = 1

# **************************************************************************** #
# **************************************************************************** #
### SOURCE OF FILES *.c
PRGM_SRC_MAIN =	main.c

PRGM_SRC_HELPERS = 	main_utils.c	\
					main_utils1.c	\
					main_utils2.c	\

LIB_SRC_FUNCTIONS = 	0.bubble_sort.c			\
						0.insertion_sort.c		\
						0.selection_sort.c		\
						1.merge_sort.c			\
						1.quick_sort.c		\
						2.radix_sort.c		\
						3.intro_sort0.c		\
						3.intro_sort1.c		\
						L2_graycode.c		\
						bitwise.c			\
						bst.c				\
						flood_fill.c		\
						ft_atoi.c			\
						ft_atoi_base.c		\
						ft_bzero.c			\
						ft_calloc.c			\
						ft_fprintf1.c		\
						ft_free.c			\
						ft_garbage_collector_1.c		\
						ft_garbage_collector_2.c		\
						ft_hexa_mayusc.c				\
						ft_hexa_minusc.c				\
						ft_pointer_hexa_fd_fpr.c		\
						ft_putchar_fd_fpr.c				\
						ft_putnbr_fd_fpr.c				\
						ft_putstr_fd_fpr.c				\
						ft_isalnum.c		\
						ft_isalpha.c		\
						ft_isascii.c		\
						ft_isdigit.c		\
						ft_isprint.c		\
						ft_itoa.c			\
						ft_memchr.c			\
						ft_memcmp.c			\
						ft_memcpy.c			\
						ft_memmove.c		\
						ft_memset.c			\
						ft_num_unsign.c		\
						ft_pointer_hexa.c	\
						ft_printf.c			\
						ft_putchar.c		\
						ft_putchar_int.c	\
						ft_putchar_fd.c		\
						ft_putendl_fd.c		\
						ft_putnbr.c			\
						ft_putnbr_fd.c		\
						ft_putstr1.c		\
						ft_putstr_fd.c		\
						ft_split.c			\
						ft_strchr.c			\
						ft_strdup.c			\
						ft_striteri.c		\
						ft_strjoin.c		\
						ft_strlcat.c		\
						ft_strlcpy.c		\
						ft_strlen.c			\
						ft_strmapi.c		\
						ft_strncmp.c		\
						ft_strnstr.c		\
						ft_strrchr.c		\
						ft_strtrim.c		\
						ft_substr.c			\
						ft_tolower.c		\
						ft_toupper.c		\
						get_next_line.c		\
						get_next_line_utils.c		\
						get_next_line2.c			\
						linked_list_doubly1.c		\
						linked_list_doubly2.c		\
						print_bits.c				\
						reverse_bits.c				\
						swap_bits.c					\
						halt_exit.c					\
						ft_putstr1.c				\
						ft_garbage_collector_bff.c	\
						ft_swap_pointers.c			\
						ft_array_to_d_linked_list.c \
						ft_contains.c				\
						ft_digits_to_bits.c			\
						ft_free_list_doubly.c		\
						ft_free_ls_simple.c			\
#						get_next_line.c 			\
						get_next_line2_utils.c		\
						get_next_line_utils.c 		\
						ft_lstadd_back_bonus.c 		\
						ft_lstadd_front_bonus.c 	\
						ft_lstclear_bonus.c 		\
						ft_lstdelone_bonus.c 		\
						ft_lstiter_bonus.c 			\
						ft_lstlast_bonus.c 			\
						ft_lstmap_bonus.c 			\
						ft_lstnew_bonus.c 			\
						ft_lstsize_bonus.c 			\


#PRGM_SRC_MAIN = $(wildcard src/*.c) $(wildcard src/*/*.c)

VPATH = src:include:objs:		\
		src/src_all:			\

### SOURCE OF FILES *.a (libraries to be included)
LIBS_DIR = libs
LIB_1_NAME = ft_mylib
LIB_1_PATH = $(LIBS_DIR)/$(LIB_1_NAME)


# **************************************************************************** #
# **************************************************************************** #
### COMPILER AND FLAGS DECLARATION
NAME1 = ft_mylib#Name as OUTPUT of the compiled									# If library DONT add prefix "lib" or the end it with ".a"(static) or ".sa"

MAKE = make -j -O --no-print-directory #																# Number of jobs to run in parallel	wihtou the number go max
COMPILER = clang

LIB_COMP_STATIC = ar rcs
#LIB_COMP_DYNAMIC_obj = fPIC
#LIB_COMP_DYNAMIC_lib = shared

CFLAGS_INCL = -Iinclude -Ilibs/include											# Folder to look for headers:inlcude and libs

CFLAGS_DBG = -Wall -Wextra -Werror
CFLAGS_DBG += -g3
#CFLAGS_DBG += -fsanitize=address -lasan

CFLAGS = $(CFLAGS_INCL) $(CFLAGS_DBG)

RM = rm -rf

# **************************************************************************** #
# **************************************************************************** #
### HELPERS

### Name definition
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
    NAME = $(NAME1)
else
    NAME = ../lib$(NAME1).a
endif

### Source File Definition
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	SOURCES = $(PRGM_SRC_MAIN) $(PRGM_SRC_HELPERS)
else
	SOURCES = $(LIB_SRC_FUNCTIONS)
endif

#Object Files and Dependency Files Definition
	OBJECTS =  $(patsubst %.c,objs/%.o,$(notdir $(SOURCES)))						# This will create the object files in the folder "objs"
	DEPS = $(OBJECTS:.o=.d)
	DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them

### Include or not a library
LIBS +=
ifeq ($(INCLUDE_LIB), 1)
	LIBS += -L$(LIB_1_PATH) -l$(LIB_1_NAME)
#	LIBS += -L$(LIB_2_PATH) -l$(LIB_2_NAME)
endif

# **************************************************************************** #
#                                 RULES/ALL                                    #
# **************************************************************************** #
all:	$(NAME)

objs/%.o:	%.c
	@mkdir -p objs
	@$(COMPILER) $(CFLAGS_INCL) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo "$(GRAY)()و $@ OBJECTS GENERATED!$(RESET)"

-include $(DEPS)#																Include the .d files after the rule is defined

$(NAME): program_or_lib
program_or_lib:
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	@$(MAKE) check_up_to_date
	@$(MAKE) program
	@$(MAKE) check_up_to_date
else
	@$(MAKE) check_up_to_date
	@$(MAKE) lib
	@$(MAKE) check_up_to_date
endif


program:	$(OBJECTS) libs_build
		@$(COMPILER) $(CFLAGS_INCL) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)
		@echo	"$(RED)	(•̀ᴗ•́)و BIN GENERATED!$(RESET)"

lib:	$(OBJECTS)
		@$(LIB_COMP_STATIC) $(NAME) $(OBJECTS)
		@echo "$(YELLOW)(•̀ᴗ•́)و LIBRARY GENERATED!$(RESET)"

# **************************************************************************** #
#                                 RULES/RECLEAN                                #
# **************************************************************************** #
clean:
	$(RM) objs
	@echo	"$(RED)	¯\_(ツ)_/¯ OBJECTS REMOVED!$(RESET)"

fclean:	clean
	$(RM) -f $(NAME)
	@echo	"$(RED)	(╯°□°）╯︵ ┻━┻ FILE REMOVED!$(RESET)"

library_clean:
	$(MAKE) -C $(LIB_1_PATH) clean

library_fclean:
	$(MAKE) -C $(LIB_1_PATH) fclean

library_re:
	$(MAKE) -C $(LIB_1_PATH) re

re: fclean all

.PHONY: all clean fclean re bonus libs_build program_or_lib program lib update_folder

# **************************************************************************** #
#                                DEFS/COLORS                                   #
# **************************************************************************** #

# Define the target for the script
update_folder:
	@# 1. Delete src_all and include_all if they exist
	@if [ -d "src/src_all" ]; then \
		echo "Deleting existing src/src_all directory..."; \
		rm -rf "src/src_all"; \
	fi

	@if [ -d "include" ]; then \
		echo "Deleting existing include directory..."; \
		rm -rf "include"; \
	fi

	@# Create the destination directories if they don't exist (they shouldn't after the previous step)
	@echo "Creating src/src_all and include directories..."
	@mkdir -p "src/src_all"
	@mkdir -p "include"

	@# 2. Find .c and .h files and copy them
	@echo "Copying .c and .h files..."
	@find src/ -mindepth 1 -maxdepth 5 -type f \( -name "*.c" \) -print0 | xargs -0 -I {} cp {} src/src_all/
	@find src/ -mindepth 1 -maxdepth 5 -type f \( -name "*.h" \) -print0 | xargs -0 -I {} cp {} include/

	@echo "Script completed successfully."
	$(MAKE) $(NAME)

check_up_to_date:
ifeq ($(MAKECMDGOALS),all) # Only check if 'all' is the explicit goal
	@# Check if $(NAME) exists. If not, skip the up-to-date check.
	@if [ ! -f "$(NAME)" ]; then \
		echo "$(YELLOW)$(NAME) does not exist. Building...$(RESET)"; \
	else \
		# If $(NAME) exists, check if any source files are newer.
		@if find src/ include/ -newer "$(NAME)" -print | grep -q .; then \
			echo "$(YELLOW)Some files have changed. Rebuilding...$(RESET)"; \
		else \
			echo "$(GREEN)Everything up-to-date.$(RESET)"; \
			exit 0; \
		fi \
	fi
endif
ifeq ($(MAKECMDGOALS),check_up_to_date) # Special handling for 'make check_up_to_date'
	@if [ -f "$(NAME)" ] && find src/ include/ -newer "$(NAME)" -print | grep -q .; then \
		echo "$(YELLOW)Some files have changed. Run 'make all' to rebuild.$(RESET)"; \
	else \
		echo "$(GREEN)$(NAME) is up-to-date.$(RESET)"; \
		exit 0; \
	fi
endif

### Build or not a library
libs_build:
ifeq ($(BUILD_LIBRARY), 1)
	$(MAKE) -C $(LIB_1_PATH)
#	$(MAKE) -C $(LIB_2_PATH)
	@echo "$(RED)(•̀ᴗ•́)و $@ DONE!$(RESET)"
else
	@echo "$(RED)Skipping library build$(RESET)"
endif

hello:
	@echo "$(GREEN)\nHello, $(USER)!\n$(RESET)"
	@echo "$(GREEN)### Welcome to Makefile for: $(NAME)! ###\n$(RESET)"
	@echo "$(GREEN)################################################\n$(RESET)"

#_Colors
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
RESET =			\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

# **************************************************************************** #
#                      RUN:NORM|TESTERS && CODE_CLEANER                        #
# **************************************************************************** #
#code_cleaner:
#	bash tester/code_cleaner.sh $(NAME)

test: re
	@echo "$(BOLD)\n# RUNNING TESTS$(RESET)"
	@echo ""

	@echo "$(BOLD)### MILESTONES$(RESET)"
	@echo ""

	@echo "$(BOLD)### RUNNING NORMINETTE$(RESET)"	
	norminette 

	@echo "$(BOLD)### RUNNING TESTS$(RESET)"
	bash tester/tests.sh
