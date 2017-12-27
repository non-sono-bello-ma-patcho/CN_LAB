#include <iostream>
#include <math.h>

using namespace std;

int norma_infinita(int matrix[4][4], int RIGHE, int COLONNE)
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
    //inizializzo la matrice multidimensionale
    int a[4][4] = {
        {3, 1 -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };
    a[0][0]=3;
    a[0][1]=1;
    a[0][2]=-1;
    a[0][3]=0;

    int b[4][4] = {
        {2, 4 -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };
    b[0][0]=2;
    b[0][1]=4;
    b[0][2]=-2;
    b[0][3]=0;
   
    cout<<"la norma infinita della matrice A1 e' "<<norma_infinita(a,4,4)<<endl;
    cout<<"la norma infinita della matrice A2 e' "<<norma_infinita(b,4,4)<<endl;

}
    
