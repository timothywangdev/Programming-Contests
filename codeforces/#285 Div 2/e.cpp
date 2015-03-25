//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int a[100000];
int counter[100001];
long long n;
bool palin[100000];

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
			return rmq(left(p), L, (L + R) / 2, i, j) + rmq(right(p), (L + R) / 2 + 1, R, i, j);
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
class POS_EVEN :public SegmentTreeFunc<Qtype, Dtype>{
public:
	virtual Qtype combine(Qtype left, Qtype right){ return left + right; }
	virtual Qtype eva(Dtype data){
		if (data>0 && data % 2 == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
};
template<class Qtype, class Dtype>
class POS_ODD :public SegmentTreeFunc<Qtype, Dtype>{
public:
	virtual Qtype combine(Qtype left, Qtype right){ return left + right; }
	virtual Qtype eva(Dtype data){
		if (data>0 && data % 2 == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
};
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
int main(){
	cin >> n;
	memset(counter, 0, sizeof(counter));
	for (int i = 0; i<n; i++){
		cin >> a[i];
		counter[a[i]]++;
	}
	long long k = 0;
	while (a[k] == a[n - k - 1] && k<n){
		k++;
	}
	if (k == n){
		cout << (n*(n + 1)) / 2 << endl;
		return 0;
	}
	int odd = 0;
	for (int i = 1; i <= n; i++){
		if (counter[i] % 2 != 0){
			odd++;
		}
	}
	if ((n % 2 == 0 && odd == 0) || (n % 2 == 1 && odd == 1)){
		long long even, odd, neg, head, prefix,suffix;
		SegmentTree<int, int> seg_pos_even(new POS_EVEN<int, int>()),
			seg_pos_odd(new POS_ODD<int, int>()), seg_neg(new NEG<int, int>());
		memset(palin, false, sizeof(palin));
		if (n % 2 == 1){
			for (int i = n / 2; i >= k; i--){
				if (a[i] == a[n - i - 1]){
					palin[i] = palin[n - i - 1] = true;
				}
				else{
					break;
				}
			}
			// prefix
			memset(counter, 0, sizeof(counter));
			seg_pos_even.build_tree(vector<int>(n, 0));
			seg_pos_odd.build_tree(vector<int>(n, 0));
			seg_neg.build_tree(vector<int>(n, 0));
			head = k;
			while (head <= n - k - 1){
				if (head<n / 2){
					counter[a[head]]++;
					counter[a[n - head - 1]]--;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_even.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_neg.update(a[head], counter[a[head]]);
					seg_neg.update(a[n - head - 1], counter[a[n - head - 1]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (even == 0 && odd == 0 && neg == 0&&palin[head+1]){
						prefix = head;
						break;
					}
				}
				else if (head == n / 2){
					counter[a[head]]++;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 1 && even == 0){
						prefix = head;
						break;
					}
				}
				else{
					counter[a[head]] += 2;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 1 && even >= 0){
						prefix = head;
						break;
					}
				}
				head++;
			}
			// suffix
			memset(counter, 0, sizeof(counter));
			seg_pos_even.build_tree(vector<int>(n, 0));
			seg_pos_odd.build_tree(vector<int>(n, 0));
			seg_neg.build_tree(vector<int>(n, 0));
			head = n-k-1;
			while (head >=0){
				if (head>n / 2){
					counter[a[head]]++;
					counter[a[n - head - 1]]--;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_even.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_neg.update(a[head], counter[a[head]]);
					seg_neg.update(a[n - head - 1], counter[a[n - head - 1]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (even == 0 && odd == 0 && neg == 0&&palin[head-1]){
						suffix = head;
						break;
					}
				}
				else if (head == n / 2){
					counter[a[head]]++;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 1 && even == 0){
						suffix = head;
						break;
					}
				}
				else{
					counter[a[head]] += 2;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 1 && even >= 0){
						suffix = head;
						break;
					}
				}
				head--;
			}
		}
		else{
			for (int i = n / 2-1; i >= k; i--){
				if (a[i] == a[n - i - 1]){
					palin[i] = palin[n - i - 1] = true;
				}
				else{
					break;
				}
			}
			// prefix
			memset(counter, 0, sizeof(counter));
			seg_pos_even.build_tree(vector<int>(n, 0));
			seg_pos_odd.build_tree(vector<int>(n, 0));
			seg_neg.build_tree(vector<int>(n, 0));
			head = k;
			while (head <= n - k - 1){
				if (head<n / 2){
					counter[a[head]]++;
					counter[a[n - head - 1]]--;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_even.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_neg.update(a[head], counter[a[head]]);
					seg_neg.update(a[n - head - 1], counter[a[n - head - 1]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (even == 0 && odd == 0 && neg == 0){
						if (head != n / 2 - 1){
							if (palin[head + 1]){
								prefix = head;
								break;
							}
						}
						else{
							prefix = head;
							break;
						}
					}
				}else{
					counter[a[head]] += 2;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 0 && even >= 0){
						prefix = head;
						break;
					}
				}
				head++;
			}
			// suffix
			memset(counter, 0, sizeof(counter));
			seg_pos_even.build_tree(vector<int>(n, 0));
			seg_pos_odd.build_tree(vector<int>(n, 0));
			seg_neg.build_tree(vector<int>(n, 0));
			head = n - k - 1;
			while (head >= 0){
				if (head>=n / 2){
					counter[a[head]]++;
					counter[a[n - head - 1]]--;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_even.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[n - head - 1], counter[a[n - head - 1]]);
					seg_neg.update(a[head], counter[a[head]]);
					seg_neg.update(a[n - head - 1], counter[a[n - head - 1]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (even == 0 && odd == 0 && neg == 0){
						if (head != n / 2){
							if (palin[head - 1]){
								suffix = head;
								break;
							}
						}
						else{
							suffix = head;
							break;
						}
					}
				}else{
					counter[a[head]] += 2;
					seg_pos_even.update(a[head], counter[a[head]]);
					seg_pos_odd.update(a[head], counter[a[head]]);
					seg_neg.update(a[head], counter[a[head]]);
					even = seg_pos_even.query(1, n);
					odd = seg_pos_odd.query(1, n);
					neg = seg_neg.query(1, n);
					if (neg == 0 && odd == 0 && even >= 0){
						suffix = head;
						break;
					}
				}
				head--;
			}
		}
		//cout << "prefix: " << prefix << endl;
		//cout << "suffix: " << suffix << endl;
		prefix++;
		suffix++;
		cout << (k + 1)*(n - prefix + 1) + suffix*(k + 1) - (k + 1)*(k + 1) << endl;
	}
	else{
		cout << "0" << endl;
	}
	return 0;
}
