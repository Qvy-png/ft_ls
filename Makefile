# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 12:48:07 by rdel-agu          #+#    #+#              #
#    Updated: 2025/09/20 12:48:43 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm

OBJ = $(SRC:.c=.o)

SRC =	srcs/main.c \
		srcs/str_utils.c
		
INCL =	includes/ft_ls.h

all: $(NAME)

bonus: $(NAME)_bonus

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@
		
$(NAME): $(OBJ)
	@echo " \033[0;31mCompiling $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo " \033[0;32mSuccess\033[0m"

clean:
	@$(RM) -f $(OBJ)
	@echo " \033[0;32mCleaning done!\033[0m"
	
fclean: clean
	@$(RM) -f $(NAME) 
	@$(RM) -f $(NAME)_bonus

re: fclean all

	
.PHONY: clean fclean
