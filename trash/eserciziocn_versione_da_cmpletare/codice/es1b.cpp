#include <iostream>
#include <cmath>
 
using namespace std;
 
float factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}
 
int main(){
    // Pij = (i+j-2 i-1)= (i+j-2)!/(i-1)!(j-1)!
    int a[10][10];
 
    for(int i=0; i<10; i++){
        for(int j=0; j<10;j++){
            a[i][j]=(factorial((i+1)+(j+1)-2))/(factorial(i)*factorial(j));
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
    return 0;
}