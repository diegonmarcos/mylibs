# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
SRCS_1 =	ft_printf.c ft_putchar.c ft_putnbr.c ft_num_unsign.c \
			ft_pointer_hexa.c ft_putstr.c ft_strlen.c ft_hexa_minusc.c \
			ft_hexa_mayusc.c ft_fprintf1.c\

VPATH = src:include:objs

OBJS_1 = $(patsubst %.c,objs/%.o,$(notdir $(SRCS_1)))

#SRC_2 = 

#OBJS_2 = $(patsubst %.c,objs/%.o,$(SRCS_2))

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #
NAME = lib_ft_printf.a
CC = clang
RM = rm -rf
AR = ar rcs
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