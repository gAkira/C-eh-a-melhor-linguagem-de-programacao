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
PARTE_2_DIR		=	$(call FixPath,./parte_2)

all:
	@echo "Modo de uso:"
	@echo "    make <comando>"
	@echo "--------------------------------------------------------------------------------"
	@echo "COMANDOS"
	@echo "Especificos:"
	@echo "    pX        -    roda a parte X"
	@echo "    plotX     -    plota os graficos de calor e erro da parte X"
	@echo "     | heatX  -    plota apenas o grafico de calor da parte X"
	@echo "     | errorX -    plota apenas o grafico de erro da parte X"
	@echo "    cleanX    -    limpa os objetos (.o) da parte X"
	@echo "    fcleanX   -    limpa os objetos (.o) e o executavel da parte X"
	@echo "    reX       -    recompila os arquivos da parte X"
	@echo ""
	@echo "    Exemplo: $$> make p2"
	@echo "        Este comando rodara a parte 2"
	@echo ""
	@echo ""
	@echo "Genericos:"
	@echo "    Usar os comandos especificos sem definir uma parte 'X' fara com que este"
	@echo "    comando se aplique para ambas partes do EP."
	@echo ""
	@echo "    Exemplo: $$> make plot"
	@echo "        Este comando executara tanto plot1 quanto plot2"
	@echo ""
	@echo ""
	@echo "Extra:"
	@echo "    nyan"	

p: p1 p2

p1:
	@echo "Rodando parte 1 do EP1..."
	@$(MAKE) -C $(PARTE_1_DIR)

p2:
	@echo "Rodando parte 2 do EP1..."
	@$(MAKE) -C $(PARTE_2_DIR)

plot: plot1 plot2

plot1: heat1 error1

heat1:
	@$(MAKE) -C $(PARTE_1_DIR) heat

error1:
	@$(MAKE) -C $(PARTE_1_DIR) error

heat2:
	@$(MAKE) -C $(PARTE_2_DIR) heat

plot2: heat2 error2

error2:
	@$(MAKE) -C $(PARTE_2_DIR) error

clean: clean1 clean2

clean1:
	@$(MAKE) -C $(PARTE_1_DIR) clean

clean2:
	@$(MAKE) -C $(PARTE_2_DIR) clean

fclean: fclean1 fclean2

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


fclean1:
	@$(MAKE) -C $(PARTE_1_DIR) fclean
	
fclean2:
	@$(MAKE) -C $(PARTE_2_DIR) fclean

re: re1 re2

re1:
	@$(MAKE) -C $(PARTE_1_DIR) re

re2:
	@$(MAKE) -C $(PARTE_2_DIR) re
