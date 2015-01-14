#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int T, S, N,x,y,gg;
struct ii{
	int a;
	int b;
	double w;
	ii(int a, int b, double w) :a(a),b(b),w(w){}
};
vector<ii> edges,rv;
struct Cor{
	int x;
	int y;
	Cor(){}
	Cor(int x, int y) :x(x), y(y){}
};
map<int, Cor> toCor;
void addNode(Cor c){
	toCor[gg] = c;
	gg++;
}
double getDist(Cor &a, Cor &b){
	return sqrt((double)(a.x - b.x)*(double)(a.x - b.x) + (double)(a.y - b.y)*(double)(a.y - b.y));
}
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
bool myCmp(const ii &a, const ii &b){
	return a.w < b.w;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> S >> N;
		edges.clear();
		toCor.clear();
		rv.clear();
		gg = 0;
		for (int i = 0; i < N; i++){
			cin >> x >> y;
			addNode(Cor(x, y));
		}
		for (int i = 0; i < N-1; i++){
			for (int j = i+1; j < N; j++){
				if (i != j){
					edges.push_back(ii(i,j, getDist(toCor[i], toCor[j])));
				}
			}
		}
		sort(edges.begin(), edges.end(), myCmp);
		UnionFind uf(N);
		for (int i = 0; i < edges.size(); i++){
			ii front = edges[i];
			if (!uf.same_set(front.a, front.b)){

				uf.union_set(front.a, front.b);	
				rv.push_back(front);
			}
		}
		if (rv.size()>=S){
			cout << fixed<<setprecision(2)<<rv[rv.size() - S].w << endl;
		}
		else{
			cout << "0.00" << endl;
		}
	}
	return 0;
}