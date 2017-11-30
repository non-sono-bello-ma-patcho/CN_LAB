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
    L_MATRICE=10*(d1+1)+d0;
return (10*(d1+1)+d0);
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
    l_y=l_x;
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
    fp=fopen(FILE_NAME_VECTOR,"w");
	if(fp==NULL)
	{
			perror("ERROR:unable to open file");
			fclose(fp);
			return -1;
	}
    
    printf("auto creazione dati vettore :to be implemented");
    
    
    
fclose(fp);
return 0;
}


