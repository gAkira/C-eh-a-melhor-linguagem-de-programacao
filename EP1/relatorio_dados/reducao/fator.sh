#!/bin/sh

if [ $1 = a ]; then
	echo "$2 $2 $3" >> reducao/CN_A.red
elif [ $1 = b ]; then
	echo "$2 $2 $3" >> reducao/CN_B.red
else
	echo "$2 $2 $3" >> reducao/TESTE.red
fi
