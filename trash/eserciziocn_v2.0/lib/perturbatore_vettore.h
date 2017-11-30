#ifndef PERTURBATORE_VETTORE_H
#define PERTURBATORE_VETTORE_H
#include<stdio.h>
#include<stdlib.h>
#include"output_type.h"

#include<unistd.h>



#define SUCCESS 0
#define FAIL -1
/*torna -1(FAIL) se fallisce ,  0(success) altrimenti*/
/*raccoglie i valori di perturbazione dal file "dati_perturbazione" e li applica sul vettore*/
/*il numero dei dati nel file può essere minore del numero di termini noti del vettore,il programma 
riapplicherà ciclicamnte i valori*/
int perturba_vettore(float* vettore,const unsigned int * const l);

#endif
