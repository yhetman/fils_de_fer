# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 01:12:39 by yhetman           #+#    #+#              #
#    Updated: 2019/04/14 01:20:39 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME		:=	fdf

SRC_PATH	:=	sources/

INC_PATH	:=	includes/

LIB_PATH	:=	libft/

OBJ_PATH	:=	obj/

CC :=		clang

CFLAGS :=	-g -Wall -Wextra -Werror

IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH)

LIB :=		$(LIB_PATH)libft.a

HFILES :=	fdf

FILES :=	main init_fdf init_line is_valid \
			rotation hooks error

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)

$(OBJ_PATH)%.o:	%.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:	mclean
		make clean -C $(LIB_PATH)

fclean:	mfclean
		make fclean -C $(LIB_PATH)

re:		fclean all

mclean:
		rm -rf $(OBJ_PATH)

mfclean:
		rm -f $(NAME)
		rm -rf $(OBJ_PATH)

mre:	mfclean all