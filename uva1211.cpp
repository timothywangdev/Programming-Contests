#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
#include <fstream>

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
int N, r,vv[2001];
double b, v, e, f,ff[2001];
double tim[2001][2001];
double getOneKiloTime(int x){
	if (x >= r){
		return 1.0 / (v - (e*(double)(x - r)));
	}
	else{
		return 1.0 / (v - (f*(double)(r - x)));
	}
}
double t(int start, int end){
	double sum = 0.0;
	for (int i = 0; i < end-start; i++){
		sum += getOneKiloTime(i);
	}
	return sum;
}
double tt(int start, int end, int beginning){
	double sum = 0.0;
	for (int i = start; i < end; i++){
		sum += getOneKiloTime(i-beginning);
	}
	return sum;
}
int main(){
	redirect();
	while (cin >> N){
		if (!N){
			break;
		}
		memset(vv, 0, sizeof(vv));
		ff[0] = 0.0;
		for (int i = 1; i <= N; i++){
			cin >> vv[i];
		}
		cin >> b;
		cin >> r >> v >> e >> f;
		for (int i = 0; i <= N; i++){
			for (int j = i; j <= N; j++){
				if (i == j){
					tim[i][j] = 0;
				}
				else{
					tim[i][j] = tim[i][j - 1] + tt(vv[j-1], vv[j],vv[i]);
				}
			}
		}
		for (int i = 1; i <= N; i++){
			double minimum = -1;
			for (int j = 0; j < i; j++){
				if (j==0){
					minimum =tim[j][i];
				}
				else{
					if (minimum>ff[j] + tim[j][i] + b){
						minimum = ff[j] + tim[j][i] + b;
					}
				}
			}
			ff[i] = minimum;
		}
		cout << fixed<<setprecision(4)<<ff[N] << endl;
		//cout << ff[N] << endl;
	}
	return 0;
}