#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int w[32768];
int po[32768];
int D,n,rv;
int power(int base,int k){
	int rv=1;
	for(int i=0;i<k;i++)
		rv*=base;
	return rv;
}
bool getBit(int &mask,int pos){
	return (mask & (1<<pos))>0;
}
void clearBit(int &mask,int pos){
	mask= (mask & (~(1<<pos)));
}
void setBit(int &mask,int pos){
	mask=(mask | (1<<pos));
}
int main(){
	while(cin>>D){
		memset(po,0,sizeof(po));
		rv=0;
		int upper=power(2,D)-1;
		for(int i=0;i<=upper;i++)
			cin>>w[i];
		for(int i=0;i<=upper;i++){
			for(int j=0;j<D;j++)
				if(!getBit(i,j)){
					n=i;
					setBit(n,j);
					po[i]+=w[n];
				}
				else{
					n=i;
					clearBit(n,j);
					po[i]+=w[n];
				}
		}
		for(int i=0;i<=upper;i++){
			for(int j=0;j<D;j++)
				if(!getBit(i,j)){
					n=i;
					setBit(n,j);
					rv=max(rv,po[i]+po[n]);
				}
		}
		cout<<rv<<endl;
	}
	return 0;
}