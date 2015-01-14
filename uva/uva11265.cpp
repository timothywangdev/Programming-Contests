#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define PI acos(-1.0)
#define EPS 1e-9
using namespace std;
typedef long long LL;
int N,W,H,x,y;
int x_1,y_1,x_2,y_2;
int counter=1;
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

struct Seg{
  P p1;
  P p2;
  Seg(){}
  Seg(P p1, P p2):p1(p1),p2(p2){}
};

struct Line_p{
  P p1;
  P p2;
  Line_p(){}
  Line_p(P p1, P p2):p1(p1),p2(p2){}
};

struct Vec{
  double x,y;
  Vec(double x,double y):x(x),y(y){}
};

Vec to_vec(P a, P b){
  return Vec(b.x-a.x,b.y-a.y);
}

vector<vector<P> > polys;
double ccw(P p1, P p2, P p3){
  return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
double cross(Vec a, Vec b){
  return a.x*b.y-a.y*b.x;
}
double dot(Vec a, Vec b){
  return a.x*b.x+a.y*b.y;
}
double mag_sq(Vec v){
  return v.x*v.x+v.y*v.y;
}
// Angle aob in rad
double angle(P a, P o, P b){
  Vec oa=to_vec(o,a),ob=to_vec(o,b);
  return acos(dot(oa,ob)/sqrt(mag_sq(oa)*mag_sq(ob)));
}

double rad_to_degree(double r){
  return r*(180.0/PI);
}
double area(const vector<P> &p){
  double rv=0.0,x1,y1,x2,y2;
  for(LL i=0;i<p.size()-1;i++){
    x1=p[i].x;
    x2=p[i+1].x;
    y1=p[i].y;
    y2=p[i+1].y;
    rv+=(x1*y2-x2*y1);
  }
  return fabs(rv)/2.0;
}

bool in_polygon(P pt, const vector<P> &p){
  if(p.size()==0)return false;
  double sum=0;
  for(LL i=0;i<p.size()-1;i++){
    if(ccw(pt,p[i],p[i+1])<0.0){
      sum+=angle(p[i],pt,p[i+1]);
    }
    else{
      sum-=angle(p[i],pt,p[i+1]);
    }
  }
  // Compares radians
  return fabs(fabs(sum)-2*PI)<EPS;
}

P line_intersect_seg(Seg seg, Line_p l){
  double a=l.p2.y-l.p1.y;
  double b=l.p1.x-l.p2.x;
  double c=l.p2.x*l.p1.y-l.p1.x*l.p2.y;
  double u=fabs(a*seg.p1.x+b*seg.p1.y+c);
  double v=fabs(a*seg.p2.x+b*seg.p2.y+c);
  return P((seg.p1.x*v+seg.p2.x*u)/(u+v),(seg.p1.y*v+seg.p2.y*u)/(u+v));
}

vector<P> cut_polygon(Line_p l, const vector<P> &Q){
  vector<P> p;
  for(LL i=0;i<Q.size();i++){
    double left1=cross(to_vec(l.p1,l.p2),to_vec(l.p1,Q[i]));
    double left2=0;
    if(i!=Q.size()-1){
      left2=cross(to_vec(l.p1,l.p2),to_vec(l.p1,Q[i+1]));
    }
    if(left1>-EPS)p.push_back(Q[i]);
    if(left1*left2<-EPS){
      p.push_back(line_intersect_seg(Seg(Q[i],Q[i+1]),l));
    }
  }
  // a line
  if(p.size()==3&&(p.back()==p.front())){
    p.clear();
    return p;
  }
  if(!p.empty()&&!(p.back()==p.front())){
    p.push_back(p.front());
    return p;
  }
}
int main(){
  while(cin>>N>>W>>H>>x>>y){
    vector<P> poly;
    polys.clear();
    poly.push_back(P(0,0));
    poly.push_back(P(0,H));
    poly.push_back(P(W,H));
    poly.push_back(P(W,0));
    poly.push_back(poly[0]);
    polys.push_back(poly);
    vector<P> target;
    P fountain(x,y);
    for(int i=0;i<N;i++){
      cin>>x_1>>y_1>>x_2>>y_2;
      P A((double)x_1,(double)y_1);
      P B((double)x_2,(double)y_2);
      for(int j=0;j<polys.size();j++){
	if(in_polygon(fountain,polys[j])){
	  target=polys[j];
	  break;
	}
      }
      polys.clear();
      vector<P> left=cut_polygon(Line_p(A,B),target);
      vector<P> right=cut_polygon(Line_p(B,A),target);
      if(left.size()>=4){
	polys.push_back(left);
      }
      if(right.size()>=4){
	polys.push_back(right);
      }
    }
    for(int j=0;j<polys.size();j++){
      if(in_polygon(fountain,polys[j])){
	target=polys[j];
	break;
      }
    }
    cout<<"Case #"<<counter<<": ";
    counter++;
    cout<<fixed<<setprecision(3)<<area(target)<<endl;
  }
  return 0;
}
