# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2023/01/20 00:42:06 by arnaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC = solong.c mapcheck.c init.c get_next_line.c get_next_line_utils.c



OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

INC =   include

LIB = -L ./libft minilibx_macos/libmlx.a

.c.o:
	$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libft
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIB)


clean:
	make clean -C libft
	$(RM) $(OBJS) $(NAME) 


fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re