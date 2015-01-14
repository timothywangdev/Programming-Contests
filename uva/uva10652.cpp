#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

struct P{
  double x;
  double y;

  P(double x,double y):x(x),y(y){}
  P(){}
  bool operator==(P other)const{
    return fabs(x-other.x)<EPS&&fabs(y-other.y)<EPS;
  }
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


 double DEG_to_RAD(double theta){
   return (theta*PI)/180.0;
 }
 // Rotates p according to origin for theta degrees.
 P rotate(P p, double theta){
   double rad=DEG_to_RAD(theta);
   return P(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
 }

struct Vec{
  double x,y;
  Vec(double x,double y):x(x),y(y){}
};

Vec to_vec(P a, P b){
  return Vec(b.x-a.x,b.y-a.y);
}

Vec scale(Vec v, double s){
  return Vec(v.x*s,v.y*s);
}

P translate(P p, Vec v){
  return P(p.x+v.x,p.y+v.y);
}
double mag(Vec v){
  return sqrt(v.x*v.x+v.y*v.y);
}
double mag_sq(Vec v){
  return v.x*v.x+v.y*v.y;
}
double dot(Vec a, Vec b){
  return a.x*b.x+a.y*b.y;
}

double angle(P a, P o, P b){
   Vec oa=to_vec(o,a),ob=to_vec(o,b);
   return acos(dot(oa,ob)/sqrt(mag_sq(oa)*mag_sq(ob)));
 }
 double cross(Vec a, Vec b){
   return a.x*b.y-a.y*b.x;
 }
 bool collinear(P p, P q, P r){
   return fabs(cross(to_vec(p,q),to_vec(p,r)))<EPS;
 }

double ccw(P p1, P p2, P p3){
  return cross(to_vec(p1,p2),to_vec(p1,p3));
}

// Convex Hull
// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
// Note: the last point in the returned list is the same as the first one.
vector<P> convex_hull(vector<P> ps){
  int i,j,n=ps.size();
  vector<P> rv;
  if(n<=3){
    if(!(ps[0]==ps[n-1])){
      ps.push_back(ps[0]);
    }
    return ps;
  }
  sort(ps.begin(),ps.end());
  for(i=0;i<n;i++){
    while(rv.size()>=2&&ccw(rv[rv.size()-2],rv[rv.size()-1],ps[i])<=0)rv.pop_back();
    rv.push_back(ps[i]);
  }
  int k=rv.size()-1;
  rv.pop_back();
  for(i=n-1;i>=0;i--){
    while(rv.size()-k>=2&&ccw(rv[rv.size()-2],rv[rv.size()-1],ps[i])<=0)rv.pop_back();
    rv.push_back(ps[i]);
  }
  return rv;
}

// Polygon area
double area(const vector<P> &ps){
  double result=0.0,x1,y1,x2,y2;
  if(ps.size()<=2)return 0.0;
  for(int i=0;i<(int)ps.size()-1;i++){
    x1=ps[i].x;
    x2=ps[i+1].x;
    y1=ps[i].y;
    y2=ps[i+1].y;
    result+=(x1*y2-x2*y1);
  }
  return fabs(result)/2.0;
}

double x,y,w,h,j;
int T;
int N;

vector<P> ps;

void addPoints(){
  vector<P> rv;
  rv.push_back(P(-w/2,h/2));
  rv.push_back(P(-w/2,-h/2));
  rv.push_back(P(w/2,h/2));
  rv.push_back(P(w/2,-h/2));
  for(int i=0;i<rv.size();i++){
    rv[i]=rotate(rv[i],-j);
    rv[i].x+=x;
    rv[i].y+=y;
    ps.push_back(rv[i]);
  }    	    
}

int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    ps.clear();
    double a=0.0;
    for(int i=0;i<N;i++){
      cin>>x>>y>>w>>h>>j;
      a+=w*h;
      addPoints();
    }
    vector<P> CH=convex_hull(ps);
    /*
    for(int i=0;i<CH.size();i++){
      cout<<CH[i].x<<" "<<CH[i].y<<endl;
    }
    */
    // cout<<area(CH)<<endl;
    cout<<fixed<<setprecision(1)<<(100.0*a)/area(CH)<<" %"<<endl;
  }
  return 0;
}
