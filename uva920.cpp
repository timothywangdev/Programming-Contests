#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
#define EPS 1e-9

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

struct Line{
  double a,b,c;
};

void points_to_line(P p1,P p2,Line &l){
  if(fabs(p1.x-p2.x)<EPS){
    l.a=1.0;
    l.b=0.0;
    l.c=-p1.x;
  }
  else{
    l.a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
    l.b=1.0;
    l.c=-(double)(l.a*p1.x)-p1.y;
  }
}
bool are_parallel(Line &l1, Line &l2){
  return (fabs(l1.a-l2.a)<EPS)&&(fabs(l1.b-l2.b)<EPS);
}
bool are_intersect(Line &l1, Line &l2, P &p){
  if(are_parallel(l1,l2))return false;
  p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
  if(fabs(l1.b)>EPS){
    p.y=-(l1.a*p.x+l1.c);
  }
  else{
    p.y=-(l2.a*p.x+l2.c);
  }
  return true;
}
vector<P> v;
int T,N;
double x,y;
double currentH;
double hypot(double x,double y){
  return sqrt(x*x+y*y);
}
double dist(P &p1, P &p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
}
double calLen(P a, P b){
  Line l1,l2;
  P intersection;
  points_to_line(a,b,l1);
  points_to_line(P(1000,currentH),P(2000,currentH),l2);
  if(are_intersect(l1,l2,intersection)){
    return dist(a,intersection);
  }
  else{
    return 0.0;
  }
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    v.clear();
    for(int i=0;i<N;i++){
      cin>>x>>y;
      v.push_back(P(x,y));
    }
    sort(v.begin(),v.end());
    currentH=0;
    double sum=0;
    for(int i=v.size()-1;i>=0;i--){
      if(v[i].y>currentH){
	sum+=calLen(v[i],v[i+1]);
	currentH=v[i].y;
      }
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
  }
  return 0;
}
