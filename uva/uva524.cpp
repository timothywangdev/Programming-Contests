#include <iostream>
#include <string.h>
using namespace std;
int n;
int ring[16];
bool used[17];
bool prime[32];
void search(int pos){
	if(pos==n){
		if(prime[1+ring[n-1]]){
			for(int i=0;i<n;i++){
				if(i>0)
					cout<<" ";
				cout<<ring[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&prime[i+ring[pos-1]]){
			used[i]=true;
			ring[pos]=i;
			search(pos+1);
			used[i]=false;
		}
	}
}
int main(){
	int counter=0;
	memset(prime,false,sizeof(prime));
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=true;
	while(cin>>n){
		counter++;
		if(counter>1)
			cout<<endl;
		cout<<"Case "<<counter<<":"<<endl;
		memset(used,false,sizeof(used));
		ring[0]=1;
		used[1]=true;
		search(1);
	}
	return 0;
}