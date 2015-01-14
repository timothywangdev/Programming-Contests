#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

vector<int> edge[100000];
stack<int> s;
bool visited[100000],ig[100000];
int dfs_low[100000],dfs_num[100000],comp[100000];
int T, N, M, a, b,sum,dfsNumberCounter,ncomp;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	visited[u] = true;
	s.push(u);
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (dfs_num[v]==-1){
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
			comp[k] = ncomp;
			s.pop();
			visited[k] = false;
		} while (k != u);
		ncomp++;
	}
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		while (s.size()){
			s.pop();
		}
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++){
			edge[i].clear();
		}
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			a--;
			b--;
			edge[a].push_back(b);
		}
		sum = 0;
		dfsNumberCounter = 0;
		ncomp = 0;
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(dfs_low, 0, sizeof(dfs_low));
		for (int i = 0; i < N; i++){
			if (dfs_num[i]==-1){
				tarjanSCC(i);
			}
		}
		memset(ig, false, sizeof(ig));
		for (int i = 0; i < N; i++){
			for (int j = 0; j < edge[i].size(); j++){
				if (comp[i] != comp[edge[i][j]]){
					ig[comp[edge[i][j]]] = true;
				}
			}
		}
		for (int i = 0; i < ncomp; i++){
			if (!ig[i]){
				sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}