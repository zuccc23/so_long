#COMPILER AND FLAGS
CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/$(MINILIBX_DIR)/lmlx -lXext -lX11

#SOURCE FILES
MAIN_SRC = src/main.c src/cleanup.c
MAP_SRC = src/map/parser.c 

#DIRECTORIES
OBJ_DIR = obj

MINILIBX_DIR = libs/minilibx-linux
GNL_DIR = libs/gnl
LIBFT_DIR = libs/libft

#DEFINE OBJECTS
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(MAIN_SRC))
OBJ += $(patsubst src/map/%.c, $(OBJ_DIR)/map/%.o, $(MAP_SRC))

MINILIBIX_OBJ = $(MINILIBX_DIR)/libmlx.a
GNL_OBJ = $(GNL_DIR)/get_next_line.a
LIBFT_OBJ = $(LIBFT_DIR)/libft.a

#PROGRAM NAME
NAME = so_long

#DEFAULT TARGET
all: $(NAME)

#LINKING EXECUTABLE !!!FLAGS
$(NAME): $(OBJ) $(MINILIBIX_OBJ) $(GNL_OBJ) $(LIBFT_OBJ)
	${CC}  $(OBJ) $(GNL_OBJ) $(LIBFT_OBJ) $(MINILIBIX_OBJ) $(MLX_FLAGS) -o $(NAME)

#BUILD LIBRARIES
$(MINILIBIX_OBJ):
	$(MAKE) -C $(MINILIBX_DIR)
$(GNL_OBJ):
	$(MAKE) -C $(GNL_DIR)
$(LIBFT_OBJ):
	$(MAKE) -C $(LIBFT_DIR)

#CREATING OBJECT DIRECTORIES
$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/map:
	mkdir -p $@

#COMPILING .c FILES INTO .o FILES (INSIDE OBJ DIR) !!!FLAGS
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	${CC}  -c $< -o $@

$(OBJ_DIR)/map/%.o: src/map/%.c | $(OBJ_DIR)/map
	${CC}  -c $< -o $@

#BASIC RULES
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re