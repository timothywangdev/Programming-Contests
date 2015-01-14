#include <iostream>
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
int f[2001][2];
int v[2001];
int T, N;
int gMax;
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int i = 1; i <= N; i++){
			cin >> v[i];
			f[i][0] = f[i][1] = 1;
		}
		for (int i = N; i >= 1; i--){
			for (int j = N; j >i; j--){
				if (v[j] > v[i]){
					f[i][0] = max(f[i][0], f[j][0] + 1);
				}
				if (v[j] < v[i]){
					f[i][1] = max(f[i][1], f[j][1] + 1);
				}
			}
		}
		gMax = 0;
		for (int i = 1; i <= N; i++){
			gMax = max(gMax, f[i][0] + f[i][1] - 1);
		}
		cout << gMax << endl;
	}
	return 0;
}