#!/bin/sh

if [ $2 = 0.25 ]; then
	echo "$1 $2 $3" >> reducao/EXP_B_L25.red
elif [ $2 = 0.5 ]; then
	echo "$1 $2 $3" >> reducao/EXP_B_L50.red
elif [ $2 = 0.51 ]; then
	echo "$1 $2 $3" >> reducao/EXP_B_L51.red
else
	echo "Testando" >> reducao/TESTE.red
fi
