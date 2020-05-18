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

#ifndef P2_H
# define P2_H

// Define a janela de tempo do dominio: [0.0 , T]
//-----------------------------------------------------------------------------
# define T 1.0

// Define se deseja calcular o erro ou nao
//-----------------------------------------------------------------------------
# define CALC_ERROR

// Define qual metodo implicito aplicar
// Obs: Para apenas validar a decomposicao LDLt, comente ambos metodos
//-----------------------------------------------------------------------------
//# define EULER
# define CRANK_NICOLSON

// Define qual exercicio da primeira parte deseja computar
//-----------------------------------------------------------------------------
//# define EX_A_FAKE
//# define EX_A
# define EX_B
//# define EX_C_1
//# define EX_C_2

// Define o ponto da fonte puntual aplicada (valido em EX_C_x)
//-----------------------------------------------------------------------------
# define P 0.25

#endif
