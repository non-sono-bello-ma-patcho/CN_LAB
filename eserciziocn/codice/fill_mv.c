#include"../lib/fill_mv.h"

int fill_vector(float* vettore,const unsigned int* lunghezza,const int dimensione_nota)
{
	int scelta=0;
	char* file_name=(char*)malloc(sizeof(char)*256);
	FILE *fp;
	if(!dimensione_nota)
	{
	    printf("Vuoi inserire via terminale(0) o via file (1)?\n");
	    fflush(stdin);
	    scanf("%d",&scelta);
	    
	}
	else{scelta=1;}
	if(scelta)
	{	
			if(!dimensione_nota)
	        {
			    printf("Inserisci path:");
			    fflush(stdin);
			    if(scanf("%s",file_name)==EOF){perror("ERRORE funzione scanf();");return 1;}
		    }
		    else
		    {
		        file_name="file_vettore\0";
		    }	
			fp=fopen(file_name,"r");
			if(!fp)
			{
				perror("ERROR:unable to open file");
				return 1;
			}
			
			for(unsigned int i=0;i<*lunghezza;i++)
			{
				fscanf(fp,"%f",&vettore[i]);	
			}
			fclose(fp);
	}	
	else
	{
		for(unsigned int i=0;i<*lunghezza;i++)
		{
			printf("Inserisci	valore riga %d\n",i+1);
			scanf("%f",&vettore[i]);	
		}
	}
	
return 0;
}

int fill_matrix(float** matrix,const unsigned int* l_y,const unsigned int* l_x,const int dimensione_nota)
{
	int scelta=0;
	char* file_name=(char*)malloc(sizeof(char)*256);
	FILE *fp;
	if(!dimensione_nota)
	{
	    printf("Vuoi inserire via terminale(0) o via file (1)?\n");
	    fflush(stdin);
	    scanf("%d",&scelta);
	}
	else{scelta=1;}
	if(scelta)
	{
	    if(!dimensione_nota)
	    {
			printf("Inserisci path:");
			fflush(stdin);
			if(scanf("%s",file_name)==EOF){perror("ERRORE funzione scanf();");return 1;}
		}
		else
		{
		    file_name="file_matrice\0";
		}	
			
			fp=fopen(file_name,"r");
			if(!fp)
			{
				perror("ERROR:unable to open file");
				return 1;
			}
			
			for(unsigned int x=0;x<*l_x;x++)
			{
				for(unsigned int y=0;y<*l_y;y++)
				{
					fscanf(fp,"%f",&matrix[x][y]);	
				}
			}
		    fclose(fp);
	}	
	else
	{
		for(unsigned int x=0;x<*l_x;x++)
		{
			for(unsigned int y=0;y<*l_y;y++)
			{
				printf("Inserisci	valore riga;%u \t colonna:%u\n",y+1,x+1);
				scanf("%f",&matrix[x][y]);	
			}
		}
	}
return 0;
}







/*
char *inputString(FILE* fp, size_t size)
{
    char *str;
    int ch;
    size_t len = 0;
    if(fflush(stdin)==EOF){perror("ERRORE fflsuh");}
    str = realloc(NULL, sizeof(char)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n')
    {
        str[len++]=ch;
        if(len==size)
        {
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    return realloc(str, sizeof(char)*len);
}
*/












