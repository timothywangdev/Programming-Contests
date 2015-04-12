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

LL n,s,l;
LL a[100001];

/*
  Static RMQ data structure
  Preprocessing: O(nlogn)
  Query: O(1)
*/

// Comparator
template <class T>
class Cmp_min{
public:
   bool operator()(const T &a, const T &b){
      return a<b;
   }
};
template <class T>
class Cmp_max{
public:
   bool operator()(const T &a, const T &b){
      return a>b;
   }
};
template <class T,class Cmp>
class SparseTable{
   vector<vector<T> > spt;
   vector<T> _data;
   Cmp cmp;
public:
   SparseTable(){}
   void build(vector<T> data){
      _data=data;
      int n=data.size();
      spt=vector<vector<T> >(n,vector<T>((int)log2((double)n)+1,0));
      for(int i=0;i<n;i++){
	 spt[i][0]=i;
      }
      for(int j=1;(1<<j)<=n;j++){
	 for(int i=0;i+(1<<j)-1<n;i++){
	    if(cmp(_data[spt[i][j-1]],_data[spt[i+(1<<(j-1))][j-1]]))
	       spt[i][j]=spt[i][j-1];
	    else
	       spt[i][j]=spt[i+(1<<(j-1))][j-1];
	 }
      }
   }
   // Returns an index of the 'minimum' element
   int query(int i,int j){
      int k=(int)floor(log((double)j-i+1)/log(2.0));
      if(!cmp(_data[spt[j-(1<<k)+1][k]],_data[spt[i][k]])){
	 return spt[i][k];
      }
      else{
	 return spt[j-(1<<k)+1][k];
      }
   }
};
/*
Usage:
template<class Qtype, class Dtype>
class NEG :public SegmentTreeFunc<Qtype, Dtype>{
public:
	virtual Qtype combine(Qtype left, Qtype right){ return left + right; }
	virtual Qtype eva(Dtype data){
		if (data<0){
			return 1;
		}
		else{
			return 0;
		}
	}
};
SegmentTree<int, int> seg_neg(new NEG<int, int>());
*/

// Interface for core functions for the SegmentTree class
template <class Dtype, class Qtype>
class SegmentTreeFunc{
public:
   virtual Qtype combine(Qtype left, Qtype right){ 
      if(left!=-1&&right!=-1){
	 return min(left,right);
      }
      else if(left==-1&&right!=-1){
	 return right;
      }
      else if(left!=-1&&right==-1){
	 return left;
      } 
      else{
	 return -1;
      }
   }
	virtual Qtype eva(Dtype data){ return data; }
};

template <class Dtype, class Qtype>
class SegmentTree{
private:
	// st size>=2*2^(floor(log2(n))+1) or loosely 4*n
	// default implementation: sum of range[L..R]
	// Dtype: data type
	// Qtype: query type
	Qtype st[400001];
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
	Qtype query(int left, int right){
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

vector<LL> v;
SparseTable<LL,Cmp_min<LL> > table_min;
SparseTable<LL,Cmp_max<LL> > table_max;
SegmentTree<LL,LL> seg(new SegmentTreeFunc<LL,LL>());
bool check(int S,int E){
   return v[table_max.query(S-1,E-1)]-v[table_min.query(S-1,E-1)]<=s;
}
int binary(int S,int E){
   int s=S,e=E,mid;
   bool got=false;
   if(S==E){
      return S;
   }
   while(s<e){
      mid=(s+e)/2;
      if(check(mid,E)){
	 got=true;
	 e=mid;
      }
      else{
	 s=mid+1;
      }
   }
   return e;
}
LL f[100001];
int main(){
   cin>>n>>s>>l;

   for(int i=1;i<=n;i++){
      cin>>a[i];
      v.pb(a[i]);
   }
   table_min.build(v);
   table_max.build(v);
   memset(f,-1,sizeof(f));
   f[0]=0;
   seg.build_tree(n+1,f);
   for(int i=1;i<=n;i++){
      int k=binary(1,i);
      if(i-l<k-1){
	 f[i]=-1;
      }
      else {
	 f[i]=seg.query(k-1,i-l);
	 if(f[i]!=-1)f[i]++;
      }
      seg.update(i,f[i]);
   }
   cout<<f[n]<<endl;
   return 0;
}
