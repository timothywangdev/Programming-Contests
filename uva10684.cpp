#include <iostream>
#include <algorithm>
using namespace std;

int v[10000];
int N;

int main(){
    while(cin>>N){
		if(!N)
			break;
		for(int i=0;i<N;i++)
			cin>>v[i];
		int sum=0,rv=0;
		for(int i=0;i<N;i++){
			sum+=v[i];
			rv=max(rv,sum);
			if(sum<0)
				sum=0;
		}
		if(rv>0)
			cout<<"The maximum winning streak is "<<rv<<"."<<endl;
		else
			cout<<"Losing streak."<<endl;
	}
	return 0;
}