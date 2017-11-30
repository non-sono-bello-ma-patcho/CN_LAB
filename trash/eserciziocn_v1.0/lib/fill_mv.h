#ifndef FILL_MV_H
#define FILL_MV_H
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int fill_vector(float* vettore,const unsigned int* lunghezza,const int dimensione_nota);
int fill_matrix(float** matrix,const unsigned int* l_y,const unsigned int* l_x,const int dimensione_nota);
#endif
