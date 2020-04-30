PARTE_1_DIR		=	./parte_1

all: 1

1:
	@echo "Rodando parte 1 do EP1..."
	@make -C $(PARTE_1_DIR)

clean:
	@make -C $(PARTE_1_DIR) clean

fclean:
	@make -C $(PARTE_1_DIR) fclean

re: fclean all
