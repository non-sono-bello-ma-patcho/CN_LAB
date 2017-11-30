#include"../lib/perturbatore_vettore.h"

float norma_infinita(float * const vettore,const unsigned int * const l);

int perturba_vettore(float* vettore,const unsigned int * const l)
{
	FILE *fp;
	int scelta=0;/*default*/
	unsigned int i=0,n_val;
	float *val_pert=(float*)malloc(sizeof(float)*(*l));
	float v_norma_infinita;
	if(!val_pert){perror("ERRORE:unable to allocate enouh memory");return FAIL;}
	
	{
	    fflush(stdin);
	    printf("\nVuoi perturbare il vettore b con i dati del file <dati_perturbazione>?(1/0)\n");
	    scanf("%d",&scelta);
	    if(!scelta){return SUCCESS;}
	}
	
	fp=fopen("bin/dati_perturbazione","r");
	
	#ifdef DEBUG
	char * current_directory=(char*)malloc(sizeof(char)*250);
        if(!current_directory){perror("ERRORE:unable to allocate enough memory ");}
        current_directory=getcwd(current_directory,250);
	
	printf("Directory:%s;\n",current_directory);
	#endif
	if(!fp){perror("ERRORE:unable to find such file or directory");free(val_pert);return FAIL;}
	/*leggo i dati dal file*/
	for(int n_b_letti=1,i=0;i<*l&&n_b_letti>0;i++)
	{
	    n_b_letti=fscanf(fp,"%f",&val_pert[i]);
		if(n_b_letti==EOF)
		{
			perror("ERRORE lettura file perturbazione");
			
			/*free(val_pert);
			fclose(fp);
			return FAIL;*/
		}
		
	}
	if(++i<*l)
	{
		/*se il file vuoto undefined behaviour*/
		n_val=i;
		for(unsigned int j=0;i<*l;i++)
		{
			val_pert[i]=val_pert[j];
			if(++j>=n_val){j=0;}
		}
	}
	#ifdef DEBUG
	debug2(vettore,l,val_pert);
	#endif
/*a questo punto ho completato il vettore perturbazione ciclando se i dati erano in numero minore*/
	
    v_norma_infinita=norma_infinita(vettore,l);
    for(unsigned int i=0;i<*l;i++)
    {
        vettore[i]+=val_pert[i]*v_norma_infinita;
    }
    
    #ifdef DEBUG
	debug2(vettore,l,val_pert);
	#endif
	
    fclose(fp);
	free(val_pert);
return SUCCESS;
}


float norma_infinita(float * const vettore,const unsigned int * const l)
{
    float max=0;
    for(unsigned int i=0;i<*l;i++)
    {
        if(abs(vettore[i])>max)
        {
            max=abs(vettore[i]);
        }
    }
return max;
}
