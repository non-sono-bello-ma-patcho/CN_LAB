#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <limits>
using namespace std;

double factorial(double n)
{
	if(n==0){return 1;}
	return n*factorial(n-1);
}


double expTaylorExpansion(const double& deg,const double& x){
	double result=0;
	for(int i=0;i<=deg;i++)	result+=pow(x,i)/factorial(i);
	return result;
}

void stamp_info(const double N[],const int& i,const double x[],const int& j,const double& fn_result,const double& f_result){
	
	cout<<"\n---------------------------------------------\n";
   	cout<<"for N="<<N[i]<<" and x="<<x[j]<<endl;
   	cout<<"approximation: "<<fn_result<<"\ncomputed value: "<<f_result<<endl;
   	cout<<"relative error: "<<(double)abs(fn_result - f_result)/f_result<<endl;
   	cout<<"absolute error: "<<(double)abs(fn_result - f_result)<<endl;
   	cout<<"---------------------------------------------\n";
}


int main(){
   	double x[4]={0.5,30,-0.5,-30};
   	double N[5]={3,10,50,100,150};
   	double f_result;
   	double fn_result;
   	double fn_res_array_1[5],fn_res_array_2[5];/*il primo array è per i risultati di fn(+0,5) mentre il secondo per fn(+30) al variare del parametro N*/
   	/*
		algorithm 1:
			compute approximation for value x=0.5,x=30,x=-0.5 and x=-30 for N value={3, 10, 50, 100, 150}
   	*/
   	cout<<"FIRST ALG:\n";
   	for(int j=0; j<4; j++){
   		for(int i=0; i<5; i++)
   		{
   			f_result=exp(x[j]);
   			fn_result=expTaylorExpansion(N[i], x[j]);
   			if(x[j]==0.5)/*salvo il risultato per l'algoritmo2*/
   			{  			
   				fn_res_array_1[i]=fn_result;
   			}
   			if(x[j]==30)/*salvo il risultato per l'algoritmo2*/
   			{  			
   				fn_res_array_2[i]=fn_result;
   			}
   			stamp_info(N,i,x,j,fn_result,f_result);
   		}
   	}
   	/*
   	
   		algorithm 2:
   			
   	*/
   	cout<<"\n\n\nSECOND ALG:\n";
   	for(int j=2;j<4;j++){
   		for(int i=0; i<5; i++){
   			f_result=exp(x[j]);
   			if(x[j]==-0.5)
   			{
   				fn_result=(double)1/fn_res_array_1[i];
   			}
   			if(x[j]==-30)
   			{
   				fn_result=(double)1/fn_res_array_2[i];
   			}
   			stamp_info(N,i,x,j,fn_result,f_result);
   		}
   	}
   	
   	return 0; 
}
