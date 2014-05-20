#include <stdio.h>
#include <algorithm>
using namespace std;

int m[75][75], mm[150][150], sum[150][150];
int T, N, maximum;
int getSum(int a, int b, int c, int d){
	int k = sum[c][d];
	if (b - 1 >= 0){
		k -= sum[c][b - 1];
	}
	if (a - 1 >= 0){
		k -= sum[a - 1][d];
	}
	if (b - 1 >= 0 && a - 1 >= 0){
		k += sum[a - 1][b - 1];
	}
	return k;
}
int dp(int R, int C){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			sum[i][j] = mm[i][j];
			if (i - 1 >= 0){
				sum[i][j] += sum[i - 1][j];
			}
			if (j - 1 >= 0){
				sum[i][j] += sum[i][j - 1];
			}
			if (i - 1 >= 0 && j - 1 >= 0){
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}
	int maximum = -1000000000;
	for (int a = 0; a < N; a++){
		for (int b = 0; b < N; b++){
			for (int c = a; c < R&&c-a<=N-1; c++){
				for (int d = b; d < C&&d - b <= N - 1; d++){
					int k = getSum(a, b, c, d);
					if (k > maximum){
						maximum = k;
					}
				}
			}
		}
	}
	return maximum;
}
int main(){
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				scanf("%d", &mm[i][j]);
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				mm[i + N][j] = mm[i][j];
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				mm[i][j+N] = mm[i][j];
			}
		}
		printf("%d\n", max(dp(N,N*2),dp(N*2,N)));
	}
	return 0;
}