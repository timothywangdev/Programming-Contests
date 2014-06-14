#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#define INF 2147483647
using namespace std;

bool reachable[100];
bool visited[100];
int w[100];
vector<int> dist;
int N,n,tmp;
vector<int> edge[100];
void reachbility(int index, int energy){
	visited[index] = true;
	reachable[index] = true;
	for (int i = 0; i < edge[index].size(); i++){
		int u = edge[index][i];
		if (!visited[u]){
			if (energy + w[u]>0){
				reachbility(u, energy + w[u]);
				visited[u] = true;
			}
		}
	}
	visited[index] = false;
}
void BellmanFord(){
	dist[0] = -100;
	for (int i = 0; i < N - 1; i++){
		for (int u = 0; u < N; u++){
			for (int j = 0; j < edge[u].size(); j++){
				int v = edge[u][j];
				if (dist[u] - w[v] >= 0)continue;
				dist[v] = min(dist[v], dist[u] - w[v]);
			}
		}
	}
}
void negative(){
	bool found = true;
	while (found){
		found = false;
		for (int u = 0; u < N; u++){
			for (int j = 0; j < edge[u].size(); j++){
				int v = edge[u][j];
				if (visited[v])continue;
				if (dist[u] == -INF&&!visited[v]){
					dist[v] = -INF;
					visited[v] = true;
					found = true;
				}
				else if (dist[u] != -INF&&dist[v]>dist[u]-w[v]){
					dist[v] = -INF;
					visited[v] = true;
					found = true;
				}
			}
		}
	}
}
bool wontDieInCycle(int index, int energy,int ori_energy){
	visited[index] = true;
	for (int i = 0; i < edge[index].size(); i++){
		int u = edge[index][i];
		if (visited[u]){
			if (energy + w[u]>0 && energy + w[u]>ori_energy){
				visited[index] = false;
				return true;
			}
		}
		else{
			if (energy + w[u]>0){
				if (wontDieInCycle(u, energy + w[u], ori_energy)){
					visited[index] = false;
					return true;
				}
			}
		}
	}
	visited[index] = false;
	return false;
}
int main(){
	while (cin >> N){
		if (N == -1){
			break;
		}
		dist = vector<int>(N, INF);
		for (int i = 0; i < N; i++){
			cin >> w[i] >> n;
			for (int j = 0; j < n; j++){
				cin >> tmp;
				tmp--;
				edge[i].push_back(tmp);
			}
		}
		memset(reachable, false, sizeof(reachable));
		memset(visited, false, sizeof(visited));
		reachbility(0,100);
		BellmanFord();
		if (dist[N - 1] == INF){
			cout << "hopeless" << endl;
		}
		else{
			bool win = false;
			memset(visited, false, sizeof(visited));
			negative();
			memset(visited, false, sizeof(visited));
			for (int i = 0; i < N; i++){
				if (dist[i] == -INF){
					if (reachable[i]){
						win = true;
						break;
					}
				}
			}
			if (dist[N - 1] < 0){
				win = true;
			}
			if (win){
				cout << "winnable" << endl;
			}
			else{
				cout << "hopeless" << endl;
			}
		}
	}
	return 0;
}