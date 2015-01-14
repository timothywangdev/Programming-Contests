#include <iostream>
#include <bitset>
#define MAXIMUM 1000000
using namespace std;

int N,M,cal,s,e,r;
bool conflict;
bitset<MAXIMUM+10> bit;
bool con(int head,int tail){
	for(int i=head+1;i<=tail&&i<=MAXIMUM;i++)
		if(bit[i])
			return true;
		else
			bit[i]=1;
	return false;
}
int main(){
	while(cin>>N>>M){
		if(N==0&&M==0)
			break;
		conflict=false;
		bit.reset();
		for(int i=0;i<N&&!conflict;i++){
			cin>>s>>e;
			if(!conflict&&con(s,e))
				conflict=true;
		}
		for(int i=0;i<M&&!conflict;i++){
			cin>>s>>e>>r;
			for(int k=0;s+k*r<=MAXIMUM&&!conflict;k++){
				if(con(s+k*r,e+k*r))
					conflict=true;
			}
		}
		if(!conflict){
			cout<<"NO CONFLICT"<<endl;
		}
		else{
			cout<<"CONFLICT"<<endl;
		}

	}
	return 0;
}