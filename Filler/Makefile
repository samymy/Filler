#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 12:56:23 by vdubinki          #+#    #+#              #
#    Updated: 2017/10/02 12:56:24 by vdubinki         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vdubinki.filler

LIB = ft

LIBDIR = libft

SRC = main.c map.c array.c process.c

OBJ = $(SRC:.c=.o)

INC = *.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): $(INC)

.c.o:
	@gcc $(FLAGS) -c $<

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) -o $@ -L$(LIBDIR) -l$(LIB) $^

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
