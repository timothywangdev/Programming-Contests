#include <iostream>
#include <cmath>
#include <vector>
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
int N;
double R,x,y;
vector<P> v;

// Check if a point is inside a circle with R
// -1: inside
// 0: on the circle
// 1: outside the circle
int inside_circle(P p, P center, double r){
  double d_sq=(center.x-p.x)*(center.x-p.x)+(center.y-p.y)*(center.y-p.y);
  double rr=R*R;
  if(fabs(d_sq-rr)<EPS)return 0;
  if(d_sq<rr)return -1;
  else return 1;
}

// Given 2 points on the circle and radius r, return the center of the circle;
// return false if two points are impossible on the circle.
// to get the other center, reverse p1 and p2
bool circle_to_pts_rad(P p1, P p2, double r, P &c){
  double d2=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
  double det=r*r/d2-0.25;
  if(det<0.0)return false;
  double h=sqrt(det);
  c.x=(p1.x+p2.x)*0.5+(p1.y-p2.y)*h;
  c.y=(p1.y+p2.y)*0.5+(p2.x-p1.x)*h;
  return true;
}

bool check(P center){
  for(int i=0;i<v.size();i++){
    if(inside_circle(v[i],center,R)>0){
      return false;
    }
  }
  return true;
}
int main(){
  while(cin>>N){
    if(!N)break;
    v.clear();
    for(int i=0;i<N;i++){
      cin>>x>>y;
      v.push_back(P(x,y));
    }
    cin>>R;
    bool found=false;
    for(int i=0;i<v.size()&&!found;i++){
      for(int j=0;j<v.size()&&!found;j++){
	if(i!=j){
	  P center;
	  if(circle_to_pts_rad(v[i],v[j],R,center)){
	    if(check(center)){
	      found=true;
	      break;
	    }
	  }
	}
      }
    }
    if(found){
      cout<<"The polygon can be packed in the circle."<<endl;
    }
    else{
      cout<<"There is no way of packing that polygon."<<endl;
    }
  }
  return 0;
}
