#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int degree[200];
bool m[200][200];
bool inBound[200],visited[200];
int N, M, a, b;
void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < N; i++){
		if (!visited[i]&&m[u][i]){
			dfs(i);
		}
	}
}
int main(){
	while (cin >> N >> M){
		memset(degree, 0, sizeof(degree));
		memset(m, false, sizeof(m));
		memset(visited, false, sizeof(visited));
		memset(inBound, false, sizeof(inBound));
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			degree[a]++;
			degree[b]++;
			m[a][b] = m[b][a] = true;
			inBound[a] = inBound[b] = true;
		}
		for (int i = 0; i < N; i++){
			if (degree[i] != 0){
				dfs(i);
				break;
			}
		}
		vector<int> f1, f2;
		for (int i = 0; i < N; i++){
			if (visited[i]){
				f1.push_back(i);
			}
			if (inBound[i]){
				f2.push_back(i);
			}
		}
		bool tour = true;
		if (f1 != f2){
			tour = false;
		}
		for (int i = 0; i < N; i++){
			if (visited[i]&&degree[i] % 2 == 1){
				tour = false;
				break;
			}
		}
		if (M == 0){
			tour = false;
		}
		if (tour)cout << "Possible" << endl;
		else cout << "Not Possible" << endl;
	}
	return 0;
}