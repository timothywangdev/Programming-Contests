#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
LL T,X,K,x,y,d;
void extendedEuclid(LL a,LL b){
  if(b==0){
    x=1;
    y=0;
    d=a;
    return;
  }
  extendedEuclid(b,a%b);
  LL x1=y;
  LL y1=x-(a/b)*y;
  x=x1;
  y=y1;
}


int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>X>>K;
    extendedEuclid(floor((double)X/(double)K),ceil((double)X/(double)K));
    cout<<x*(X/d)<<" "<<y*(X/d)<<endl;
  }
  return 0;
}
