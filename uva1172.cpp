#include <iostream>
#include <string>
#include <string.h>
using namespace std;

long long f[1001][1001];
int bri[1001][1001];
string ty[2][1001];
long long value[2][1001];
int T, N, M;
string s;
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		memset(f, 0, sizeof(f));
		memset(bri, 0, sizeof(bri));
		memset(value, 0, sizeof(value));
		for (int i = 1; i <= N; i++){
			cin >> ty[0][i] >> ty[0][i] >> value[0][i];
		}
		cin >> M;
		for (int i = 1; i <= M; i++){
			cin >> ty[1][i] >> ty[1][i] >> value[1][i];
		}

		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				long long rv = 0, b = 0;
				if (f[i - 1][j] > f[i][j - 1]){
					rv = f[i - 1][j];
					b = bri[i - 1][j];
				}
				else if (f[i - 1][j] < f[i][j - 1]){
					rv = f[i][j - 1];
					b = bri[i][j - 1];
				}
				else{
					rv = f[i][j - 1];
					if (bri[i - 1][j] >= bri[i][j - 1]){
						b = bri[i][j - 1];
					}
					else{
						b = bri[i - 1][j];
					}
				}
				f[i][j] = rv;
				bri[i][j] = b;
				if (ty[0][i] == ty[1][j]){
					if (f[i - 1][j - 1] + value[0][i] + value[1][j] > f[i][j]){
						f[i][j] = f[i - 1][j - 1] + value[0][i] + value[1][j];
						bri[i][j] = bri[i - 1][j - 1] + 1;
					}
					else if (f[i - 1][j - 1] + value[0][i] + value[1][j] == f[i][j]){
						if (bri[i - 1][j - 1] < bri[i][j]){
							f[i][j] = f[i - 1][j - 1] + value[0][i] + value[1][j];
							bri[i][j] = bri[i - 1][j - 1] + 1;
						}
					}
				}
			}
		}
		cout << f[N][M] << " " << bri[N][M] << endl;
	}
	return 0;
}