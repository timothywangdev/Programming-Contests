#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
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

double x,y;
P M;
int n;
vector<P> v;

struct Seg{
  P p1;
  P p2;
  Seg(){}
  Seg(P p1, P p2):p1(p1),p2(p2){}
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

double dist_to_line(P p, P a, P b, P &c){
  Vec ap=to_vec(a,p),ab=to_vec(a,b);
  double u=dot(ap,ab)/mag_sq(ab);
  c=translate(a,scale(ab,u));
  return dist(p,c);
}
double dist_to_seg(P p, Seg seg, P &c){
  Vec ap=to_vec(seg.p1,p),ab=to_vec(seg.p1,seg.p2);
  double u=dot(ap,ab)/mag_sq(ab);
  if(u<0.0){
    c=P(seg.p1.x,seg.p1.y);
    return dist(p,seg.p1);
  }
  if(u>1.0){
    c=P(seg.p2.x,seg.p2.y);
    return dist(p,seg.p2);
  }
  return dist_to_line(p,seg.p1,seg.p2,c);
}
int main(){
  while(cin>>x>>y){
    M=P(x,y);
    cin>>n;
    v.clear();
    for(int i=0;i<=n;i++){
      cin>>x>>y;
      v.push_back(P(x,y));
    }
    double minimumDist=0;
    bool first=true;
    P rv,tmp;
    for(int i=0;i<n;i++){
      if(first){
	minimumDist=dist_to_seg(M, Seg(v[i],v[i+1]),rv);
	first=false;
      }
      else{
	double dist=dist_to_seg(M, Seg(v[i],v[i+1]),tmp);
	if(minimumDist>dist){
	  minimumDist=dist;
	  rv=tmp;
	}
      }
    }
    cout<<fixed<<setprecision(4)<<rv.x<<endl<<rv.y<<endl;
  }
  return 0;
}
