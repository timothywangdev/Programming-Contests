#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

short f[10201];
short p[101];
short v[101];
short k;
int M, N;
int main(){
	while (cin >> M >> N){
		for (int i = 1; i <= N; i++){
			cin >> p[i] >> v[i];
		}
		memset(f, -1, sizeof(f));
		f[0] = 0;
		for (int i = 1; i <= N; i++){
			for (int w = M + 200; w >= 0; w--){
				if (w - p[i] >= 0){
					k = f[w - p[i]];
					if (k >= 0){
						k += v[i];
					}
					f[w] = max(f[w], k);
				}
			}
		}
		short maximum = -1000;
		for (int i = 0; i <= min(2000, M); i++){
			maximum = max(maximum, f[i]);
		}
		for (int i = 2001; i <= M + 200; i++){
			maximum = max(maximum, f[i]);
		}
		cout << maximum << endl;
	}
	return 0;
}