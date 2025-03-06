#COMPILER AND FLAGS
CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

#SOURCE FILES
SRC = ./get_next_line.c ./get_next_line_utils.c

#DEFINE DIRECTORIES
OBJ_DIR = obj

#DEFINE OBJECTS
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

#PROGRAM NAME
NAME = get_next_line.a

#DEFAULT TARGET
all: $(NAME)

#CREATE STATIC LIBRARY
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

#CREATING OBJECT DIRECTORIES
$(OBJ_DIR):
	mkdir -p $@

#COMPILING .c FILES INTO .o FILES (INSIDE OBJ DIR)
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

#BASIC RULES
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re