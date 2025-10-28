# Nome do executável
NAME = philo

# Compilador
CC = cc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Arquivos fonte
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/rotine.c \
      $(SRC_DIR)/init.c

# Geração automática dos objetos (.o)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(NAME)

# Linkagem
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compilação dos .c para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cria pasta obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpa arquivos objeto
clean:
	rm -rf $(OBJ_DIR)

# Limpa tudo (objetos + binário)
fclean: clean
	rm -f $(NAME)

# Recompila do zero
re: fclean all

# Evita conflitos com arquivos reais
.PHONY: all clean fclean re
