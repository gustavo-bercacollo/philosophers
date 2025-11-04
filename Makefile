NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude

SRC = src/main.c \
      src/utils.c \
      src/rotine.c \
      src/philosophers.c \
      src/free.c \
      src/validate.c \
      src/init.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
