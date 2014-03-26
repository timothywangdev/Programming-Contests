#include <iostream>
#include <string>
using namespace std;

unsigned int n,a,b;
bool getBit(unsigned int &mask,int pos){
	return (mask & (1<<pos))>0;
}
void clearBit(unsigned int &mask,int pos){
	mask= (mask & (~(1<<pos)));
}
void setBit(unsigned int &mask,int pos){
	mask=(mask | (1<<pos));
}
int main(){
	while(cin>>n){
		if(!n)
			break;
		a=b=0;
		bool sign=true;
		for(int i=0;i<32;i++)
			if(getBit(n,i)){
				if(sign)
					setBit(a,i);
				else
					setBit(b,i);
				sign=1-sign;
			}
	    cout<<a<<" "<<b<<endl;
	}
	return 0;
}