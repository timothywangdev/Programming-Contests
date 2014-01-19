#include <iostream>
#include <iomanip>
using namespace std;
int n,k,c[1000],a;
double t;
int main(){
    cin>>n;
	for(int i=0;i<n;i++){
        cin>>k;
		t=0;
		for(int j=0;j<k;j++){
			cin>>c[j];
			t+=c[j];
		}
		t/=(double)k;
		a=0;
        for(int j=0;j<k;j++)
			if((double)c[j]>t)
				a++;
		double rv=((double)a*100)/(double)k;
		cout << std::fixed;
		cout<<setprecision(3)<<rv<<"%"<<endl;

	}
	return 0;
}