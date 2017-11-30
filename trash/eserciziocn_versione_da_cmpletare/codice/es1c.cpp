#include <iostream>
#include <math.h>

using namespace std;

//matricola ZAZZERA ELISA :4380663
int main()
{
    int d0=3;
    int d1=6;
    int n=10+(d1+1)+d0;
    int matrix[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) matrix[i][j]=2;
            else if(fabs(i-j)==1) matrix[i][j]=-1;
            else matrix[i][j]=0;

            cout<<matrix[i][j]<<'\t';
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
