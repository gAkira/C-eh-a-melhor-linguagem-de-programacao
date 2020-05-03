ifdef OS
	NAME	=	plot.exe
	RM	=	del /Q
	RMDIR	=	rmdir	/S/Q
	MKDIR	=	if not exist "$1" (mkdir $1)
	FixPath	=	$(subst /,\,$1)
else
	NAME	=	plot
	RM	=	rm -f
	RMDIR	= $(RM) -r
	MKDIR	=	mkdir -p $1
	FixPath =	$1
endif


CC		=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

LIB		=	m
DATA_DIR=	data

SRC_DIR	=	src
ifdef OS
	SRC		=	$(call FixPath,$(SRC_DIR)/windows_plot.c)
else
	SRC		=	$(call FixPath,$(SRC_DIR)/linux_plot.c)
endif

OBJ_DIR	=	obj
OBJ		=	$(call FixPath,						\
			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CC_FLAG) $^ -o $@ -l$(LIB)

$(call FixPath,$(OBJ_DIR)/%.o): $(call FixPath,$(SRC_DIR)/%.c)
	@$(call MKDIR,$(OBJ_DIR))
	@$(CC) $(CC_FLAG) -c $< -o $@ -l$(LIB)

heat: all
	@$(call FixPath,./$(NAME) 0)

error: all
	@$(call FixPath,./$(NAME) 1)

clean:
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@$(RMDIR) $(DATA_DIR)
	@$(RM) $(NAME)

re: fclean all
