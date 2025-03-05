#COMPILER AND FLAGS
CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/$(MINILIBX_DIR)/lmlx -lXext -lX11

#SOURCE FILES
MAIN_SRC = src/main.c 
MAP_SRC = src/map/parser.c

#DEFINE DIRECTORIES
MINILIBX_DIR = libs/minilibx-linux
OBJ_DIR = obj

#DEFINE OBJECTS
MINILIBIX_OBJ = $(MINILIBX_DIR)/libmlx.a

OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ = $(patsubst src/map/%.c, $(OBJ_DIR)/map/%.o, $(SRC))

#PROGRAM NAME
NAME = so_long

#DEFAULT TARGET
all: $(NAME)

#LINKING EXECUTABLE
$(NAME): $(OBJ) $(MINILIBIX_OBJ)
	${CC} ${CFLAGS} $(OBJ) $(MINILIBIX_OBJ) $(MLX_FLAGS) -o $(NAME)

#BUILD LIBRARIES
$(MINILIBIX_OBJ):
	$(MAKE) -C $(MINILIBX_DIR)

#CREATING OBJECT DIRECTORIES
$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/map:
	mkdir -p $@

#COMPILING .c FILES INTO .o FILES (INSIDE OBJ DIR)
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR)/map/%.o: src/map/%.c | $(OBJ_DIR)/map
	${CC} ${CFLAGS} -c $< -o $@

#BASIC RULES
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re