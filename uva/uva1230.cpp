#include <iostream>

using namespace std;

typedef long long LL;

LL X,Y,N;

LL mpow(LL x, LL y, LL mod) {
	LL ret = 1;
	while(y) {
    	if(y&1)
        	ret *= x, ret %= mod;
    	y >>= 1;
    	x = x*x, x %= mod;
	}
	return ret;
}

LL T;
int main(){
  cin>>T;
  for(LL t=0;t<T;t++){
    cin>>X>>Y>>N;
    cout<<mpow(X,Y,N)<<endl;
  }
  cin>>X;
  return 0;
}
