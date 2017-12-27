#include <iostream>
#include <math.h>
//matricola ZAZZERA ELISA :4380663
using namespace std;
   
int d0=3;
int d1=6;
const int n=10*(d1+1)+d0;

int norma_infinita(int *matrix[], int RIGHE, int COLONNE)
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
int main()
{
     cout<<"calcolo la matrice diagonale:"<<endl;
    
  
    int **matrice_diagonale = new int*[n];
	for(int i=0; i<n; i++) matrice_diagonale[i]=new int[n]; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) matrice_diagonale[i][j]=2;
            else if(fabs(i-j)==1) matrice_diagonale[i][j]=-1;
            else matrice_diagonale[i][j]=0;

            cout<<matrice_diagonale[i][j]<<"\t";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
     cout<<"la norma infinita della matrice diagonale e' "<<norma_infinita(matrice_diagonale,n,n)<<endl;
 
    return 0;
}
