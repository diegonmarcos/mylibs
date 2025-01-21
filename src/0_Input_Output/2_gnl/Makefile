# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
SRCS_1 = 	src/get_next_line.c		\
		  	src/get_next_line_utils.c	\

VPATH = src:include:objs

OBJS_1 = $(patsubst %.c,objs/%.o,$(notdir $(SRCS_1)))

#SRC_2 = 

#OBJS_2 = $(patsubst %.c,objs/%.o,$(SRCS_2))

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #
NAME = get_next_line.a
CC = clang
RM = rm -rf
AR = ar rcs
RANLIB = ranlib
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iinclude

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #
all:	$(NAME)

objs/%.o:	%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "(•̀ᴗ•́)و $@ OBJECTS GENERATED!"

$(NAME):	$(OBJS_1)
			$(AR) $(NAME) $(OBJS_1)
			$(RANLIB) $(NAME)
			@echo	"	(•̀ᴗ•́)و FILE GENERATED!"

bonus:	$(NAME) $(OBJS_2)
		$(AR) $(NAME) $(OBJS_2)
		$(RANLIB) $(NAME)
		@echo	"	(•̀ᴗ•́)و BONUS GENERATED!"

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #
clean:
	$(RM) objs
	@echo	"	¯\_(ツ)_/¯ OBJECTS REMOVED!"

fclean:	clean
		rm -f $(NAME)
		@echo	"	(╯°□°）╯︵ ┻━┻ FILE REMOVED!"

re: fclean all

.PHONY: all clean fclean re bonus