#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int T, N, M;
int m[500][500];
bool vis[1000];
int match[1000];
vector<vector<int> > edge;

int Aug(int l){
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int j = 0; j < edge[l].size(); j++){
		int r = edge[l][j];
		if (match[r] == -1 || Aug(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
int findMCBM(){
	memset(match, -1, sizeof(match));
	int MCBM = 0;
	for (int i = 0; i < N; i++){
		memset(vis, false, sizeof(bool)*N);
		MCBM += Aug(i);
	}
	return MCBM;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		edge = vector<vector<int> >(N, vector<int>());
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cin >> m[i][j];
				if (m[i][j]){
					edge[i].push_back(j+N);
				}
			}
		}
		cout << "Case " << t + 1 << ": a maximum of " << findMCBM() << " nuts and bolts can be fitted together" << endl;
	}
	return 0;
}