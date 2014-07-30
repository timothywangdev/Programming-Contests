#include <iostream>
#include <utility>
using namespace std;
typedef unsigned long long LL;
typedef pair<LL,LL> ll;
LL n,a,b;

LL f(LL x){
  return  (((a*((x*x)%n))%n)%n+b)%n;
}

// Cycle finding for LL f(LL x)
// mu: the start of the cycle
// lambda: the length of the cycle
ll brentCycleFinding(LL x0){
  LL power=1,lambda=1;
  LL tortoise=x0;
  LL hare=f(x0);
  while(tortoise!=hare){
    if(power==lambda){
      tortoise=hare;
      power*=2;
      lambda=0;
    }
    hare=f(hare);
    lambda+=1;
  }
  LL mu=0;
  tortoise=hare=x0;
  for(LL i=0;i<lambda;i++){
    hare=f(hare);
  }
  while(tortoise!=hare){
    tortoise=f(tortoise);
    hare=f(hare);
    mu++;
  }
  return make_pair(mu,lambda);
}

int main(){
  while(cin>>n){
    if(!n)break;
    cin>>a>>b;
    ll rv=brentCycleFinding(0);
    cout<<n-rv.second<<endl;
  }
  return 0;
}
