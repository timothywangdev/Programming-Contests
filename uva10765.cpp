#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int a;
	int b;
	Node(int a, int b) :a(a), b(b){}
};
vector<int> edge[10000];
int dfs_low[10000], dfs_num[10000],c[10000],parent[10000];
bool articulate[10000];
int N, M, a, b, dfsNumberCounter,rootCounter,root;
void findArticulatePoint(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (dfs_num[v] == -1){
			parent[v] = u;
			if (u == root){
				rootCounter++;
			}
			findArticulatePoint(v);
			if (dfs_low[v] >= dfs_num[u]){
				c[u]++;
				articulate[u] = true;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (parent[u] != v){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
	if (articulate[u]){
		if (parent[u] >= 0){
			c[u]++;
		}
	}
	else{
		c[u] = 1;
	}
}
bool myCmp(const Node &a, const Node &b){
	if (a.b > b.b){
		return true;
	}
	else if (a.b == b.b){
		return a.a < b.a;
	}
	return false;
}
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(articulate, false, sizeof(articulate));
		memset(c, 0, sizeof(c));
		memset(parent, -1, sizeof(parent));
		dfsNumberCounter = 0;
		rootCounter = 0;
		for (int i = 0; i < N; i++){
			edge[i].clear();
		}
		while (cin >> a >> b){
			if (a == -1 && b == -1){
				break;
			}
			if (find(edge[a].begin(), edge[a].end(), b) == edge[a].end()){
				edge[a].push_back(b);
			}
			if (find(edge[b].begin(), edge[b].end(), a) == edge[b].end()){
				edge[b].push_back(a);
			}
		}
		root = 0;
		findArticulatePoint(root);
		if (rootCounter > 1){
			articulate[root] = true;
		}
		vector<Node> rv;
		for (int i = 0; i < N; i++){
			if (articulate[i]){
				rv.push_back(Node(i, c[i]));
			}
			else{
				rv.push_back(Node(i, 1));
			}
		}
		sort(rv.begin(), rv.end(), myCmp);
		for (int i = 0; i < M; i++){
			cout << rv[i].a <<" "<< rv[i].b << endl;
		}
		cout << endl;
	}
	return 0;
}