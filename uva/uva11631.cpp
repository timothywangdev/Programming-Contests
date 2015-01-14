#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

struct ii{
	int a;
	int b;
	ii(int a, int b) :a(a), b(b){}
};
vector< pair<int, ii> > edges;
int N, M, a, b, c,sum;

class UnionFind{
public:
	int parent[200000];
	UnionFind(int N){
		for (int i = 0; i < N; i++){
			parent[i] = i;
		}
	}
	bool same_set(int x, int y){
		return find_set(x) == find_set(y);
	}
	void union_set(int x, int y){
		int xroot = find_set(x);
		int yroot = find_set(y);
		parent[xroot] = yroot;
	}
	int find_set(int x){
		if (parent[x] != x){
			parent[x] = find_set(parent[x]);
		}
		return parent[x];
	}
};
bool myCmp(const pair<int, ii> &a, const pair<int, ii> &b){
	return a.first < b.first;
}
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		
		edges.clear();
		sum = 0;
		for (int i = 0; i < M; i++){
			cin >> a >> b >> c;
			sum += c;
			edges.push_back(make_pair(c, ii(a, b)));
		}
		sort(edges.begin(), edges.end(), myCmp);
		int mst_cost = 0;

		UnionFind uf(N);
		for (int i = 0; i < edges.size(); i++){
			pair<int, ii> front = edges[i];
			if (!uf.same_set(front.second.a, front.second.b)){
				mst_cost += front.first;
				uf.union_set(front.second.a, front.second.b);
			}
		}
		cout <<sum- mst_cost << endl;
	}
	return 0;
}

