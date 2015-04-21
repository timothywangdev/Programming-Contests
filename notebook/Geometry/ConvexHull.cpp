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
  bool operator==(P other) const {
    return fabs(x-other.x)<EPS && fabs(y-other.y)<EPS;
  }
};
double ccw(P p1, P p2, P p3){
  return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

// Convex Hull
// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
// Note: the last point in the returned list is the same as the first one.
// Points in the result will be listed in counter-clockwise order.
// T is the associated structure such as indices

// Warning: It only returns non-duplicated points!!!

template <class T>
vector<pair<P,T> > convex_hull(vector<pair<P,T> > ps){
  int i,j,n=ps.size();
  vector<pair<P,T> > rv;
  sort(ps.begin(),ps.end(),[](pair<P,T> a, pair<P,T> b) {
      return (a.first <b.first);});
  for(i=0;i<n;i++){
    while(rv.size()>=2&&ccw(rv[rv.size()-2].first,rv[rv.size()-1].first,ps[i].first)<=0)rv.pop_back();
    rv.push_back(ps[i]);
  }
  int k=rv.size()-1;
  rv.pop_back();
  for(i=n-1;i>=0;i--){
    while(rv.size()-k>=2&&ccw(rv[rv.size()-2].first,rv[rv.size()-1].first,ps[i].first)<=0)rv.pop_back();
    rv.push_back(ps[i]);
  }
  return rv;
}
// Convex Hull without associated structures
vector<P> convex_hull(vector<P> ps){
  vector<pair<P,bool> > _ps,_rv;
  vector<P> rv;
  F(i,ps.size()){
    _ps.pb(mp(ps[i],true));
  }
  _rv=convex_hull<bool>(_ps);
  F(i,_rv.size()){
    rv.pb(_rv[i].first);
  }
  return rv;
}

