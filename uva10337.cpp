#include <iostream>
#include <string.h>
#include <algorithm>
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
int m[11][1002],f[1002][11];
int N,T;
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		memset(f, 50, sizeof(f));
		cin >> N;
		N /= 100;
		for (int i = 10; i >= 1; i--){
			for (int j = 1; j <= N; j++){
				cin >> m[i][j];
			}
		}
		f[1][1] = 0;
		for (int i = 2; i <= N+1; i++){
			for (int j = 1; j <= 10; j++){
				f[i][j] = f[i - 1][j] + 30-m[j][i - 1];
				if (j - 1 >= 0){
					f[i][j] = min(f[i][j], f[i - 1][j - 1] + 60-m[j-1][i-1]);
				}
				if (j + 1 <= 10){
					f[i][j] = min(f[i][j], f[i - 1][j + 1] + 20 - m[j + 1][i - 1]);
				}
			}
		}
		cout << f[N+1][1] << endl<<endl;
	}
	return 0;
}