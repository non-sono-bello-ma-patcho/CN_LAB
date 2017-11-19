#include"../lib/perturbatore_vettore.h"



int perturba_vettore(float* vettore,const unsigned int * const l)
{
	FILE *fp;
	int scelta=0;/*default*/
	unsigned int i=0,n_val;
	float *val_pert=(float*)malloc(sizeof(float)*(*l));
	if(!val_pert){perror("ERRORE:unable to allocate enouh memory");return FAIL;}
	
	{
	    fflush(stdin);
	    printf("\nVuoi perturbare il vettore b con i dati del file <dati_perturbazione>?(1/0)\n");
	    scanf("%d",&scelta);
	    if(!scelta){return SUCCESS;}
	}
	
	fp=fopen("dati_perturbazione","r");
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
	

    fclose(fp);
	free(val_pert);
return SUCCESS;
}


