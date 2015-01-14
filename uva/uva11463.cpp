#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, T, a, b,s,d;

int m[100][100];

int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;

		memset(m, 50, sizeof(m));
		for (int i = 0; i < N; i++){
			m[i][i] = 0;
		}
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			m[a][b] = m[b][a] = 1;
		}
		cin >> s >> d;
		for (int k = 0; k < N; k++){
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				}
			}
		}
		int maximum = 0;
		for (int i = 0; i < N; i++){
			maximum = max(maximum, m[s][i] + m[i][d]);
		}
		cout << "Case " << t + 1 << ": " << maximum << endl;
	}
	return 0;
}