# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2023/01/19 16:44:36 by abeaudui         ###   ########.fr        #
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

LIB = -L ./libft ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx

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