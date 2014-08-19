#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;
typedef long long LL;
struct P{
  double x;
  double y;
  P(double x,double y):x(x),y(y){}
  P(){}
  bool operator<(P other) const {
    if(fabs(x-other.x)>EPS){
      return x<other.x;
    }
    else{
      return y<other.y;
    }
  }
};
double hypot_sq(double x,double y){
  return x*x+y*y;
}

double dist_sq(P &p1, P &p2){
  return hypot_sq(p1.x-p2.x,p1.y-p2.y);
}
// Check if a point is inside a circle with R
// -1: inside
// 0: on the circle
// 1: outside the circle
int inside_circle(P p, P center, double r){
  double d_sq=(center.x-p.x)*(center.x-p.x)+(center.y-p.y)*(center.y-p.y);
  double rr=r*r;
  if(fabs(d_sq-rr)<EPS)return 0;
  if(d_sq<rr)return -1;
  else return 1;
}

double x,y;
LL N,a;

int main(){
  while(cin>>N>>a){
    if(N==0)break;
    P upperleft(0.0,a);
    P upperright(a,a);
    P lowerleft(0.0,0.0);
    P lowerright(a,0.0);
    LL counter=0;
    for(int i=0;i<N;i++){
      cin>>x>>y;
      P tmp(x,y);
      if(dist_sq(tmp,upperleft)<=(double)(a*a)&&
	 dist_sq(tmp,upperright)<=(double)(a*a)&&
	 dist_sq(tmp,lowerleft)<=(double)(a*a)&&
	 dist_sq(tmp,lowerright)<=(double)(a*a)){
	counter++;
      }
    }
    cout<<fixed<<setprecision(5)<<(double)counter*(a*a)/N<<endl;
  }
  return 0;
}

