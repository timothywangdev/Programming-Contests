#include <iostream>

using namespace std;
typedef long long LL;
long long T,N;
LL gcd(LL x, LL y) {
		if(x == 0)	return y;
		if(y == 0)	return x;
		LL tmp;
		while(x%y) {
			tmp = x, x = y, y = tmp%y;
		}
		return y;
	}
int main(){
  cin>>T;
  for(int t=1;t<=T;t++){
    cout<<"Case "<<t<<": ";
    cin>>N;
    long long num=N*(N-1);
    long long den=4;
    long long g=gcd(num,den);
    num/=g;
    den/=g;
    if(den==1||num==0){
      cout<<num<<endl;
    }
    else{
      cout<<num<<"/"<<den<<endl;
    }
  }
  return 0;
}
