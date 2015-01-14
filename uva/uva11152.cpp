#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1.0)
#define EPS 1e-9
using namespace std;

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
double hypot(double x,double y){
  return sqrt(x*x+y*y);
}

double dist(P &p1, P &p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
}

double perimeter(double ab, double bc, double ca){
  return ab+bc+ca;
}

double area(double r){
  return PI*r*r;
}
double area(double ab,double bc,double ca){
  double s=0.5*perimeter(ab,bc,ca);
  return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

double r_circum_circle(double ab, double bc, double ca){
  return (ab*bc*ca)/(4.0*area(ab,bc,ca));
}
double r_circum_circle(P a, P b, P c){
  return r_circum_circle(dist(a,b),dist(b,c),dist(c,a));
}
// Return r of the incircle
double r_in_circle(double ab, double bc, double ca){
  return area(ab,bc,ca)/(0.5*perimeter(ab,bc,ca));
}
// Return r of the incircle
double r_in_circle(P a, P b, P c){
  return r_in_circle(dist(a,b),dist(b,c),dist(c,a));
}

double a,b,c;
int main(){
  while(cin>>a>>b>>c){
    double r=r_in_circle(a,b,c);
    double R=r_circum_circle(a,b,c);
    double areaTri=area(a,b,c);
    cout<<fixed<<setprecision(4)<<area(R)-areaTri<<" "<<areaTri-area(r)<<" "<<area(r)<<endl;
  }
  return 0;
}
