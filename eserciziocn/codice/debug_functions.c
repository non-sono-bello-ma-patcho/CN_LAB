#include"output_type.h"

/*testing funzioni gauss_moves*/
void debug(float** matrix,const unsigned int*  altezza,const unsigned int* larghezza)
{
    int scelta=0;
    unsigned int riga1,riga2;
    float valore1,valorebase;
    while(scelta!=42)
    {
        printf("\n\n");
        stampa_risultato(matrix,altezza,larghezza);
        printf("\nQuale operazione vuoi svolgere?\n1:scambia righe(riga1,riga2)\n2:trova parametro(valore1,valorebase)\n3:somma riga con multiplo riga base(riga1,rigabase,parametro\n4:pulisci schermo\n42:esci\n");
        fflush(stdout);
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
                    printf("\nInserisci riga1:");
                    scanf("%u",&riga1);
                    printf("\nInserisci riga2:");
                    scanf("%u",&riga2);
                    if(scambia_righe(matrix,&riga1,&riga2,altezza,larghezza)<0)
                    {perror("Operazione terminata con errore\n");}
                    break;
            case 2:
                    printf("\nInserisci valore1:");
                    scanf("%f",&valore1);
                    printf("\nInserisci valorebase:");
                    scanf("%f",&valorebase);
                    printf("risultato=%f",trova_parametro(&valore1,&valorebase));
                    break;
            case 3:
                    printf("\nInserisci riga1:");
                    scanf("%u",&riga1);
                    printf("\nInserisci rigabase:");
                    scanf("%u",&riga2);
                    printf("\nInserisci parametro:");
                    scanf("%f",&valore1);                    
                    if(somma_riga_con_multiplo_rigabase(matrix,&riga1,&riga2,&valore1,altezza,larghezza)<0)
                    {perror("Operazione terminata con errore\n");}
                    break;
            case 4:
                    system("clear");
                    break;
            case 42:
                    printf("Ok!");
                    break;
            default:
                   printf("\noperazione inesistente");
                   break;
        }
    }
return;
}


void debug2(float* vettore,const unsigned int * l, float* val_pert)
{
	printf("DEBUG-------------------------------\n");
	printf("vettore:");
	for(unsigned int i=0;i<*l;i++)printf("%f ",vettore[i]);
	printf("\nvettore_perturbazione:");
	for(unsigned int i=0;i<*l;i++)printf("%f ",val_pert[i]);
	return;
}
