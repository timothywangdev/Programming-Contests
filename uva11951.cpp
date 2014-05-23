#include <iostream>
#include <stdio.h>
using namespace std;
#include <fstream>
using namespace std;
#define DEBUG
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(fout.rdbuf());
#endif
}
long long sum[100][100];
long long N, M, K,T,cost;
long long getSum(int a, int b, int c, int d){
	long long  k = sum[c][d];
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
long long  dp(int R, int C){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
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
	long long  maximum = -1000000000;
	bool newStartingPoint = false;
	for (int a = 0; a < R; a++){
		if (newStartingPoint){
			newStartingPoint = false;
		}
		for (int b = 0; b < C; b++){
			if (newStartingPoint){
				newStartingPoint = false;
			}
			
			if ((R - a)*(C - b) < maximum){
				continue;
			}
			
			for (int c = a; c < R&&!newStartingPoint; c++){
				
				if ((c - a + 1)*(C - b) < maximum){
					continue;
				}
				
				for (int d = b; d < C&&!newStartingPoint; d++){
					long long k = getSum(a, b, c, d);
					
					if (k>K){
						break;
					}
					
					if ((c-a+1)*(d-b+1) > maximum&&k<=K){
						maximum = (c - a + 1)*(d - b + 1);
						cost = k;
					}
					else if ((c - a + 1)*(d - b + 1) == maximum&&k <= K&&k < cost){
						cost = k;
					}
				}
			}
		}
	}
	return maximum;
}
int main(){
	redirect();
	scanf("%d", &T);
	//cin>>T;
	for (int t = 0; t < T; t++){
		//cin >> N >> M >> K;
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &K);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				scanf("%d", &sum[i][j]);
			}
		}
		long long  k = dp(N, M);
		if (k == -1000000000){
			k = 0;
			cost = 0;
		}
		cout << "Case #" << t + 1 << ": " << k << " "<<cost<<endl;
	}
	
	return 0;
}