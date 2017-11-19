#include<iostream>
#include<cmath>


using namespace std;

int main()
{
    
	float eps_sing_prec;
	double eps_doppia_prec;

	int ds, dd;

	for(ds=0;(1+powf(2,-ds))>1;) ds++;
	for(dd=0;(1+pow(2,-dd))>1;) dd++;

	cout<<"max ds value: "<<ds<<"\tmax dd value: "<<dd<<endl;

	eps_doppia_prec=pow(2,-dd);
	eps_sing_prec=(powf(2,-ds));

	cout<<"--------------------------RISULTATO----------------------------\nsingola precisione eps="<<eps_sing_prec<<endl<<"doppia precisione eps="<<eps_doppia_prec<<endl;
	return 0;
}

/*perchè il risultato viene uguale in entrambi??*/
