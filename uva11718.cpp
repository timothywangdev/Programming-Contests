#include <iostream>
#include <cmath> 
#define MAX_LL 9223372036854775807
typedef long long LL;
using namespace std;
LL N,K,M,T,tmp,sum;
LL getPow(LL n,LL c){
  if(c==0)return 1;
  if(n==1)return 1;
  LL k=log10((double)MAX_LL)/log10((double)n);
  // cout<<log((double)MAX_LL)<<" "<<log((double)n)<<endl;
  LL curr=0;
  LL T=1;
  while(true){
    if(curr+k>c){
      return (T*((LL)pow(n,c-curr)%M))%M;
    }
    else{
      T=(T*((LL)pow(n,k)%M))%M;
      curr+=k;
    }
  }
}
long long mpow(long long x, long long y, long long mod) {
    long long ret = 1;
    while(y) {
        if(y&1)
            ret *= x, ret %= mod;
        y >>= 1;
        x = x*x, x %= mod;
    }
    return ret;
}
int main(){
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>N>>K>>M;
    sum=0;
    for(int i=0;i<N;i++){
      cin>>tmp;
      sum=(sum+tmp)%M;
    }
    // double rv=log10((double)K)+(K-1)*log10((double)N)+log10((double)sum);
    cout<<"Case "<<t<<": ";
    cout<<((K%M)*((mpow(N,K-1,M)*sum)%M))%M<<endl;
    //cout<<(LL)pow(10,rv)%M<<endl;
  }
  return 0;
}
