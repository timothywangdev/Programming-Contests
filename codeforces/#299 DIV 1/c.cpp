#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

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


int n,si,ri;
vector<pair<P,PII> > v;
vector<PII> vv;
int main(){
  cin>>n;
  F(i,n){
    cin>>si>>ri;
    vv.pb(mp(si,ri));
    v.pb(mp(P((double)1/si,(double)1/ri),mp(si,ri)));
  }
  v=convex_hull<PII>(v);
  int s=0,e=0;
  F(i,v.size()-1){
    P p=v[i].first;
    if(p.x<v[s].first.x||(fabs(p.x-v[s].first.x)<EPS&&p.y<v[s].first.y)){
      s=i;
    }
    if(p.y<v[e].first.y||(fabs(p.y-v[e].first.y)<EPS&&p.x<v[e].first.x)){
      e=i;
    }
  }
  set<PII> valid;
  if(s<=e){
    for(int i=s;i<=e;i++){
      valid.insert(v[i].second);
    }
  }
  else{
    for(int i=0;i<abs(s-e);i++){
      valid.insert(v[(s+i)%v.size()].second);
    }
  }
  F(i,vv.size()){
    if(valid.count(vv[i]))
      cout<<i+1<<" ";
  }
  cout<<endl;
  return 0;
}
