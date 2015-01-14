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
int N, K,f[101][101];
int main(){
	redirect();
	while (cin >> N >> K){
		memset(f, 0, sizeof(f));
		if (!N&&!K)
			break;
		for (int i = 0; i <= N; i++){
			for (int k = 0; k <= K; k++){
				for (int j = 0; j <= i; j++){
					if (k == 1){
						f[i][k] = 1;
					}
					else{
						f[i][k] += f[i - j][k - 1];
						f[i][k] = f[i][k] % 1000000;
					}
				}
			}
		}
		cout << f[N][K] << endl;
	}
	return 0;
}