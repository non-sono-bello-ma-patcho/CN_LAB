#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

double factorial(double n){
	if(n==0) return 1;
	return n*factorial(n-1);
}

double power(float base, int exp){
	if(exp==0) return 1;
	return base*power(base, exp-1);
}

double expTaylorExpansion(int deg, int x){
	if(deg==0) return 1;
	return (pow(x, deg)/factorial(deg))+expTaylorExpansion(deg-1, x);
}



int main(){
   	double x[4]={0.5,30,-0.5,-30};
   	double N[5]={3,10,50,100,150};
   	double f_result;
   	double fn_result;
   	/*
		algorithm 1:
			compute approximation for value x=0.5 and x=30, for N value={3, 10, 50, 100, 150}
   	*/
   	cout<<"FIRST ALG:\n";
   	for(int j=0; j<2; j++){
   		for(int i=0; i<5; i++){
   			f_result=exp(0.5);
   			fn_result=expTaylorExpansion(N[i], x[j]);
   			cout<<"\n---------------------------------------------\n";
   			cout<<"for N="<<N[i]<<" and x="<<x[j]<<endl;
   			cout<<"approximation: "<<fn_result<<"\ncomputed value: "<<f_result<<endl;
   			cout<<"relative error: "<<(f_result - fn_result)/f_result<<endl;
   			cout<<"absolute error: "<<f_result - fn_result<<endl;
   			cout<<"---------------------------------------------\n";
   		}
   	}
   	return 0; 
}