# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #
SRCS_1 =  	ft_memset.c		\
		  		ft_memmove.c	\
		  		ft_memchr.c		\
		  		ft_memcmp.c		\
		  		ft_memcpy.c		\
		  		ft_bzero.c		\
		  		ft_atoi.c		\
		  		ft_strlen.c		\
		  		ft_strlcpy.c	\
		  		ft_strlcat.c	\
		 	 	ft_strchr.c		\
		 		ft_strrchr.c	\
		  		ft_strnstr.c	\
				ft_strncmp.c	\
		  		ft_isalnum.c	\
		  		ft_isdigit.c	\
		  		ft_isalpha.c	\
		  		ft_isascii.c	\
		 		ft_isprint.c	\
		  		ft_tolower.c	\
		  		ft_toupper.c	\
		  		ft_calloc.c		\
		  		ft_strdup.c		\
				ft_itoa.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_striteri.c	\
				ft_lstnew_bonus.c 		\
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c 		\
				ft_lstlast_bonus.c 		\
				ft_lstadd_back_bonus.c 	\
				ft_lstdelone_bonus.c 	\
				ft_lstclear_bonus.c 	\
				ft_lstiter_bonus.c 		\
				ft_lstmap_bonus.c		\

VPATH = src:include:objs

OBJS_1 = $(patsubst %.c,objs/%.o,$(notdir $(SRCS_1)))

#SRC_2 = 

#OBJS_2 = $(patsubst %.c,objs/%.o,$(SRCS_2))

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #
NAME = libft.a
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