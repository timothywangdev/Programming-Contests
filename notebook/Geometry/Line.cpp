struct Line{
  double a,b,c;
  P<double> p1;
  P<double> p2;
  Line(double a,double b,double c):a(a),b(b),c(c){}
  Line(P<double> p1, P<double> p2):p1(p1),p2(p2){
     if(fabs(p1.x-p2.x)<EPS){
       a=1.0;
       b=0.0;
       c=-p1.x;
     }
     else{
       a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
       b=1.0;
       c=-(double)(l.a*p1.x)-p1.y;
     }
  }
  Line(){}
  double getX(double y){return (double)(-b*y-c)/a;}
  double getY(double x){return (double)(-a*x-c)/b;}
  bool parallel(Line &other){
    return (fabs(a-other.a)<EPS)&&(fabs(b-other.b)<EPS);
  }
  bool intersect(Line &other, P<double> &p){
    if(parallel(other))return false;
    p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>EPS){
      p.y=-(l1.a*p.x+l1.c);
    }
    else{
      p.y=-(l2.a*p.x+l2.c);
    }
    return true;
  }
};
