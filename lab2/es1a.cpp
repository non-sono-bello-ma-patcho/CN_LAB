#include <iostream>
#include <math.h>

using namespace std;
float norma_infinita(int matrix[4][4], int RIGHE, int COLONNE)
{
    float sum=0, tmp=0;//massima somma riga in valore assoluto
    for(int x=0; x<RIGHE; x++)
    {
        for(int y=0;y<COLONNE; y++)
        {
            sum+=fabs(matrix[x][y]);
        }
        if (sum<tmp)
            sum=tmp;
    }
    return sum;
}
int main()
{
    //inizializzo la matrice multidimensionale
    int a[4][4] = {
        {3, 1 -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };
    int b[4][4]= {
        {2, 4 -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };
    cout<<"la norma infinita della matrice A1 e' "<<norma_infinita(a,4,4)<<endl;
    cout<<"la norma infinita della matrice A2 e' "<<norma_infinita(b,4,4)<<endl;
    
}
    
