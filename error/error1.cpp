#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int d0=0;
    int d1=4;
    double a, b=((d1+1)*pow(10,20)), c=-b;

   

    for(int i=0; i<7; i++)
    {
       a=(d0+1)*pow(10,i);
       cout<<"il risultato per i="<<i<<" dell'espressione (a+b)+c e' "<<(a+b)+c<<endl;
       cout<<"il risultato per i="<<i<<" dell'espressione a+(b+c) e' "<<a+(b+c)<<endl;
    }
    return 0;
    
}
