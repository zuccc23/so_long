CC = cc

CFLAGS = -Wall -Wextra -Werror

MINILIBX_DIR = minilibx-linux

OBJ_DIR = obj

MINILIBIX_OBJ = $(MINILIBX_DIR)/libmlx.a

SRC = src/main.c 

OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = so_long

$(NAME): $(OBJ) $(MINILIBIX_OBJ)
	${CC} ${CFLAGS} $(OBJ) $(MINILIBIX_OBJ) -o $(NAME)

minilibx-linux/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all