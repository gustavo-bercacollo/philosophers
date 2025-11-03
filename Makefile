# Nome do executável
NAME = philo

# Compilador
CC = cc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Arquivos fonte
SRC = src/main.c \
      src/utils.c \
      src/rotine.c \
			src/philosophers.c \
			src/free.c \
			src/validate.c \
      src/init.c

# Geração automática dos objetos (.o)
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(NAME)

# Linkagem
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compilação dos .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos objeto
clean:
	rm -f $(OBJ)

# Limpa tudo (objetos + binário)
fclean: clean
	rm -f $(NAME)

# Recompila do zero
re: fclean all

.PHONY: all clean fclean re
