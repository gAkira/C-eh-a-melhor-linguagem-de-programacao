NAME	=	plot

CC		=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

LIB		=	m
INCLUDE	=	../inc
DATA_DIR=	data

SRC_DIR	=	src
SRC		=	$(SRC_DIR)/main.c

OBJ_DIR	=	obj
OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CC_FLAG) -I$(INCLUDE) $^ -o $@ -l$(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAG) -I$(INCLUDE) -c $< -o $@ -l$(LIB)

heat: all
	@./$(NAME) 0

error: all
	@./$(NAME) 1

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(DATA_DIR)
	@$(RM) $(NAME)

re: fclean all
