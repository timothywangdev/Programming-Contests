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

int n,m,k,t,l,r,c;
//============PolyHash Class Bundle================

LL poly_pow[2][100000]; // Change this according to the _pow[2][max_len(str)]
const LL MOD[2]={1000000009,1000000021};
const LL P[2]={113,129};//{113,129}; // larger primes {229,233}

class PolyHash{
public:
  LL v[2];
  int len;
  
  PolyHash():len(0),v{0,0}{}
  PolyHash(LL val):len(1),v{val,val}{}
  PolyHash(const PolyHash &other):len(other.len),v{other.v[0],other.v[1]}{}
  PolyHash operator>>(int k){
    // TODO
  }
  PolyHash operator<<(int k){
    PolyHash rv(*this);
    rv.len+=k;
    rv.v[0]=(v[0]*poly_pow[0][k])%MOD[0];
    rv.v[1]=(v[1]*poly_pow[1][k])%MOD[1];
    return rv;
  }
  // Append
  PolyHash operator+(const PolyHash& other) const{
    PolyHash rv(*this);
    rv=rv<<other.len;
    rv.v[0]=(other.v[0]+rv.v[0])%MOD[0];
    rv.v[1]=(other.v[1]+rv.v[1])%MOD[1];
    return rv;
  }
  bool operator==(const PolyHash& other) const{
    // if(n==20){
    //cout<<len<<" "<<v[0]<<" "<<v[1]<<endl
    // cout<<other.len<<" "<<other.v[0]<<" "<<other.v[1]<<endl;
    // }
    return (len==other.len&&v[0]==other.v[0]&&v[1]==other.v[1]);
  }
  

};
//============PolyHash Class Bundle END================

PolyHash segment[10][100001];
char str[100001];


// Interface for core functions for the SegmentTree class
template <class Dtype, class Qtype>
class SegmentTreeFunc{
public:
  virtual int left(int p){ return p << 1; }
  virtual int right(int p){ return (p << 1) + 1; };
  virtual Qtype combine(Qtype left, Qtype right){ return left + right; }
  virtual Qtype eva(Dtype data){ return PolyHash(data); }
  // Lazy update functons: rangeValue, propagate
  virtual Qtype rangeValue(int L, int R, Dtype value){
    return segment[value-'0'][R-L+1];
  }
  virtual void propagate(int p, int L, int R, bool lazy[], Dtype lazy_range[], Qtype st[]){
    if(lazy[p]){
      lazy[left(p)]=lazy[right(p)]=true;
      lazy_range[left(p)]=lazy_range[p];
      lazy_range[right(p)]=lazy_range[p];
      st[left(p)]=rangeValue(L, (L+R)/2, lazy_range[p]);
      st[right(p)]=rangeValue((L+R)/2+1,R,lazy_range[p]);
      lazy[p]=false;
    }
  }
};


