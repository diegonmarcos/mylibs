# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
SRCS_1 = 	get_next_line.c		\
		  		get_next_line_utils.c	\

OBJS_1 = ${SRCS_1:.c=.o}

SRC_2 = 

OBJS_2 = ${SRC_2:.c=.o}

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #
NAME = get_next_line.a
CC = gcc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib
CFLAGS = -Wall -Wextra -Werror

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #
all: $(NAME)

%.o: %.c
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
	$(RM) $(OBJS_1) $(OBJS_2)
	@echo	"	¯\_(ツ)_/¯ OBJECTS REMOVED!"

fclean:	clean
		rm -f $(NAME)
		@echo	"	(╯°□°）╯︵ ┻━┻ FILE REMOVED!"

re: fclean all

.PHONY: all clean fclean re bonus