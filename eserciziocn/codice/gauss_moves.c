#include"gauss_moves.h"


float trova_parametro(const float* valore1,const float* valorebase)
{
	return (-(*valore1/(*valorebase)));
}

/*torna 0 se operazione a buon fine ,   -1 in caso di errore*/
int scambia_righe(float** matrix,const unsigned int* riga1,const unsigned int* riga2,const unsigned int* l_y,const unsigned int* l_x)
{
	if(*riga1>=*l_y||*riga2>=*l_y)
	{perror("Out of bond\n");return -1;}
	float array[*l_x];
	for(unsigned int i=0;i<*l_x;i++)
	{
		array[i]=matrix[i][*riga1];/*salvo in array temporaneo*/
		matrix[i][*riga1]=matrix[i][*riga2];/*sostituisco cella prima riga*/
		matrix[i][*riga2]=array[i];
	}
	return 0;
}


/*torna 0 se operazione a buon fine, -1 altrimenti*/
int somma_riga_con_multiplo_rigabase(float** matrix,const unsigned int* riga1,const unsigned int* rigabase,const float* parametro,const unsigned int* l_y,const unsigned int* l_x)
{
	if(*riga1>=*l_y||*rigabase>=*l_y)
	{perror("Out of bond\n");return -1;}
	/*printf("L_x=========================%u\n",*l_x);*/
	for(unsigned int i=0;i<*l_x;i++)
	{
	    
		matrix[i][*riga1]+=matrix[i][*rigabase]*(*parametro);
	}
	return 0;
}


void stampa_risultato(float** matrix,const unsigned int* l_y,const unsigned int* l_x)
{
	printf("MATRICE----%uX%u-----------------------------------------------------------\n",*l_y,*l_x);
	for(unsigned int y=0;y<*l_y;y++)
	{
		for(unsigned int x=0;x<*l_x;x++)
		{
		    #ifdef DEBUG
		    printf("riga:%u   colonna:%u   %f\n",y+1,x+1,matrix[x][y]);	
		    #else
			printf("%f\t",matrix[x][y]);	
		    #endif
		}
		printf("\n");
	}
	printf("\n----------------------------------------------------------------------------\n");
	return;
}
