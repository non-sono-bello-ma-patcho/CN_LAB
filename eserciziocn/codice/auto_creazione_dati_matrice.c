#include"../lib/auto_creazione_dati_matrice.h"

const char* FILE_NAME_MATRIX="file_matrice";
const char* FILE_NAME_VECTOR="file_vettore"; 

int calcolo_dimensione_mat(char* numero_mat)
{
    char c0=numero_mat[strlen(numero_mat)-1];
    char c1=numero_mat[strlen(numero_mat)-2];
    #ifdef DEBUG
    printf("c0:%c c1:%c;",c0,c1);
    #endif
    int d0=c0-'0';
    int d1=c1-'0';
    L_MATRICE=10*(d1+1)+d0;/*variabile globale definita nel .h*/
return (10*(d1+1)+d0);
}

void free_routine_acdm(float **matrice,float *vettore,unsigned int *l_x)
{
    free(vettore);
    if(matrice==NULL){return;}/*il NULL l'ho impostato prima*/
    for(unsigned int i=0;i<*l_x;i++)
    {
        free(matrice[i]);
    }
    free(matrice);
return;
}


int f_auto_creazione_dati_matrice(char* numero_matricola)
{
    FILE *fp;
    int l_x,l_y;
    fp=fopen(FILE_NAME_MATRIX,"w");
	if(fp==NULL)
	{
			perror("ERROR:unable to open file");
			fclose(fp);
			return -1;
	}
    l_x=calcolo_dimensione_mat(numero_matricola);
    l_y=l_x;                                               /*matrice quadrata*/
    #if defined(DEBUG) || defined(STAMPA_OPERAZIONI)
    printf("La matrice ha dimensione %dX%d \n",l_x,l_y);
    #endif
    for(int x=0;x<l_x;x++)
    {
        for(int y=0;y<l_y;y++)
        {
            if(x==y){fprintf(fp," 2");}
            else
            {
                if(abs(x-y)==1){fprintf(fp," -1");}
                else{fprintf(fp," 0");}
            }
        }
    }
fclose(fp);
return 0;
}



int f_auto_creazione_dati_vettore(char* numero_matricola)
{
    FILE *fp;
    FILE *f_valori_matrice;
    unsigned int l_vettore,l_x,l_y;
    float *vettore_soluzioni;
    float **matrice=NULL;
    float valore_noto_temp;/*lo uso quando calcolo uno ad uno i valori noti*/
    
    
    fp=fopen(FILE_NAME_VECTOR,"w");
    f_valori_matrice=fopen(FILE_NAME_MATRIX,"r");
	if(f_valori_matrice==NULL||fp==NULL)
	{
			perror("ERROR:unable to open file");
			fclose(f_valori_matrice);fclose(fp);
			return -1;
	}
    
    /*calcolo le dimensioni delle strutture dati*/
    l_vettore=calcolo_dimensione_mat(numero_matricola);
    l_x=l_vettore;
    l_y=l_x;
    
    /*inizializzo vettore*/
    vettore_soluzioni=(float*)malloc(sizeof(float)*l_vettore);/*alloco memoria per array temoraneo soluzioni che userò per il calcolo dei valori noti*/
    if(vettore_soluzioni==NULL)
	{
	    perror("ERROR:unable to allocate enough memory");
	    free_routine_acdm(matrice,vettore_soluzioni,&l_x);
	    fclose(f_valori_matrice);fclose(fp);
	    return -1;
	}
	/*inizializzo tutto a 1 come da consegna*/
    for(unsigned i=0;i<l_vettore;i++)
    {
        vettore_soluzioni[i]=1.0;/*se uno vuole qui può modificare con altri valori...*/
    }
    
    #if defined(DEBUG) || defined(STAMPA_OPERAZIONI)
    printf("Il vettore ha dimensione %d \n",l_vettore);
    #endif
    
    /* naturalmente dato che sono sfigato nel file ho stampato su file(causa altre parti di codice)le colonne*righe e non righe*colonne quindi mi tocca creare pure una matrice... */
    matrice=init_matrix(&l_x,&l_y,1);
    if(matrice==NULL)
    {
        perror("ERROR:unable to allocate matrix memory");
	    free_routine_acdm(matrice,vettore_soluzioni,&l_x);
	    fclose(f_valori_matrice);fclose(fp);
	    return -1;
    }
    
    /*leggo i dati e inizializzo matrice*/
    fill_matrix(matrice,&l_y,&l_x,1);
    
    /*calcolo soluzioni utilizzando coeff. matrice e valori del vettore_soluzioni*/
    for(unsigned int y=0;y<l_y;y++)
    {
        valore_noto_temp=0;
        for(unsigned int x=0;x<l_x;x++)
        {
            valore_noto_temp+=matrice[x][y]*vettore_soluzioni[x];/*sommatoria coeff. per valore noto*/
        }
        fprintf(fp," %f",valore_noto_temp);
    }
    
/*libero memoria*/
free_routine_acdm(matrice,vettore_soluzioni,&l_x);
fclose(f_valori_matrice);
fclose(fp);
return 0;
}




