#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool vis[1000];
int match[1000];
int A[100], B[100];
int N, M, T;
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
bool multiple(int a, int b){
	if (a == 0 && b == 0)
		return true;
	if (b != 0){
		if (a%b == 0){
			return true;
		}
	}
	return false;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> A[i];
		}
		cin >> M;
		for (int i = 0; i < M; i++){
			cin >> B[i];
		}
		edge = vector<vector<int> >(N, vector<int>());
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (multiple(B[j], A[i])){
					edge[i].push_back(j + N);
				}
			}
		}
		cout << "Case " << t + 1 << ": " << findMCBM() << endl;
	}
	return 0;
}