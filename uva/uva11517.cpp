#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXIMUM 2147483647
using namespace std;
int T, S, M;
int v[101],f[30000][101];
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> S >> M;
		for (int i = 1; i <= M; i++){
			cin >> v[i];
		}
		memset(f, -1, sizeof(f));
		for (int i = 0; i <= M; i++){
			f[0][i] = 0;
		}
		if (S == 0){
			cout << "0 0" << endl;
			continue;
		}
		for (int i = 1;; i++){
			for (int j = 1; j <= M; j++){
				if (i - v[j] >= 0 && f[i - v[j]][j - 1] != -1){
					f[i][j] = 1 + f[i - v[j]][j - 1];
				}
				if (f[i][j]!=-1&&f[i][j - 1] != -1){
					f[i][j] = min(f[i][j], f[i][j - 1]);
				}
				if (f[i][j] == -1){
					f[i][j] = f[i][j - 1];
				}
			}
			if (i >= S){
				if (f[i][M] != -1){
					cout << i << " " << f[i][M] << endl;
					break;
				}
			}
		}
	}
	return 0;
}