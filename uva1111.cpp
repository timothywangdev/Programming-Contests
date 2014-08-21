#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#define INF 1.7e+308
#define EPS 1e-9
using namespace std;

struct P{
  double x;
  double y;
  P(double x,double y):x(x),y(y){}
  P(){}
  bool operator==(P other) const{
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
double cross(Vec a, Vec b){
  return a.x*b.y-a.y*b.x;
}
double hypot(double x,double y){
  return sqrt(x*x+y*y);
}

/*
# Three points are a counter-clockwise turn if ccw > 0, clockwise if
# ccw < 0, and collinear if ccw = 0 because ccw is a determinant that
# gives twice the signed  area of the triangle formed by p1, p2 and p3.
*/

double ccw(P p1, P p2, P p3){
  return cross(to_vec(p1,p2),to_vec(p1,p3));
}

double dist(P &p1, P &p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
}

// Angle aob in rad
double angle(P a, P o, P b){
  Vec oa=to_vec(o,a),ob=to_vec(o,b);
  return acos(dot(oa,ob)/sqrt(mag_sq(oa)*mag_sq(ob)));
}
bool collinear(P p, P q, P r){
  return fabs(cross(to_vec(p,q),to_vec(p,r)))<EPS;
}


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
double dist_to_line(P p, P a, P b, P &c){
  Vec ap=to_vec(a,p),ab=to_vec(a,b);
  double u=dot(ap,ab)/mag_sq(ab);
  c=translate(a,scale(ab,u));
  return dist(p,c);
}


int N;
double x,y;
vector<P> v;

// Convex Hull
// Global variable
P pivot(0,0);
bool angCmp(P a, P b){
  if(collinear(pivot,a,b)){
    return dist(pivot,a)<dist(pivot,b);
  }
  double d1x=a.x-pivot.x,d1y=a.y-pivot.y;
  double d2x=b.x-pivot.x,d2y=b.y-pivot.y;
  return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}

vector<P> CH(vector<P> ps){
  int i,j,n=ps.size();
  if(n<=3){
    if(!(ps[0]==ps[n-1])){
      ps.push_back(ps[0]);
    }
    return ps;
  }
  
  int p0=0;
  for(i=1;i<n;i++){
    if(ps[i].y<ps[p0].y||(ps[i].y==ps[p0].y&&ps[i].x>ps[p0].x)){
      p0=i;
    }
  }

  swap(ps[p0],ps[0]);
  pivot=ps[0];
  sort(ps.begin()+1,ps.end(),angCmp);

  vector<P> s;
  s.push_back(ps[n-1]);
  s.push_back(ps[0]);
  s.push_back(ps[1]);
  i=2;
  while(i<n){
    j=s.size()-1;
    if(ccw(s[j-1],s[j],ps[i])>0){
      s.push_back(ps[i]);
      i++;
    }
    else{
      s.pop_back();
    }
  }
  return s;
}
double getW(P a,P b, vector<P> &ch){
  double maximum=-1.0;
  P t;
  for(int i=0;i<ch.size();i++){
    maximum=max(maximum,dist_to_line(ch[i],a,b,t));
  }
  return maximum;
}
int counter=0;
int main(){
  while(cin>>N){
    if(!N)break;
    counter++;
    v.clear();
    for(int i=0;i<N;i++){
      cin>>x>>y;
      v.push_back(P(x,y));
    }
    vector<P> ch=CH(v);
    double minimumW=INF;
    for(int i=0;i<ch.size()-1;i++){
      double tmp=getW(ch[i],ch[i+1],ch);
      if(tmp<minimumW){
	minimumW=tmp;
      }
    }
    minimumW*=100;
    minimumW=ceil(minimumW);
    minimumW/=100;
    cout<<"Case "<<counter<<": "<<fixed<<setprecision(2)<<minimumW<<endl;
  }
  return 0;
}
