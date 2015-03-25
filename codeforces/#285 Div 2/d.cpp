#include <bits/stdc++.h>
#define debug_v(v) for(auto i:v)cout<<i<<endl; 
using namespace std;

vector<int> a,b;
int n,t;

template <class Dtype,class Qtype>
class SegmentTree{
private:
  // st size>=2*2^(floor(log2(n))+1) or loosely 4*n
  // default implementation: sum of range[L..R]
  // Dtype: data type
  // Qtype: query type
  Qtype st[800001];
  int n;
  int left(int p){return p<<1;}
  int right(int p){return (p<<1)+1;};
  void build(int p,int L,int R,Dtype data[]){
    if(L==R){
      st[p]=data[L];
    }
    else{
      build(left(p),L,(L+R)/2,data);
      build(right(p),(L+R)/2+1,R,data);
      Qtype l=st[left(p)];
      Qtype r=st[right(p)];
      st[p]=l+r;
    }
  }
  void build(int p,int L,int R,vector<Dtype> &data){
    if(L==R){
      st[p]=data[L];
    }
    else{
      build(left(p),L,(L+R)/2,data);
      build(right(p),(L+R)/2+1,R,data);
      Qtype l=st[left(p)];
      Qtype r=st[right(p)];
      st[p]=l+r;
    }
  }
  bool check(int L,int R,int i,int j){
    return !(i>R||j<L);
  }
  Qtype rmq(int p,int L,int R,int i,int j){
    if(i<=L&&R<=j){
      return st[p];
    }
    bool chk_left=check(L,(L+R)/2,i,j);
    bool chk_right=check((L+R)/2+1,R,i,j);
    if(chk_left&&chk_right){
      return rmq(left(p),L,(L+R)/2,i,j)+rmq(right(p),(L+R)/2+1,R,i,j);
    }
    else if(chk_left){
      return rmq(left(p),L,(L+R)/2,i,j);
    }
    else if(chk_right){
      return rmq(right(p),(L+R)/2+1,R,i,j);
    }
  }
  void _update(int pos,Dtype value,int p,int L,int R){
    if(L==R){
      st[p]=value;
    }
    else{
      int m=(L+R)/2;
      if(pos<=m){
	_update(pos,value,left(p),L,(L+R)/2);
      }
      else{
	_update(pos,value,right(p),(L+R)/2+1,R);
      }
      Qtype l=st[left(p)];
      Qtype r=st[right(p)];
      st[p]=l+r;
    }
  }
  // Extra Functions for the default implementation
  // Warning: For the default implementation only!
  // Binary search for an index where st[index]==targetValue
  // Returns left-most index if multiple valid indices exist
  int _find_idx(Qtype targetValue,int p,int L,int R){
    if(L==R){
      if(st[p]==targetValue){
	return L;
      }
      else{
	return -1;
      }
    }
    if(st[left(p)]>=targetValue){
      return _find_idx(targetValue,left(p),L,(L+R)/2);
    }
    else{
      return _find_idx(targetValue-st[left(p)],right(p),(L+R)/2+1,R);
    }
  }
public:
  void build_tree(int n,Dtype data[]){
    this->n=n;
    build(1,0,n-1,data);
  }
  void build_tree(vector<Dtype> &data){
    this->n=data.size();
    build(1,0,n-1,data);
  }
  Qtype query(int left,int right){
    return rmq(1,0,n-1,left,right);
  }
  void update(int pos,Dtype value){
    _update(pos,value,1,0,n-1);
  }
  // Extra Functions for default implementation
  int find_idx(Qtype targetValue){
    return _find_idx(targetValue,1,0,n-1);
  }
};


/*
  fac vector index: 0 1 2 3 ...
  factorial number: 0!1!2!3!...
 */

// O(nlogn)
vector<int> fac_to_permu(vector<int> &fac){
  int n=fac.size();
  SegmentTree<int,int> st;
  vector<int> data(n,1);
  st.build_tree(data);
  vector<int> permu(n,0);
  for(int i=0;i<n;i++){
    permu[i]=st.find_idx(fac[n-i-1]+1);
    st.update(permu[i],0);
  }
  return permu;
}
// O(nlogn)
vector<int> permu_to_fac(vector<int> &permu){
  int n=permu.size();
  SegmentTree<int,int> st;
  vector<int> fac(n,0),data(n,0);
  st.build_tree(data);
  for(int i=n-1;i>=0;i--){
    fac[n-i-1]=st.query(0,permu[i]);
    st.update(permu[i],1);
  }
  return fac;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t;
    a.push_back(t);
  }
  for(int i=0;i<n;i++){
    cin>>t;
    b.push_back(t);
  }
  vector<int> fac_a=permu_to_fac(a);
  vector<int> fac_b=permu_to_fac(b);
  //debug_v(fac_a);
  //debug_v(fac_b);
  vector<int> fac_c;
  int remain=0;
  for(int i=0;i<fac_a.size();i++){
    int c=fac_a[i]+fac_b[i]+remain;
    fac_c.push_back(c%(i+1));
    remain=c/(i+1);
  }
  //debug_v(fac_c);
  vector<int> permu=fac_to_permu(fac_c);
  for(int i=0;i<permu.size();i++){
    cout<<permu[i];
    if(i!=permu.size()-1)cout<<" ";
  }
  return 0;
}
