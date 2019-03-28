NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC_FUNCTIONS = ft_putchar.c	ft_putendl.c	ft_putstr.c		\
				ft_putnbr.c		ft_strclr.c 	ft_putnbr_fd.c	\
				ft_putendl_fd.c	ft_putchar_fd.c	ft_putstr_fd.c	\
				ft_striteri.c	ft_striter.c	ft_strequ.c		\
				ft_strnequ.c	ft_memdel.c		ft_memalloc.c	\
				ft_strdel.c		ft_strnew.c		ft_strmap.c		\
				ft_strmapi.c	ft_strsub.c		ft_strtrim.c	\
				ft_strjoin.c	ft_strsplit.c	ft_itoa.c		\
				ft_strerr.c		ft_swap.c			\
				ft_range.c		ft_rgb_to_int.c	ft_lstnew.c		\
				ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
				ft_tolower.c	ft_lstiter.c	ft_lstmap.c		\
				ft_atoi.c		ft_bzero.c		ft_isalnum.c	\
				ft_isalpha.c	ft_isdigit.c	ft_isprint.c	\
				ft_isascii.c	ft_memset.c		ft_memcpy.c		\
				ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
				ft_memcmp.c		ft_strlen.c		ft_strdup.c		\
				ft_strcpy.c		ft_strncpy.c	ft_strcat.c		\
				ft_strncat.c	ft_strlcat.c	ft_strchr.c		\
				ft_strrchr.c	ft_strstr.c		ft_strnstr.c	\
				ft_strcmp.c		ft_strncmp.c	ft_toupper.c	\
				ft_display.c	ft_strrev.c		ft_strnlen.c	\
				ft_find_whitespaces.c			get_next_line.c	\
				ft_putwchar.c	ft_putwstr.c\
				ft_wstrlen.c	ft_wstrncpy.c	ft_wstrsub.c	\
				ft_pow.c ft_strchri.c
				
OBJ_FUNCTIONS = $(SRC_FUNCTIONS:.c=.o)

HEADERS = libft.h

all: $(NAME)
	
$(NAME): $(OBJ_FUNCTIONS)
	ar rcs $(NAME) $(OBJ_FUNCTIONS)
	ranlib $(NAME)
	
$(OBJ_FUNCTIONS): %.o: %.c $(HEADERS)
	gcc -o $@ $(FLAGS) -I. -c $<

clean:
	rm -rf $(OBJ_FUNCTIONS)

fclean: clean
	rm -rf $(NAME)

re: fclean all