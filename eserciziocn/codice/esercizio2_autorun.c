#include<stdlib.h>
#include<stdio.h>
#include"../lib/init_mv.h"
#include"../lib/fill_mv.h"
#include"../lib/gauss_moves.h"
#include"../lib/perturbatore_vettore.h"
#include"../lib/output_type.h"
#include"../lib/auto_creazione_dati_matrice.h"
#define SISTEMA_IMPOSSIBILE 0
#define SISTEMA_FINITE_SOL 1
#define SISTEMA_INFINITE_SOL 2

int calcolo_tipo_sistema(float** matrice,const unsigned int* l_y,const unsigned int* l_x);
void free_routine(float **matrice,float *vettore,unsigned int *l_x);
int soluzioni_sistema(float** matrix,float* vettore,const unsigned int* l_y,const unsigned int* l_x);
void stampa_vettore(float* vettore,const unsigned int* const l_vector);

int main(int argc,char **argv)
{
#ifndef DEBUG
#ifdef STAMPA_OPERAZIONI
unsigned int number_op=1;
#endif/*stampa operazioni*/
unsigned int c_x=0,c_y=0,riga_base,i;
float parametro;
#endif /*debug*/

unsigned int l_x,l_y,l_vector;
float** matrice;
float* vettore;


if(argc>1)/*crea i file con i dati matrice e vettore calcolati in base al numero di matricola*/
{
    printf("CALCOLO I DATI PER IL NUMERO DI MATRICOLA %s...\n",argv[1]);
    if(f_auto_creazione_dati_matrice(&(*argv[1]))<0){perror("ERRORE:impossibile creare dati matrice ");exit(EXIT_FAILURE);}
    if(f_auto_creazione_dati_vettore(&(*argv[1]))<0){perror("ERRORE:impossibile creare dati vettore ");exit(EXIT_FAILURE);}
    /*allocca la memoria*/
    do{matrice=init_matrix(&l_x,&l_y,1);}while(!matrice);
    do{vettore=init_vector(&l_vector,1);}while(!vettore);
    /*inizializza i valori*/
    while(fill_vector(vettore,&l_vector,1));
    /*inizializza i valori*/
    while(fill_matrix(matrice,&l_y,&l_x,1));
}
else/*inserimento libero*/
{
    /*allocca la memoria*/
    do{matrice=init_matrix(&l_x,&l_y,0);}while(!matrice);
    do{vettore=init_vector(&l_vector,0);}while(!vettore);
    /*inizializza i valori*/
    while(fill_vector(vettore,&l_vector,0));
    /*inizializza i valori*/
    while(fill_matrix(matrice,&l_y,&l_x,0));
}
    
if(perturba_vettore(vettore,&l_vector)<0){perror("\n\nImpossibile perturbare il vettore:");}
#ifdef DEBUG
stampa_vettore(vettore,&l_vector);
#endif

#if defined(DEBUG) || defined(STAMPA_OPERAZIONI)
stampa_risultato(matrice,&l_y,&l_x);
#endif


/*faccio il merge tra matrice e vettore*/
if(merge_matrix_vector(matrice,vettore,&l_y,&l_x,&l_vector)<0)
{perror("\n\n Errore inserimento... lunghezza vettore e altezza matrice diverse!\n");return 0;}
#ifdef DEBUG
debug(matrice,&l_y,&l_x);	    
#else
do
{
/*passo1*/
    if(matrice[c_x][c_y]==0)
    {
        #ifdef STAMPA_OPERAZIONI
        printf("%u)riga con elemento pivot nullo->cerco una riga con cui fare swap\n",number_op++);
        #endif
	    for(i=c_y+1;i<l_y;i++)
	    {
		    if(matrice[c_x][i]!=0)
		    {
		        #ifdef STAMPA_OPERAZIONI
                printf("%u)trovata!(riga:%u)\n",number_op++,i+1);
                printf("%u)scambio riga:%u  con riga:%u\n",number_op++,c_y+1,i+1);
                #endif
		    	if(scambia_righe(matrice,&c_y,&i,&l_y,&l_x)<0)
		    	{
		    		perror("ERRORE1");
		    		exit(EXIT_FAILURE);	
		    	}
		    	break;/*esce dal ciclo*/	
		    }
	    }   
	    if(i==l_y)/*non ha trovato righe quindi salta al passo 3*/
	    {
	        #ifdef STAMPA_OPERAZIONI
            printf("%u)nessuna riga trovata!\n",number_op++);
            #endif
	        goto punto3;
	    }
    }
/*passo2*/
  
    for(riga_base=c_y,c_y+=1;c_y<l_y;c_y++)
    {
	    if(matrice[c_x][c_y]!=0)/*devo azzerare*/
	    {
	        parametro=trova_parametro(&matrice[c_x][c_y],&matrice[c_x][riga_base]);
	    	if(somma_riga_con_multiplo_rigabase(matrice,&c_y,&riga_base,&parametro,&l_y,&l_x)<0)
	    	{perror("ERRORE2");exit(EXIT_FAILURE);}	
	    	#ifdef STAMPA_OPERAZIONI
            printf("%u)azzero il valore alla riga:%u colonna %u con la rigabase:%u e il parametro:%f\n",number_op++,c_y+1,c_x+1,riga_base,parametro);
            #endif
	    }
    }   

/*passo3*/
    punto3:
    c_y=riga_base+1;
    c_x++; 
}while(c_y<l_y&&c_x<l_x);/*ho ottenuto matrice triangolare*/

switch(soluzioni_sistema(matrice,vettore,&l_y,&l_x))
{
    case SISTEMA_FINITE_SOL:
        printf("sistema finito soluzioni:\n");
        for(unsigned int i=0;i<l_y;i++)
        {printf("x%u=%f\n",i+1,vettore[i]);}
        break;
    case SISTEMA_INFINITE_SOL:
        printf("sistema con infinite soluzioni:\n");
        printf("to be implemented\n");
        break;
    case SISTEMA_IMPOSSIBILE:
        printf("sistema impossibile!\n");
        break;
    default:
        perror("ERRORE3");
        break;
}
stampa_risultato(matrice,&l_y,&l_x);
#endif
free_routine(matrice,vettore,&l_x);
return 0;
}


