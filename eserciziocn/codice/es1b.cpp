#include <iostream>
#include <cmath>
 
using namespace std;
 
float factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}
int norma_infinita(int matrix[10][10], int RIGHE, int COLONNE)
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
int main(){
  
    cout<<"calcolo la matrice di pascal:"<<endl;
      // Pij = (i+j-2 i-1)= (i+j-2)!/(i-1)!(j-1)!
    int matrice_pascal[10][10];
 
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10;j++)
        {
            matrice_pascal[i][j]=(factorial((i+1)+(j+1)-2))/(factorial(i)*factorial(j));
            cout<<matrice_pascal[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
    cout<<"la norma infinita della matrice di Pascal e' "<<norma_infinita(matrice_pascal,10,10)<<endl;
 
    return 0;
}