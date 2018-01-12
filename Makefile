# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avishnev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 15:13:27 by avishnev          #+#    #+#              #
#    Updated: 2017/12/06 15:13:30 by avishnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/*.c
INC = ./includes
FLAGS = -Wall -Wextra -Werror -o $(NAME)
LIB = ./libft/

all: $(NAME)
$(NAME):
	@make -C $(LIB) --silent
	@gcc $(FLAGS) $(SRC) $(LIB)libft.a -I $(INC)
	@echo "<<<<<<<<<<<<<<<<--FILLIT_COMPILED-->>>>>>>>>>>>>>>>" 
clean:
	@make -C $(LIB) clean --silent
	@echo "<<<<<<<<<<<<<<<<--Succes-->>>>>>>>>>>>>>>>" 
fclean: clean
	@make -C $(LIB) fclean --silent
	@rm -f $(NAME)
re: fclean all
