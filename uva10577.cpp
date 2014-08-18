#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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

P get_middle_point(P p1, P p2){
  return P((p1.x+p2.x)/2,(p1.y+p2.y)/2);
}
double DEG_to_RAD(double theta){
  return (theta*PI)/180.0;
}
// Rotates p according to origin for theta degrees.
P rotate(P p, double theta){
  double rad=DEG_to_RAD(theta);
  return P(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
struct Line{
  double a,b,c;
};

// Return a line which is perpendicular to the given line and goes through
// the Point p.
// Note that p must be on the Line l
Line get_perpendicular_line(Line l, P p){
  Line rv;
  // Horizontal line
  if(fabs(l.a-0.0)<EPS){
    rv.a=1;
    rv.c=-p.x;
    rv.b=0;
  }
  else{
    rv.c=-l.a*(p.y-(l.b/l.a)*p.x);
    rv.b=l.a;
    rv.a=-l.b;
  }
  return rv;
}

bool are_parallel(Line &l1, Line &l2){
  return (fabs(l1.a-l2.a)<EPS)&&(fabs(l1.b-l2.b)<EPS);
}
bool are_intersect(Line l1, Line l2, P &p){
  if(are_parallel(l1,l2))return false;
  p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
  if(fabs(l1.b)>EPS){
    p.y=-(l1.a*p.x+l1.c)/l1.b;
  }
  else{
    p.y=-(l2.a*p.x+l2.c)/l2.b;
  }
  return true;
}
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

// Returns the perimeter of a triangle
double perimeter(double ab, double bc, double ca){
  return ab+bc+ca;
}
// Returns the area of a triangle
double area(double ab,double bc,double ca){
  double s=0.5*perimeter(ab,bc,ca);
  return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}
// Returns r of the circumscribed circle
double r_circum_circle(double ab, double bc, double ca){
  return (ab*bc*ca)/(4.0*area(ab,bc,ca));
}
// Returns r of the circumscribed circle
double r_circum_circle(P a, P b, P c){
  return r_circum_circle(dist(a,b),dist(b,c),dist(c,a));
}
int N;
vector<P> v;
double x,y;
int counter=0;
int main(){
  while(cin>>N){
    if(!N)break;
    v.clear();
    for(int i=0;i<3;i++){
      cin>>x>>y;
      v.push_back(P(x,y));
    }
    P center;
    Line l1,l2,pl1,pl2;
    points_to_line(v[0],v[1],l1);
    points_to_line(v[1],v[2],l2);
    pl1=get_perpendicular_line(l1,get_middle_point(v[0],v[1]));
    pl2=get_perpendicular_line(l2,get_middle_point(v[1],v[2]));
    are_intersect(pl1,pl2,center);
    double r=r_circum_circle(v[0],v[1],v[2]);
    double angle=360.0/N;
    P current=v[0];
    current.x-=center.x;
    current.y-=center.y;
    double maxX=current.x;
    double maxY=current.y;
    double minX=current.x;
    double minY=current.y;
    for(int i=1;i<N;i++){
      current=rotate(current,angle);
      maxX=max(maxX,current.x);
      maxY=max(maxY,current.y);
      minX=min(minX,current.x);
      minY=min(minY,current.y);
      //cout<<current.x<<" "<<current.y<<endl;
    }
    counter++;
    cout<<"Polygon "<<counter<<": "<<fixed<<setprecision(3)<<(maxX-minX)*(maxY-minY)<<endl;
  }
  return 0;
}
