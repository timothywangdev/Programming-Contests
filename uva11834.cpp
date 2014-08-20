#include <iostream>
#include <algorithm>
#include <cmath>
#define EPS 1e-9
using namespace std;
typedef long long LL;
int L,C,R1,R2;
int l,c;
struct P{
  LL x;
  LL y;
  P(LL x,LL y):x(x),y(y){}
  P(){}
};
LL hypot_sq(LL x,LL y){
  return x*x+y*y;
}

LL dist_sq(P p1, P p2){
  return hypot_sq(p1.x-p2.x,p1.y-p2.y);
}
bool check(int H, int W){
  LL dsq=dist_sq(P(R1,H-R1),P(W-R2,R2));
  if(dsq>=(R1+R2)*(R1+R2)){
    return 2 * max(R1, R2) <= min(L, C);
  }
  else{
    return false;
  }
}
int main(){
  while(cin>>L>>C>>R1>>R2){
    if(!L&&!C&&!R1&&!R2)break;
    if(check(L,C)||check(C,L)){
      cout<<'S'<<endl;
    }
    else{
      cout<<'N'<<endl;
    }
  }
  return 0;
}
