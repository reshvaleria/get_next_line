NAME = test
HEADER = libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o test $(SRC) -I $(HEADER)

clean:
	rm -f $(NAME)

re: clean all
