#include <iostream>
#include <cmath>
#define EPS 1e-6
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
  bool operator==(P other) const {
    return fabs(x-other.x)<EPS && fabs(y-other.y)<EPS;
  }
};
struct Line{
  double a,b,c;
  Line(double a,double b,double c):a(a),b(b),c(c){}
  double getX(double y){return (-b*y-c)/a;}
  double getY(double x){return (-a*x-c)/b;}
};

struct Vec{
 double x,y;
 Vec(double x,double y):x(x),y(y){}
  Vec(P A,P B){
    x=B.x-A.x;
    y=B.y-A.y;
  }
  double operator*(Vec &other){
    return x*other.y-y*other.x;
  }
};

/*
same sides:-1
diff sides:1
on line(either or both points):0
 */
int differentSides(Line l,P A,P B){
  if(fabs(l.a)<EPS){
    double y=l.getY(0);
    if(fabs(A.y-y)<EPS||fabs(B.y-y)<EPS)return 0;
    if((A.y-y)*(B.y-y)<0)return 1;
    else return 0;
  }
  else if(fabs(l.b)<EPS){
    double x=l.getX(0);
    if(fabs(A.x-x)<EPS||fabs(B.x-x)<EPS)return 0;
    if((A.x-x)*(B.x-x)<0)return 1;
    else return 0;
  }
  P M(-1000,l.getY(-1000));
  P N(1000,l.getY(1000));

  Vec v1(M,N);
  Vec v2(M,A);
  Vec v3(M,B);
  double a=v1*v2,b=v1*v3;
  if(fabs(a)<EPS||fabs(b)<EPS)return 0;
  double t=a*b;
  if(t<0.0){
    return 1;
  }
  else if(t>0.0){
    return -1;
  }
}
int main(){
  double x,y,a,b,c;
  int sum=0;
  P A,B;
  cin>>x>>y;
  A=P(x,y);
  cin>>x>>y;
  B=P(x,y);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    Line l(a,b,c);
    if(differentSides(l,A,B)==1){
      sum++;
    }
  }
  cout<<sum<<endl;
  return 0;
}
