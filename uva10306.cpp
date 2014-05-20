#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXIMUM 2147483647
using namespace std;
//#define DEBUG
#include <fstream>
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
int T, S, M;
int f[301][301];
int ty[40][2];
int getMinNum(int X, int Y){
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for (int x = 0; x <= X; x++){
		for (int y = 0; y <= Y; y++){
			int minimum = MAXIMUM;
			for (int i = 0; i < M; i++){
				if (x - ty[i][0] >= 0 && y - ty[i][1] >= 0 && f[x - ty[i][0]][y - ty[i][1]] != -1){
					minimum = min(minimum, f[x - ty[i][0]][y - ty[i][1]]);
				}
			}
			if (minimum != MAXIMUM){
				f[x][y] = 1 + minimum;
			}
		}
	}
	if (f[X][Y] != -1){
		return f[X][Y];
	}
	else{
		return MAXIMUM;
	}
}
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> M >> S;
		for (int i = 0; i < M; i++){
			cin >> ty[i][0] >> ty[i][1];
		}
		int minimum = MAXIMUM;
		for (int x = 0; x <= S; x++){
			for (int y = 0; y <= S; y++){
				if (x*x + y*y == S*S){
					minimum = min(minimum, getMinNum(x, y));
				}
			}
		}
		if (minimum == MAXIMUM){
			cout << "not possible" << endl;
		}
		else{
			cout << minimum << endl;
		}
	}
	return 0;
}