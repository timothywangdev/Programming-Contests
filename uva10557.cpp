#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#define INF 2147483647
using namespace std;

bool visited[100],reach[100];
int w[100];
vector<int> dist;
int N, n, tmp;
vector<int> edge[100],reverseEdge[100];
void BellmanFord(){
	dist[0] = -100;
	for (int i = 0; i < N - 1; i++){
		for (int u = 0; u < N; u++){
			if (dist[u] == INF)continue;
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
			if (dist[u] == INF)continue;
			for (int j = 0; j < edge[u].size(); j++){
				int v = edge[u][j];
				if (dist[u] - w[v] >= 0)continue;
				else if (!visited[v] && dist[v]>dist[u] - w[v]){
					dist[v] = dist[u] - w[v];
					visited[v] = true;
					found = true;
				}
			}
		}
	}
}
void reachable(int index){
	visited[index] = true;
	reach[index] = true;
	for (int i = 0; i < reverseEdge[index].size(); i++){
		int v = reverseEdge[index][i];
		if (!visited[v]){
			reachable(v);
		}
	}
}
int main(){
	while (cin >> N){
		if (N == -1){
			break;
		}
		dist = vector<int>(N, INF);
		for (int i = 0; i < N; i++){
			edge[i].clear();
			reverseEdge[i].clear();
		}
		for (int i = 0; i < N; i++){
			cin >> w[i] >> n;
			for (int j = 0; j < n; j++){
				cin >> tmp;
				tmp--;
				edge[i].push_back(tmp);
				reverseEdge[tmp].push_back(i);
			}
		}
		memset(visited, false, sizeof(visited));
		memset(reach, false, sizeof(reach));
		reachable(N - 1);
		memset(visited, false, sizeof(visited));
		BellmanFord();
		bool win = false;
		negative();
		for (int i = 0; i < N; i++){
			if (visited[i] && reach[i]){
				win = true;
				break;
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
	return 0;
}