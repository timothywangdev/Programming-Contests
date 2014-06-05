#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> edge[2000];
stack<int> s;
int dfs_num[2000], dfs_low[2000];
bool visited[2000];
int N, M, a, b, c,ncomp,dfsNumberCounter;
void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	visited[u] = true;
	s.push(u);
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (dfs_num[v] == -1){
			tarjanSCC(v);
		}
		if (visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]){
		int k;
		do{
			k = s.top();
			s.pop();
			visited[k] = false;
		} while (k != u);
		ncomp++;
	}
}
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		for (int i = 0; i < N; i++){
			edge[i].clear();
		}
		while (s.size()){
			s.pop();
		}
		for (int i = 0; i < M; i++){
			cin >> a >> b >> c;
			a--;
			b--;
			edge[a].push_back(b);
			if (c == 2){
				edge[b].push_back(a);
			}
		}
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(visited, false, sizeof(visited));
		ncomp = 0;
		dfsNumberCounter = 0;
		for (int i = 0; i < N; i++){
			if (dfs_num[i] == -1){
				tarjanSCC(i);
			}
		}
		cout << (int)(ncomp == 1) << endl;
	}
	return 0;
}