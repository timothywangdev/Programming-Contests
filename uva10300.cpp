#include <iostream>

using namespace std;

int sum,s,n,f;
int main(){
	int N,F;
	cin>>N;
	for(int k=0;k<N;k++){
		cin>>F;
		int sum=0;
		for(int i=0;i<F;i++){
			cin>>s>>n>>f;
			sum+=s*f;
		}
		cout<<sum;
		//if(k!=N-1)
			cout<<endl;
	}

	return 0;
}