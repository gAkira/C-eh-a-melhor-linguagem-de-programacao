/******************************************************************************\
**        EP1 - MAP3121        .-------.     ,-----.      .---.    .-./`)     **
** --------------------------  \  _(`)_ \  .'  .-,  '.    | ,_|    \ .-.')    **
** Authors:                    | (_ o._)| / ,-.|  \ _ \ ,-./  )    / `-' \    **
** Guilherme Akira A. Santos   |  (_,_) /;  \  '_ /  | :\  '_ '`)   `-'`"`    **
** Leticia Mendonca Carraro    |   '-.-' |  _`,/ \ _/  | > (_)  )   .---.     **
**                             |   |     : (  '\_/ \   ;(  .  .-'   |   |     **
** NUSPs:                      |   |      \ `"/  \  ) /  `-'`-'|___ |   |     **
** 11027484                    /   )       '. \_/``".'    |        \|   |     **
** 10374480                    `---'         '-----'      `--------`'---'     **  
\******************************************************************************/

#ifndef P1_H
# define P1_H

// Define a janela de tempo do dominio: [0.0 , T]
//-----------------------------------------------------------------------------
# define T 1.0

// Define se deseja calcular o erro ou nao
//-----------------------------------------------------------------------------
# define CALC_ERROR

// Define qual exercicio da primeira parte deseja computar
//-----------------------------------------------------------------------------
//# define EX_A_FAKE
# define EX_A
//# define EX_B
//# define EX_C_1
//# define EX_C_2

// Define o ponto da fonte puntual aplicada (valido em EX_C_x)
//-----------------------------------------------------------------------------
# define P 0.25


// Define o nome do arquivo do grafico de calor e de erro, respectivamente
// Obs: Salvo em ./parte_1/plot/data/
//-----------------------------------------------------------------------------
# define HEAT_F "bololo.haha"
# define ERROR_F "erroooo.ou"

#endif
