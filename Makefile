ifdef OS
	RM	=	del /Q
	RMDIR	=	rmdir	/S/Q
	MKDIR	=	if not exist "$1" (mkdir $1)
	FixPath	=	$(subst /,\,$1)
else
	RM	=	rm -f
	RMDIR	= $(RM) -r
	MKDIR	=	mkdir -p $1
	FixPath =	$1
endif


PARTE_1_DIR		=	$(call FixPath,./parte_1)

all: p1

p1:
	@echo "Rodando parte 1 do EP1..."
	@$(MAKE) -C $(PARTE_1_DIR)

clean:
	@$(MAKE) -C $(PARTE_1_DIR) clean

fclean:
	@$(MAKE) -C $(PARTE_1_DIR) fclean

re: fclean all
