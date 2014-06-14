#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#define INF 2147483647
using namespace std;
typedef pair<int, int> ii;
int N,M;
int w[200];
vector<ii> edge[200];
vector<int> dist;
int a, b;
bool visited[200];
int getDist(int a, int b){
	int k = w[b] - w[a];
	return k*k*k;
}
void BellmanFord(){
	dist[0] = 0;
	for (int i = 0; i < N-1; i++){
		for (int u = 0; u < N; u++){
			for (int j = 0; j < edge[u].size(); j++){
				ii v = edge[u][j];
				dist[v.second] = min(dist[v.second], dist[u] + v.first);
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
				ii v = edge[u][j];
				if (visited[v.second])continue;
				if (dist[u] == -INF&&!visited[v.second]){
					dist[v.second] = -INF;
					visited[v.second] = true;
					found = true;
				}
				else if (dist[u] != -INF&&dist[v.second]>dist[u] + v.first){
					dist[v.second] = -INF;
					visited[v.second] = true;
					found = true;
				}
			}
		}
	}
}
int counter = 0;
int main(){
	while (cin >> N){
		counter++;
		for (int i = 0; i < N; i++){
			edge[i].clear();
			cin >> w[i];
		}
		dist = vector<int>(N, INF);
		cin >> M;
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			a--;
			b--;
			edge[a].push_back(make_pair(getDist(a, b), b));
		}
		memset(visited, false, sizeof(visited));
		if (N != 0){
			BellmanFord();
			negative();
		}
		cin >> M;
		cout << "Set #" << counter << endl;
		for (int i = 0; i < M; i++){
			cin >> a;
			a--;
			if (a>=N||dist[a] < 3||dist[a]==INF){
				cout << '?'<< endl;
			}
			else{
				cout << dist[a] << endl;
			}
		}
	}
	return 0;
}