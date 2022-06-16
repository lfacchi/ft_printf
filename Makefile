# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 14:53:20 by lucdos-s          #+#    #+#              #
#    Updated: 2022/06/16 15:20:40 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

FILES = ft_return_str.c ft_printf.c ft_print_b16.c ft_print_b10.c

FILES_OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	@ar -rc $(NAME) $^

cmp:all
	@./a.out
	@$(CC)  $(FLAGS) $(FILES) libftprintf.a 

$(FILES_OBJ): $(FILES)
	@$(CC) -g3 $(FLAGS) -c $^

clean:
	@rm -rf $(FILES_OBJ) 

fclean: clean
	@rm $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus

	
	
	




