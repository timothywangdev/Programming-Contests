#include <bits/stdc++.h>
#include <iomanip>
#include <tuple>
using namespace std;

class SegmentTree{
private:
  // size(st)-1>=2*2^(floor(log2(n))+1)
  // WARNING: 1-index
  int st[400001];
  int *data;
  int N;
  int left(int p){return p<<1;}
  int right(int p){return (p<<1)+1;};
  void build(int p,int L,int R){
    if(L==R){
      st[p]=data[L];
    }
    else{
      build(left(p),L,(L+R)/2);
      build(right(p),(L+R)/2+1,R);
      int l=st[left(p)];
      int r=st[right(p)];
      st[p]=max(l,r);
    }
  }
  bool check(int L,int R,int i,int j){
    return(!(i>R||j<L));
  }
  int rmq(int p,int L,int R,int i,int j){
    if(i<=L&&R<=j){
      return st[p];
    }
    if(check(L,(L+R)/2,i,j)&&check((L+R)/2+1,R,i,j)){
      return max(rmq(left(p),L,(L+R)/2,i,j),rmq(right(p),(L+R)/2+1,R,i,j));
    }
    else if(check(L,(L+R)/2,i,j)){
      return rmq(left(p),L,(L+R)/2,i,j);
    }
    else if(check((L+R)/2+1,R,i,j)){
      return rmq(right(p),(L+R)/2+1,R,i,j);
    }
    else return -1;
  }
public:
  int query(int i,int j){
    return rmq(1,0,N-1,i,j);
  }
  void update(int p,int L,int R,int i){
    if(!(L<=i&&i<=R))
      return;
    if(L==R){
      st[p]=data[L];
      return;
    }
    update(left(p),L,(L+R)/2,i);
    update(right(p),(L+R)/2+1,R,i);
    st[p]=max(st[left(p)],st[right(p)]);
  }
  void buildTree(int N,int *data){
    this->data=data;
    this->N=N;
    build(1,0,N-1);
  }
};

int N,Q,a[100000];
bool vis[5001][5002];
int mx[5001];
int l,r;
double p;
vector<tuple<int,int,double> > query;
vector<int> childs[5001];
double prob[5001][5002];
SegmentTree st;

bool mysort(const tuple<int,int,double> &a, const tuple<int,int,double> &b){
  if(get<0>(a)<get<0>(b)){
    return true;
  }
  else if(get<0>(a)==get<0>(b)){
    return get<1>(a)>get<1>(b);
  }
  return false;
}

double cal_prob(int node,int j){
  vis[node][j]=true;
  int k;
  double not_selected=1.0,selected=1.0;
  if(j==0){
    selected=0.0;
  }
  prob[node][j]=1.0;
  if(childs[node].size()>0){
    for(int i=0;i<childs[node].size();i++){
    k=childs[node][i];
    if(mx[node]+j-mx[k]>query.size()){
      not_selected*=prob[k][query.size()];
    }
    else{
    if(!vis[k][mx[node]+j-mx[k]]){
      cal_prob(k,mx[node]+j-mx[k]);
    }
    not_selected*=prob[k][mx[node]+j-mx[k]];
    }
    if(j>0){
      if(mx[node]+j-mx[k]-1>query.size()){
	selected*=prob[k][query.size()];
      }
      else{
      if(!vis[k][mx[node]+j-mx[k]-1]){
	cal_prob(k,mx[node]+j-mx[k]-1);
      }
      selected*=prob[k][mx[node]+j-mx[k]-1];
      }
    }
  }
  }
  else{
    if(j==0){
      prob[node][j]=1.0-get<2>(query[node]);
    }
  }
  double p=get<2>(query[node]);
  prob[node][j]=p*selected+(1-p)*not_selected;
}

int main(){
  cin>>N>>Q;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  SegmentTree st;
  st.buildTree(N,a);
  query.push_back(make_tuple(0,N-1,0.0));
  for(int i=0;i<Q;i++){
    cin>>l>>r>>p;
    l--;r--;
    query.push_back(make_tuple(l,r,p));
  }
  sort(query.begin(),query.end(),mysort);
  for(int i=0;i<query.size();i++){
    int last=-1;
    for(int j=i;j<query.size();j++){
      if(j!=i){
	if(get<0>(query[j])>last&&get<0>(query[i])<=get<0>(query[j])&&get<1>(query[j])<=get<1>(query[i])){
	  childs[i].push_back(j);
	  last=get<1>(query[j]);
	}
      }
    }
  }
  memset(vis,false,sizeof(vis));
  for(int i=0;i<=Q;i++){
    mx[i]=st.query(get<0>(query[i]),get<1>(query[i]));
  }
  for(int i=0;i<=Q;i++){
    cal_prob(0,i);
  }
  double rv=prob[0][0]*mx[0];
  for(int i=1;i<=Q;i++){
    rv+=(prob[0][i]-prob[0][i-1])*(mx[0]+i);
  }
  cout<<fixed<<setprecision(6)<<rv<<endl;
  return 0;
}
