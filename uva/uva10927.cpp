#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define EPS 1e-11

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

double dist(P p1, P p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
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

// Angle aob in rad
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
class Pole{
public:
  P p;
  int x;
  int y;
  int h;
  double ang;
  double d;
  Pole(){}
  Pole(P p, int h, int x,int y):p(p),h(h),x(x),y(y){
    ang=angle(p,P(0,0),P(100000,-1));
    d=dist(p,P(0,0));
  }
  bool operator==(Pole other)const{
    // return (fabs(ang-other.ang)<EPS);
     //return ang==other.ang;
    return collinear(P(0,0),p,other.p);
  }
};

bool mysort(const Pole &a, const Pole &b){
  return a.ang<b.ang;
}
bool sort_by_dist(const Pole &a, const Pole &b){
  return a.d<b.d;
}
bool sort_by_cor(const Pole &a, const Pole &b){
  if(a.x<b.x)return true;
  else if(a.x==b.x){
    return a.y<b.y;
  }
  return false;
}

vector<Pole> v,invisiable;
int N,h;
int x,y;
int counter=0;

void process(vector<Pole> align){
  sort(align.begin(),align.end(),sort_by_dist);
  int currentH=-2147483647;
  for(int i=0;i<align.size();i++){
    if(align[i].h<=currentH){
      invisiable.push_back(align[i]);
    }
    else{
      currentH=align[i].h;
    }
  }
}
int main(){
  while(cin>>N){
    if(!N)break;
    counter++;
    v.clear();
    invisiable.clear();
    for(int i=0;i<N;i++){
      cin>>x>>y>>h;
      v.push_back(Pole(P((double)x,(double)y),h,x,y));
    }
    sort(v.begin(),v.end(),mysort);
    vector<Pole> align;
    align.push_back(v[0]);
    for(int i=1;i<=v.size();i++){
      if(i<v.size()&&v[i]==align[align.size()-1]){
	align.push_back(v[i]);
      }
      else{
	process(align);
	align.clear();
	if(i<v.size()){
	  align.push_back(v[i]);
	}
      }
    }
    cout<<"Data set "<<counter<<":"<<endl;
    if(invisiable.size()==0){
      cout<<"All the lights are visible."<<endl;
    }
    else{
      sort(invisiable.begin(),invisiable.end(),sort_by_cor);
      cout<<"Some lights are not visible:"<<endl;
      for(int i=0;i<invisiable.size()-1;i++){
	cout<<"x = "<<invisiable[i].p.x<<", y = "<<invisiable[i].p.y<<";"<<endl;
      }
      cout<<"x = "<<invisiable[invisiable.size()-1].p.x<<", y = "<<invisiable[invisiable.size()-1].p.y<<"."<<endl;
    }
  }
  return 0;
}
