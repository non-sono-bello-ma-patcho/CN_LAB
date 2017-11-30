#ifndef GAUSS_MOVES_H
#define GAUSS_MOVES_H
#include<stdio.h>
float trova_parametro(const float* valore1,const float* valorebase);
int scambia_righe(float** matrix,const unsigned int* riga1,const unsigned int* riga2,const unsigned int* l_y,const unsigned int* l_x);
int somma_riga_con_multiplo_rigabase(float** matrix,const unsigned int* riga1,const unsigned int* rigabase,const float* parametro,const unsigned int* l_y,const unsigned int* l_x);
void stampa_risultato(float **matrix,const unsigned int* l_y,const unsigned int* l_x);
#endif
