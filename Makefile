NAME = test
HEADER = libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c main.c
LIBA = libft/libft.a

all:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA)

clean:
	rm -f $(NAME)

re: clean all
