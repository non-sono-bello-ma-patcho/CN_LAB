#include"init_mv.h"


float** init_matrix(unsigned int* dimensione_x,unsigned int* dimensione_y,const int dimensione_nota)
{	
	float** matrice;
	if(!(dimensione_nota))
	{
	    printf("Acquisizione dati per inizializzazione matrice:\n");
	    printf("Inserisci numero righe matrice: ");
	    fflush(stdin);
	    scanf("%u",&(*dimensione_y));
	    printf("Inserisci il numero incognite massimo: ");
	    fflush(stdin);
	    scanf("%u",&(*dimensione_x));
	}
	else
	{
	    *dimensione_y=L_MATRICE;
	    *dimensione_x=L_MATRICE;
	}
	#ifdef DEBUG
	printf("dimensioni matrice x:%u   y:%u\n",*dimensione_x,*dimensione_y);
	#endif
	
	matrice=(float**)malloc(sizeof(float*)*((*dimensione_x+1)));/*il +1 è in previaione del merge con il vettore*/
	if(matrice==NULL)
	{perror("ERROR:unable to allocate enough memory");return NULL;}
	
	for(unsigned int i=0;i<*dimensione_x+1;i++)/*il +1 per lo stesso motivo di prima*/
	{
		matrice[i]=(float*)malloc(sizeof(float)*(*dimensione_y));
		if(matrice[i]==NULL)
		{perror("ERROR:unable to allocate enough memory");return NULL;}
	}
	
	
	return matrice;
}

float* init_vector(unsigned int* dimensione_y,const int dimensione_nota)
{
	float* vettore;
	if(!(dimensione_nota))
	{
	    printf("Inserisci numero componenti del vettore: ");
	    fflush(stdin);
	    scanf("%u",&(*dimensione_y));
    }
    else
    {
        *dimensione_y=L_MATRICE;
    }
	vettore=(float*)malloc(sizeof(float)*(*dimensione_y));
	if(vettore==NULL)
	{perror("ERROR:unable to allocate enough memory");return NULL;}
	return vettore;
}


int merge_matrix_vector(float** matrix,float* vettore,const unsigned int*  l_y,unsigned int* l_x,const unsigned int* l_v)
{
	if(*l_v!=*l_y){return -1;}
	for(unsigned int i=0;i<*l_y;i++)
	{
		matrix[*l_x][i]=vettore[i];
	}
	(*l_x)++;
	return 0;
}






