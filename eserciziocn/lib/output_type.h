#ifndef _OUTPUT_TYPE_H
#define _OUTPUT_TYPE_H
#include<stdio.h>
#include<stdlib.h>
#include"gauss_moves.h"
//#define DEBUG
#define STAMPA_OPERAZIONI

#ifdef DEBUG
void debug(float** matrix,const unsigned int* altezza,const unsigned int* larghezza);
void debug2(float* vettore,const unsigned int *l, float* val_pert);
#endif/*ifdef debug*/

#endif
