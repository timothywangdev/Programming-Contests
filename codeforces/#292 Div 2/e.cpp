#include <bits/stdc++.h>

using namespace std;
#define MAXN 100000

#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;
int n,m,a,b;
LL d[2*MAXN],h[2*MAXN],sum[2*MAXN];
// Interface for core functions for the SegmentTree class
template <class Dtype, class Qtype>
class SegmentTreeFunc{
public:
   virtual Qtype combine(Qtype left, Qtype right){ return max(left,right); }
   virtual Qtype eva(Dtype data){ return data; }
};
template <class Dtype, class Qtype>
class SegmentTree{
private:
// st size>=2*2^(floor(log2(n))+1) or loosely 4*n
// default implementation: sum of range[L..R]
// Dtype: data type
// Qtype: query type
   Qtype st[4*2*MAXN][3];
// [0]: max, [1]: max(x), [2]: max(y)
   int n;
   SegmentTreeFunc<Dtype, Qtype> *func;
   int left(int p){ return p << 1; }
   int right(int p){ return (p << 1) + 1; };
   void build(int p, int L, int R, Dtype data []){
      if (L == R){
	 st[p][0] =-1 ;
	 st[p][1]=(L-1>=0)?2*h[L]-sum[L-1]:2*h[L];
	 st[p][2]=(L-1>=0)?2*h[L]+sum[L-1]:2*h[L];
      }
      else{
	 build(left(p), L, (L + R) / 2, data);
	 build(right(p), (L + R) / 2 + 1, R, data);
	 st[p][0]= max(st[left(p)][1]+st[right(p)][2],max(st[left(p)][0],st[right(p)][0]));
	 st[p][1]= max(st[left(p)][1],st[right(p)][1]);
	 st[p][2]= max(st[left(p)][2],st[right(p)][2]);
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
   tuple<LL,LL,LL> rmq(int p, int L, int R, int i, int j){
      if (i <= L&&R <= j){
	 return mt(st[p][0],st[p][1],st[p][2]);
      }
      bool chk_left = check(L, (L + R) / 2, i, j);
      bool chk_right = check((L + R) / 2 + 1, R, i, j);
      if (chk_left&&chk_right){
	 tuple<LL,LL,LL> l= rmq(left(p), L, (L + R) / 2, i, j);
	 tuple<LL,LL,LL> r= rmq(right(p), (L + R) / 2 + 1, R, i, j);
	 return mt(max(get<1>(l)+get<2>(r),max(get<0>(l),get<0>(r))),max(get<1>(l),get<1>(r)),max(get<2>(l),get<2>(r)));
      }
      else if (chk_left){
	 return rmq(left(p), L, (L + R) / 2, i, j);
      }
      else if (chk_right){
	 return rmq(right(p), (L + R) / 2 + 1, R, i, j);
      }
   }
   void _update(int pos, Dtype value, int p, int L, int R){
      if (L == R){
	 st[p] = func->eva(value);
      }
      else{
	 int m = (L + R) / 2;
	 if (pos <= m){
	    _update(pos, value, left(p), L, (L + R) / 2);
	 }
	 else{
	    _update(pos, value, right(p), (L + R) / 2 + 1, R);
	 }
	 Qtype l = st[left(p)];
	 Qtype r = st[right(p)];
	 st[p] = func->combine(l, r);
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
   SegmentTree(SegmentTreeFunc<Dtype, Qtype> *func) :func(func){}
   void build_tree(int n, Dtype data []){
      this->n = n;
      build(1, 0, n - 1, data);
   }
   void build_tree(vector<Dtype> &data){
      this->n = data.size();
      build(1, 0, n - 1, data);
   }
   tuple<LL,LL,LL> query(int left, int right){
      return rmq(1, 0, n - 1, left, right);
   }
   void update(int pos, Dtype value){
      _update(pos, value, 1, 0, n - 1);
   }
// Extra Functions for default implementation
   int find_idx(Qtype targetValue){
      return _find_idx(targetValue, 1, 0, n - 1);
   }
};

int main(){
   cin>>n>>m;
   F(i,n){cin>>d[i];d[i+n]=d[i];}
   F(i,n){cin>>h[i];h[i+n]=h[i];}
   sum[0]=d[0];
   FOR(i,1,2*n-1)sum[i]=sum[i-1]+d[i];
   SegmentTree<LL,LL> seg(new SegmentTreeFunc<LL,LL>());
   seg.build_tree(2*n,d);
   F(i,m){
      cin>>a>>b;
      a--;b--;
      tuple<LL,LL,LL> t=(a<=b)?seg.query(b+1,a+n-1):seg.query(b+1,a-1);
      cout<<get<0>(t)<<endl;
   }
   return 0;
}
