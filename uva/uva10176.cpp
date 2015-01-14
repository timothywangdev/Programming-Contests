#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL N,M=131071,index;
string s;

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
char ch;
int main(){
  while(cin>>ch){
    s=s+ch;
    while(cin>>ch){
      if(ch=='#')break;
      s=s+ch;
    }
    LL power=0;
    LL tmp;
    LL N=0;
    for(int i=s.size()-1;i>=0;i--){
      if(s[i]=='1'){
	tmp=mpow(2,power,M);
      }
      else{
	tmp=0;
      }
      N=(N+tmp)%M;
      power++;
    }
    //cout<<N<<endl;
    if(N==0){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
    s="";
  }
  return 0;
}
