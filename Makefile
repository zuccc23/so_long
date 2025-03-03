CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

SRC = src/main.c 

OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = so_long

$(NAME): $(OBJ)
	${CC} ${CFLAGS} $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -rf $(NAME)

re: fclean all