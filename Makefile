# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 10:37:53 by azulu             #+#    #+#              #
#    Updated: 2018/09/15 11:54:39 by azulu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = filler

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  get_data.c \
	  my_player.c \
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	
fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	
re: fclean all
