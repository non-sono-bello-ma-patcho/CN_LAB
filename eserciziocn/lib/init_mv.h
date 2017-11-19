#ifndef INIT_MV_H
#define INIT_MV_H
#include<sys/types.h>
#include<sys/stat.h> 
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include"auto_creazione_dati_matrice.h"
float** init_matrix(unsigned int* dimensione_x,unsigned int* dimensione_y,const int dimensione_nota);
float* init_vector(unsigned int* dimensione_y,const int dimensione_nota);
int merge_matrix_vector(float** matrix,float* vettore,const unsigned int*  l_y,unsigned int* l_x,const unsigned int*  l_v);

#endif
