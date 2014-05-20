#include <iostream>
#include <string.h>
using namespace std;
#include <fstream>
using namespace std;
//#define DEBUG
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
unsigned long long p[51][51][51][51];
int N, K, M;
int main(){
	redirect();
	while (cin >> N >> K >> M){
		memset(p, 0, sizeof(p));
		p[1][1][1][1] = 1;
		for (int n = 1; n <= N; n++){
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= n-k+1; l++){
					for (int r = 1; r <= k; r++){
						if (n == 1 && k == 1 && l == 1){
							continue;
						}
						// Special case. WA so many times.....
						if (n == l&&k == 1 && r == 1){
							p[n][k][l][r] = 1;
						}
						if (r == 1){
							for (int a = 1; a < l; a++){
								for (int rr = 1; rr <= k-1; rr++){
									if (n - l >= 1 && k - 1 >= 1){
										p[n][k][l][1] += p[n - l][k - 1][a][rr] * k;
									}
								}
							}
						}
						else{
							// Repetition case
							if (n - l >= 1 && k - 1 >= 1){
								p[n][k][l][r] += (p[n - l][k - 1][l][r - 1] * k) / r;
							}
						}
					}
				}
			}
		}
		unsigned long long sum = 0;
		for (int l = 1; l <= M; l++){
			for (int r = 1; r <= K; r++){
				sum += p[N][K][l][r];
			}
		}
		cout << sum << endl;
	}

	return 0;
}