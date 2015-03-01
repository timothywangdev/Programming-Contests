#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

// Interface for core functions for the SegmentTree class
template <class Dtype, class Qtype>
class SegmentTreeFunc{
public:
	virtual Qtype combine(Qtype left, Qtype right){ return left + right; }
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
template<class Qtype, class Dtype>
class SegFunc :public SegmentTreeFunc<Qtype, Dtype>{
public:
  virtual Qtype combine(Qtype left, Qtype right){ return max(left,right); }
	virtual Qtype eva(Dtype data){
	  return data;
	}
};

LL a[5][100000];
LL k;
int n,m;
SegmentTree<LL,LL> *seg[5];
LL getMax(int s,int e,int j){
  //cout<<s<<" "<<e<<" "<<j<<" "<<seg[j]->query(s,e)<<endl;
  return seg[j]->query(s,e);
}
LL eva(int s,int pos){
  LL sum=0;
  for(int i=0;i<m;i++){
    sum+=getMax(s,pos,i);
  }
  return sum;
}
int binarySearch(int s,int e,LL val){
  int lo=s,hi=e,mid;
  while(lo<=hi){
    mid=(lo+hi)/2;
    if(eva(s,mid)<=val){
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  return lo-1;
}
int main(){
  //cin>>n>>m>>k;
  scanf("%d%d%ld",&n,&m,&k);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      //cin>>a[j][i];
       scanf("%ld",&a[j][i]);
    }
  }
  for(int i=0;i<m;i++){
    seg[i]=new SegmentTree<LL,LL>(new SegFunc<LL,LL>());
    seg[i]->build_tree(n,a[i]);
  }
  int rv=0,pos;
  int shots[5];
  memset(shots,0,sizeof(shots));
  for(int i=0;i<n;i++){
    pos=binarySearch(i,(int)n-1,k);
    if(pos-i+1>rv){
      rv=pos-i+1;
      for(int j=0;j<m;j++){
	shots[j]=getMax(i,pos,j);
      }
    }
  }
  for(int j=0;j<m;j++){
    //cout<<shots[j]<<" ";
    printf("%d ",shots[j]);
  }
  cout<<endl;
  return 0;
}
