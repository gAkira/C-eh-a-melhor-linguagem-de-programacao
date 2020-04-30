NAME	=	ep1

CC		=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

LIB		=	m
INCLUDE	=	inc

SRC_DIR	=	src
SRC		=	$(SRC_DIR)/main.c				\
			$(SRC_DIR)/fonte.c				\
			$(SRC_DIR)/user_input.c			\
			$(SRC_DIR)/process_info.c		\
			$(SRC_DIR)/create_matrix.c		\
			$(SRC_DIR)/init_value.c			\
			$(SRC_DIR)/apply_init_value.c

OBJ_DIR	=	obj
OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all:	$(NAME)
	@echo "Voila:"
	@./$<

$(NAME):	$(OBJ)
	@echo "Gerando executavel..."
	@$(CC) $(CC_FLAG) $^ -o $@ -lm

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@echo "Criando objetos (.o)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAG) -I$(INCLUDE) -c $< -o $@ -l$(LIB)

clean:
	@echo "Limpando..."
	@$(RM) -r $(OBJ_DIR)

fclean:	clean
	@echo "Novinho em folha!"
	@$(RM) $(NAME)

re: fclean all
