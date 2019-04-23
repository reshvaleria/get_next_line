# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 19:45:03 by wjeyne-d          #+#    #+#              #
#    Updated: 2018/12/08 20:12:34 by wjeyne-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
