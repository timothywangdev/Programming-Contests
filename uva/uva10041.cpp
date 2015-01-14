#include <iostream>
#include <stdlib.h>
using namespace std;

int n,k,tmp,nei[30000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		int sum=0;
		for(int j=0;j<k;j++){
			cin>>tmp;
			nei[j]=tmp;
			sum+=tmp;
		}
		double a=(double)sum/k;
		sum/=k;
		if(abs((double)sum-a)>abs((double)(sum+1)-a)){
			sum++;
		}
		int av=sum;
		sum=0;
		for(int j=0;j<k;j++){
			sum+=abs(nei[j]-av);
		}
		cout<<sum<<endl;
	} 

	return 0;
}