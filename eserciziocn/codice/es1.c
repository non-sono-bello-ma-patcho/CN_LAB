#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXCOLUMNLINE 73 /*è sempre quadrata :D   */

float norma_infinita(float matrix[][MAXCOLUMNLINE], int RIGHE, int COLONNE)
{
    float sum=0, tmp=0;//massima somma riga in valore assoluto
    for(int x=0; x<RIGHE; x++)
    {
        for(int y=0;y<COLONNE; y++)
        {
            tmp+=fabs(matrix[x][y]);
        }
        if (sum<tmp)
            sum=tmp;
            tmp=0;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    if(argc<4){
        puts("\e[94mUSAGE:\e[0m] ./es1.out <filename> <row n> <col n>");
        exit(EXIT_FAILURE);
    }
    float a[MAXCOLUMNLINE][MAXCOLUMNLINE];
    int l_x,l_y;
    FILE *fp;
    l_x=atoi(argv[3]);
    l_y=atoi(argv[2]);

   
    fp=fopen(argv[1],"r");
    if(!fp)
    {
        perror("ERROR:unable to open file");
        return 1;
    }
    
    for(unsigned int x=0;x<l_x;x++)
    {
        for(unsigned int y=0;y<l_y;y++)
        {
            fscanf(fp,"%f",&a[x][y]);
            printf("%f \t", a[x][y]);
        }
        puts("\n\n\n");
    }
    fclose(fp);
    
    //inizializzo la matrice multidimensionale       
    printf("la norma infinita della matrice e' %f\n", norma_infinita(a,l_x,l_y));
    return 0;
}
    
