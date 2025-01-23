# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:09:01 by dinepomu          #+#    #+#              #
#    Updated: 2025/01/23 13:29:45 by dinepomu         ###   ########.fr        #
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

IS_LIB_STATIC_AND_NOT_DYNAMIC = 1

# **************************************************************************** #
# **************************************************************************** #
### SOURCE OF FILES *.c
PRGM_SRC_MAIN =	main.c

PRGM_SRC_HELPERS = 	main_utils.c	\
					main_utils1.c	\
					main_utils2.c	\

LIB_SRC_FUNCTIONS = 	mylib.c \
						function1.c	\
						function2.c	\

#PRGM_SRC_MAIN = $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)

VPATH = src:include:libs	\
		../../libs:			\
		../../include:		\
		../../src:			\
		../../include:		\

### SOURCE OF FILES *.h (inside include and libs)
#CFLAGS_INCL = -Iinclude														# Folder:inlcude
#CFLAGS_INCL += -Ilibs															# Folder:libs

### SOURCE OF FILES *.a (libraries to be included)
LIBS_DIR = libs
LIB_1_NAME = ft_mylib
LIB_1_PATH = $(LIBS_DIR)/$(LIB_1_NAME)


# **************************************************************************** #
# **************************************************************************** #
### COMPILER AND FLAGS DECLARATION
NAME1 = ft_mylib#Name as OUTPUT of the compiled									# If library DONT add prefix "lib" or the end it with ".a"(static) or ".sa"

COMPILER = clang

LIB_COMP_STATIC = ar rcs
#LIB_COMP_DYNAMIC_obj = fPIC
#LIB_COMP_DYNAMIC_lib = shared

CFLAGS_INCL = -Iinclude -Ilibs													# Folder:inlcude and libs

CFLAGS_DBG = -Wall -Wextra -Werror
#CFLAGS_DBG += -g
#CFLAGS_DBG += -fsanitize=address -lasan

CFLAGS = $(CFLAGS_INCL) $(CFLAGS_DBG)

RM = rm -rf

# **************************************************************************** #
# **************************************************************************** #
### HELPERS

### Name definition
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 0)
    NAME = $(NAME1)
else
    NAME = ../lib_$(NAME1).a
endif

### Source File Definition
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 0)
    SOURCES = $(PRGM_SRC_MAIN) $(PRGM_SRC_HELPERS)
else
    SOURCES = $(LIB_SRC_FUNCTIONS)
endif

#Object Files and Dependency Files Definition
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d)
DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them

### Include or not a library
LIBS +=
ifeq ($(INCLUDE_LIB), 1)
	LIBS += -L$(LIB_1_PATH) -l$(LIB_1_NAME)
#	LIBS += -L$(LIB_2_PATH) -l$(LIB_2_NAME)
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

# **************************************************************************** #
#                                 RULES/ALL                                    #
# **************************************************************************** #
all:	$(NAME)

objs/%.o:	%.c
	@mkdir -p objs
	$(COMPILER) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo "$(RED)(•̀ᴗ•́)و $@ OBJECTS GENERATED!$(RESET)"

-include $(DEPS_1)#																Include the .d files after the rule is defined

$(NAME): program_or_lib
program_or_lib:
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	$(MAKE) program
else
	$(MAKE) lib
endif

program:	$(OBJECTS) libs_build
		$(COMPILER) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)
		@echo	"$(RED)	(•̀ᴗ•́)و BIN GENERATED!$(RESET)"

lib:	$(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)
		@echo	"$(RED)	(•̀ᴗ•́)و LIBRARY GENERATED!$(RESET)"

# **************************************************************************** #
#                                 RULES/RECLEAN                                #
# **************************************************************************** #
clean:
	$(RM) objs
	@echo	"$(RED)	¯\_(ツ)_/¯ OBJECTS REMOVED!$(RESET)"

fclean:	clean
		rm -f $(NAME)
		@echo	"$(RED)	(╯°□°）╯︵ ┻━┻ FILE REMOVED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus libs_build

# **************************************************************************** #
#                                DEFS/COLORS                                   #
# **************************************************************************** #
hello:
	@echo "$(GREEN)\nHello, $(USER)!\n$(RESET)"
	@echo "$(GREEN)### Welcome to Makefile for: $(NAME_OUTPUT)! ###\n$(RESET)"
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
