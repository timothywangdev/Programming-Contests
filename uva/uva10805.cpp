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
vector< pair<int, ii> > edges, chosenEdges;
vector<int> rv;
bool e[25][25];
bool visited[25];
int N, M, a, b, c, sum, T,iii,furthest;
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
bool operator ==(const pair<int, ii> &a, const pair<int, ii> &b){
	return a.first == b.first&&a.second.a == b.second.a&&a.second.b == b.second.b;
}
void dfs(int u, pair<int, ii> &target){
	visited[u] = true;
	for (int i = 0; i < edges.size(); i++){
		if (edges[i] != target){
			if (edges[i].second.a == u){
				if (!visited[edges[i].second.b]){
					dfs(edges[i].second.b, target);
				}
			}
			else if (edges[i].second.b == u){
				if (!visited[edges[i].second.a]){
					dfs(edges[i].second.a, target);
				}
			}
		}
	}
}
bool connected(pair<int, ii> &target){
	memset(visited, false, sizeof(visited));
	dfs(0, target);
	for (int i = 0; i < N; i++){
		if (!visited[i]){
			return false;
		}
	}
	return true;
}
int mst(pair<int, ii> target, bool maximum){
	int mst_cost = 0;
	UnionFind uf(N);
	for (int i = 0; i < edges.size(); i++){
		if (edges[i] == target){
			continue;
		}
		pair<int, ii> front = edges[i];
		if (!uf.same_set(front.second.a, front.second.b)){
			mst_cost += front.first;
			e[front.second.a][front.second.b] = e[front.second.b][front.second.a]=true;
			uf.union_set(front.second.a, front.second.b);
			if (maximum){
				chosenEdges.push_back(edges[i]);
			}
		}
	}
	return mst_cost;
}
void getFurthest(int u, int dist){
	visited[u] = true;
	for (int i = 0; i < edges.size(); i++){
		pair<int, ii> front = edges[i];
		ii ee = front.second;
		if (!e[ee.a][ee.b])continue;
		if (ee.a == u){
			if (!visited[ee.b]){
				getFurthest(ee.b, dist + 1);
			}
		}
		if (ee.b == u){
			if (!visited[ee.a]){
				getFurthest(ee.a, dist + 1);
			}
		}
	}
	if (dist > furthest){
		furthest = dist;
		iii = u;
	}
	visited[u] = false;
}
int getResponse(){
	iii = -1;
	furthest = -1;
	getFurthest(0,0);
	furthest = -1;
	getFurthest(iii,0);
	return furthest;
}
int main(){
	cin >> T;
	for (int t = 0; t<T; t++){
		int minimum = 2147483647;
		int minResponse = 2147483647;
		cin >> N >> M;
		edges.clear();
		chosenEdges.clear();
		sum = 0;
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			c = 1;
			sum += c;
			edges.push_back(make_pair(c, ii(a, b)));
		}
		sort(edges.begin(), edges.end(), myCmp);
		pair<int, ii> pp = make_pair(-1, ii(-1, -1));
		memset(e, false, sizeof(e));
		memset(visited, false, sizeof(visited));
		int k;
		minimum= mst(pp, true);
		minResponse = getResponse();

		for (int i = 0; i < chosenEdges.size(); i++){
			if (connected(chosenEdges[i])){
				memset(e, false, sizeof(e));
				memset(visited, false, sizeof(visited));
				k=mst(chosenEdges[i], false);
				if (k == minimum){
					minResponse = min(minResponse, getResponse());
				}
			}
		}
		cout << "Case #" << t + 1 << ":" << endl;
		cout << minResponse << endl<<endl;
	}
	return 0;
}
