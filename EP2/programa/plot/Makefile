ifdef OS
	NAME	=	graph.exe
	RM	=	del /Q
	RMDIR	=	rmdir	/S/Q
	MKDIR	=	if not exist "$1" (mkdir $1)
	FixPath	=	$(subst /,\,$1)
else
	NAME	=	graph
	RM	=	rm -f
	RMDIR	= $(RM) -r
	MKDIR	=	mkdir -p $1
	FixPath =	$1
endif


CC		=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

LIB		=	m
DATA_DIR=	data

ifdef OS
	SRC_DIR	=	src_windows
	SRC		=	$(call FixPath,						\
				$(SRC_DIR)/windows_plot.c			\
				$(SRC_DIR)/get_next_line.c			\
				$(SRC_DIR)/get_next_line_utils.c	)
else
	SRC_DIR	=	src_linux
	SRC		=	$(call FixPath,						\
				$(SRC_DIR)/linux_plot.c				\
				$(SRC_DIR)/get_next_line.c			\
				$(SRC_DIR)/get_next_line_utils.c	)

endif

OBJ_DIR	=	obj
OBJ		=	$(call FixPath,						\
			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)))

all: $(NAME)
	@$(call FixPath, ./$(NAME))

$(NAME): $(OBJ)
	@$(CC) $(CC_FLAG) $^ -o $@ -l$(LIB)

$(call FixPath,$(OBJ_DIR)/%.o): $(call FixPath,$(SRC_DIR)/%.c)
	@$(call MKDIR,$(OBJ_DIR))
	@$(CC) $(CC_FLAG) -c $< -o $@ -l$(LIB)

OPT		= 15
plot: $(NAME)
	@$(call FixPath, ./$(NAME) $(OPT))

clean:
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@$(RMDIR) $(DATA_DIR)
	@$(RM) $(NAME)
	@$(RM) $(NAME).exe

re: fclean all

help: $(NAME)
	@$(call FixPath, ./$(NAME))
