#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

LL x,y,d;
void extendedEuclid(LL a, LL b){
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

LL A,B;

int main(){
  while(cin>>A>>B){
    extendedEuclid(A,B);
    cout<<x<<" "<<y<<" "<<d<<endl;
    
  }
  return 0;
}