/*riutilizzo il vettore per salvare le soluzioni*/

int soluzioni_sistema(float** matrice,float* vettore,const unsigned int* l_y,const unsigned int* l_x/*la dimensione del vettore==l_y)*/)
{
   int temp;
   int y,x;
   switch(calcolo_tipo_sistema(matrice,l_y,l_x))
   {
        case SISTEMA_IMPOSSIBILE:
                return SISTEMA_IMPOSSIBILE;
                break;
        case SISTEMA_FINITE_SOL:
                for(y=*l_y-1;y>=0;y--)
                {
                    temp=0;
                    for(x=*l_x-2;x>y;x--)/*moltiplica coeff per valori incognite*/
                    {
                        temp+=matrice[x][y]*vettore[x];
                    }
                    /*a questo punto ho l'incognita da trovare con il valore noto (è semnpre nel punto x==y*/
                    vettore[y]=(matrice[*l_x-1][y]-temp)/matrice[x][y];//x==y sulla diagonale*/
                }
                return SISTEMA_FINITE_SOL;
                break;
        case SISTEMA_INFINITE_SOL:
            /*to be implemented*/
                return SISTEMA_INFINITE_SOL;
                break;
   }
   return -1;/*errore*/
}



int calcolo_tipo_sistema(float** matrice,const unsigned int* l_y,const unsigned int* l_x)/*utilizzo rouche-capelli*/
{
    unsigned int n_pivot_completa=0,n_pivot_incompleta=0;
    
    /*NOTA---> il codice è migliorabile mergiando i due cicli e aggioungendo condizioni if interne*/
    /*matrice incompleta*/
    for(unsigned int y=0;y<*l_y;y++)/*trovo il numero di pivot*/
    {
        for(unsigned int x=y;x<*l_x-1;x++)
        {
            if(matrice[x][y]!=.0){n_pivot_completa++;break;}
        }    
    }
    /*matrice completa*/
    for(unsigned int y=0;y<*l_y;y++)/*trovo il numero di pivot*/
    {
        for(unsigned int x=y;x<=*l_x-1;x++)
        {
            if(matrice[x][y]!=.0){n_pivot_incompleta++;break;}
        }    
    }
    if(n_pivot_completa>n_pivot_incompleta){return SISTEMA_IMPOSSIBILE;}/*impossibile e non ammette soluzioni*/
    else
    {
        if(n_pivot_completa==*l_x-1){return SISTEMA_FINITE_SOL;}/*una e unica soluzioni*/
        if(n_pivot_completa<*l_x-1){return SISTEMA_INFINITE_SOL;}/*una e unica soluzioni*/
    }
    return -1;/*errore (non dovrebbe mai verificarsi però boh non si sà mai :P*/
}


void free_routine(float **matrice,float *vettore,unsigned int *l_x)
{
    free(vettore);
    for(unsigned int i=0;i<*l_x;i++)
    {
        free(matrice[i]);
    }
    free(matrice);
return;
}

void stampa_vettore(float* vettore,const unsigned int* const l_vector)
{
	printf("\nvettore dimensione:%u----------------------\n",*l_vector);
	for(unsigned int i=0;i<*l_vector;i++)
	{
    		printf("%f  ",vettore[i]);
	}
	printf("\n-------------------------------------------\n");
	return;
}
