template <class Dtype, class Qtype>
class SegmentTree{
private:
  // st size>=2*2^(floor(log2(n))+1) or loosely 4*n
  // default implementation: sum of range[L..R]
  // Dtype: data type
  // Qtype: query type
  Qtype st[400001+2]; //+2 to avoid invalid access while propagating(lazy update) 
  Dtype lazy_range[400001+2];
  bool lazy[400001+2];
  int n;
  SegmentTreeFunc<Dtype, Qtype> *func;
  int left(int p){ return p << 1; }
  int right(int p){ return (p << 1) + 1; };
  void build(int p, int L, int R, Dtype data []){
    if (L == R){
      st[p] = func->eva(data[L]);
    }
    else{
      build(left(p), L, (L + R) / 2, data);
      build(right(p), (L + R) / 2 + 1, R, data);
      Qtype l = st[left(p)];
      Qtype r = st[right(p)];
      st[p] = func->combine(l, r);
    }
  }
  void build(int p, int L, int R, vector<Dtype> &data){
    if (L == R){
      st[p] = func->eva(data[L]);
    }
    else{
      build(left(p), L, (L + R) / 2, data);
      build(right(p), (L + R) / 2 + 1, R, data);
      Qtype l = st[left(p)];
      Qtype r = st[right(p)];
      st[p] = func->combine(l, r);
    }
  }
  bool check(int L, int R, int i, int j){
    return !(i>R || j<L);
  }
  Qtype rmq(int p, int L, int R, int i, int j){
    if(L!=R)func->propagate(p,L,R,lazy,lazy_range,st);
    if (i <= L&&R <= j){
      return st[p];
    }
    bool chk_left = check(L, (L + R) / 2, i, j);
    bool chk_right = check((L + R) / 2 + 1, R, i, j);
    if (chk_left&&chk_right){
      return func->combine(rmq(left(p), L, (L + R) / 2, i, j),rmq(right(p), (L + R) / 2 + 1, R, i, j));
    }
    else if (chk_left){
      return rmq(left(p), L, (L + R) / 2, i, j);
    }
    else if (chk_right){
      return rmq(right(p), (L + R) / 2 + 1, R, i, j);
    }
  }
  void _update(int p, int L, int R, int i, int j, Dtype value){
    if(L!=R)func->propagate(p,L,R,lazy,lazy_range,st);
    if(R<i||L>j)return;
    if (i <= L&&R <= j){
      st[p]=func->rangeValue(L,R,value);
      lazy[p]=true;
      lazy_range[p]=value;
    }
    else{
      _update(left(p), L, (L + R) / 2, i, j, value);
      _update(right(p), (L + R) / 2 + 1, R, i, j, value);
      st[p] = func->combine(st[left(p)], st[right(p)]);
    }
  }
  // Extra Functions for the default implementation
  // Warning: For the default implementation only!
  // Binary search for an index where st[index]==targetValue
  // Returns left-most index if multiple valid indices exist
  int _find_idx(Qtype targetValue, int p, int L, int R){
    if (L == R){
      if (st[p] == targetValue){
	return L;
      }
      else{
	return -1;
      }
    }
    if (st[left(p)] >= targetValue){
      return _find_idx(targetValue, left(p), L, (L + R) / 2);
    }
    else{
      return _find_idx(targetValue - st[left(p)], right(p), (L + R) / 2 + 1, R);
    }
  }
public:
  SegmentTree(SegmentTreeFunc<Dtype, Qtype> *func) :func(func){
    memset(lazy,false,sizeof(lazy));
  }
  void build_tree(int n, Dtype data []){
    this->n = n;
    build(1, 0, n - 1, data);
  }
  void build_tree(vector<Dtype> &data){
    this->n = data.size();
    build(1, 0, n - 1, data);
  }
  Qtype query(int left, int right){
    return rmq(1, 0, n - 1, left, right);
  }
  // Lazy update 
  void update(int left, int right, Dtype value){
    _update(1, 0, n-1, left, right, value);
  }
  // Extra Functions for default implementation
  int find_idx(Qtype targetValue){
    return _find_idx(targetValue, 1, 0, n - 1);
  }
};


int main(){
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s",str);
  
  for(int idx=0;idx<2;idx++){
    for(int i=0;i<n;i++){
      if(i==0)poly_pow[idx][i]=1;
      else poly_pow[idx][i]=(poly_pow[idx][i-1]*P[idx])%MOD[idx];
    }
  }

  for(char ch='0';ch<='9';ch++){
    for(int len=0;len<=n;len++){
      if(len==0){
	segment[ch-'0'][len]=PolyHash();
      }
      else{
	segment[ch-'0'][len]=segment[ch-'0'][len-1]+PolyHash(ch);
      }
    }
  }
  
  SegmentTree<char, PolyHash> seg(new SegmentTreeFunc<char, PolyHash>());
  
  seg.build_tree(n,str);
  m+=k;
  F(i,m){
    scanf("%d%d%d%d",&t,&l,&r,&c);
    l--;r--;
    if(t==1){
      seg.update(l,r,c+'0');
    }
    else{
      if(r-l+1<=c){
	printf("YES\n");
      }
      else{
	if(seg.query(l,r-c)==seg.query(l+c,r)){
	  printf("YES\n");
	}
	else{
	  printf("NO\n");
	}
      }
    }
  }
  
  return 0;
}
