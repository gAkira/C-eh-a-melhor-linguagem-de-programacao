ifdef OS
	NAME	=	ep2.exe
	RM		=	del /Q /F
	RMDIR	=	rmdir	/S/Q
	MKDIR	=	if not exist "$1" (mkdir $1)
	FixPath	=	$(subst /,\,$1)
else
	NAME	=	ep2
	RM	=	rm -f
	RMDIR	= $(RM) -r
	MKDIR	=	mkdir -p $1
	FixPath =	$1
endif

CC		=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

LIB		=	m
PLOT_DIR=	plot
SAVE_DIR=	$(call FixPath,$(PLOT_DIR)/data)

SRC_DIR	=	src
SRC		=	$(call FixPath,					\
			$(SRC_DIR)/main.c				\
			$(SRC_DIR)/fonte.c				\
            $(SRC_DIR)/fronteira.c          \
			$(SRC_DIR)/init_value.c			\
			$(SRC_DIR)/user_input.c			\
			$(SRC_DIR)/process_info.c		\
			$(SRC_DIR)/crank_nicolson.c		\
			$(SRC_DIR)/set_uT.c				\
			$(SRC_DIR)/solve_ak.c			\
			$(SRC_DIR)/calc_uTk.c			\
			$(SRC_DIR)/calc_E2.c			\
			$(SRC_DIR)/print_uk_file.c		\
			$(SRC_DIR)/free_mem.c			\
			$(SRC_DIR)/get_next_line.c		\
			$(SRC_DIR)/get_next_line_utils.c)

OBJ_DIR	=	obj
OBJ		=	$(call FixPath,					\
			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)))

all:	$(NAME)
	@echo "Voila:"
	@$(call FixPath,./$<)

$(NAME):	$(OBJ)
	@echo "Gerando executavel..."
	@$(call MKDIR,$(SAVE_DIR))
	@$(CC) $(CC_FLAG) $^ -o $@ -lm

$(call FixPath,$(OBJ_DIR)/%.o):	$(call FixPath,$(SRC_DIR)/%.c)
	@echo "Criando objetos (.o)"
	@$(call MKDIR,$(OBJ_DIR))
	@$(CC) $(CC_FLAG) -c $< -o $@ -l$(LIB)


OPT		=	15
plot:
	@$(MAKE) -C $(PLOT_DIR) $@ OPT=$(OPT)

graph:
	@$(MAKE) -C $(PLOT_DIR) help

clean:
	@echo "Limpando..."
	@$(RMDIR) $(OBJ_DIR)
	@$(MAKE) -C $(PLOT_DIR) $@

fclean:	clean
	@echo "Novinho em folha!"
	@$(RM) $(NAME)
	@$(RM) $(NAME).exe
	@$(MAKE) -C $(PLOT_DIR) $@

re: fclean all

help:
	@echo "Modo de uso:"
	@echo "    make <comando>"
	@echo "--------------------------------------------------------------------------------"
	@echo "COMANDOS"
	@echo "Especificos:"
	@echo "              -    compila e executa o EP"
	@echo "    clean     -    limpa os objetos (.o)"
	@echo "    fclean    -    limpa os objetos (.o) e o executavel"
	@echo "    re        -    recompila os arquivos e executa"
	@echo "    help      -    exibe painel de comandos"
	@echo "    graph     -    exibe lista de comandos para plotagem de graficos"
	@echo "    plot [OPT]-    plota o grafico de acordo com o valor adotado por OPT"
	@echo "                   (para saber mais sobre os valores de OPT: $$> make graph)"
	@echo ""
	@echo "    Exemplo: $$> make"
	@echo "        [Este comando compilara e executara o programa do EP2]"
	@echo ""
	@echo "    Exemplo: $$> make plot OPT=15"
	@echo "        [Este comando plotara o grafico da distribuicao final fornecida"
	@echo "            e as componentes de cada fonte de calor]"
	@echo "        OBS: OPT assume o valor de 15 por padrao"
	@echo ""
	@echo ""
	@echo "Extra:"
	@echo "    nyan"

nyan:
	@echo "    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "    ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░"
	@echo "    ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░"
	@echo "    ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░"
	@echo "    ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░"
	@echo "    ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░"
	@echo "    ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░"
	@echo "    ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░"
	@echo "    ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░"
	@echo "    ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░"
	@echo "    ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░"
	@echo "    ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░"
	@echo "    ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░"
	@echo "    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"


