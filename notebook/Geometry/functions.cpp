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
