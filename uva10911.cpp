#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>
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
struct Cor{
	int x;
	int y;
};
Cor v[16];
int N,x,y;
string s;
double f[65536];
int power(int base, int k){
	int rv = 1;
	for (int i = 0; i < k; i++){
		rv *= base;
	}
	return rv;
}
bool bitOn(int bitmask, int pos){
	return (bitmask&(1 << pos))>0;
}
int turnOff(int bitmask, int pos){
	return (bitmask&~(1 << pos));
}
bool valid(int bitmask){
	int sum = 0;
	for (int i = 0; i < 2 * N; i++){
		sum += bitOn(bitmask, i);
	}
	return sum >= 2;
}
double cost(int i, int j){
	return sqrt((double)(v[i].x - v[j].x)*(v[i].x - v[j].x) + (double)(v[i].y - v[j].y)*(v[i].y - v[j].y));
}
int counter = 0;
int main(){
	redirect();
	while (cin >> N){
		if (!N){
			break;
		}
		counter++;
		for (int i = 0; i < 2*N; i++){
			cin >> s >> x >> y;
			v[i].x = x;
			v[i].y = y;
		}
		f[0] = 0;
		int MAX_BITMASK = power(2, 2 * N) - 1;
		for (int bitmask = 1; bitmask <= MAX_BITMASK; bitmask++){
			if (valid(bitmask)){
				f[bitmask] = -1;
				int t1, t2;
				for (int i = 0; i < 2 * N - 1; i++){
					if (bitOn(bitmask, i)){
						for (int j = i + 1; j < 2 * N; j++){
							if (bitOn(bitmask, j)){
								double k = f[turnOff(turnOff(bitmask, i), j)];
								if (f[bitmask] < 0){
									f[bitmask] = k + cost(i, j);
								}
								else{
									f[bitmask] = min(f[bitmask], k + cost(i, j));
								}
							}
						}
					}
				}
			}
		}
		cout << "Case "<<counter<<": "<<fixed << setprecision(2) << f[MAX_BITMASK] << endl;
	}
	return 0;
}