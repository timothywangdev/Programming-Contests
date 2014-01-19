#include <iostream>
#include <algorithm>
using namespace std;

int n,N,counter,v[50];
int main(){
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>N;
        for(int i=0;i<N;i++)
			cin>>v[i];
        counter=0;
		for(int i=0;i<N;i++)
			for(int j=N-1;j>i;j--)
				if(v[j-1]>v[j]){
                   counter++;
				   swap(v[j-1],v[j]);
				}
		cout<<"Optimal train swapping takes "<<counter<<" swaps."<<endl;
	}
	return 0;
}