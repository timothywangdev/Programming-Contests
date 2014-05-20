/*
There can be multiple edges between two vertices!!!!!!!!!
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#define MAXIMUM 336860180
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

int T, N, M, P, a, b, ca, cb, sum;
int m[51][51], dist[51][51],saving[51];
bool special[51];
char ch;
map<int, int> toNode;
vector<int> nodes;
int makeCost(int ca, int cb){
	return ca * 100 + cb;
}
string toStr(int n){
	ostringstream oss;
	oss << n;
	return oss.str();
}
string costFormat(int c){
	int ca = c / 100;
	int cb = c - ca * 100;
	string a = toStr(ca);
	string b = toStr(cb);
	if (b.length() == 1){
		b = "0" + b;
	}
	return a + '.' + b;
}
void floyd_warshall(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			dist[i][j] = m[i][j];
		}
	}
	for (int i = 0; i < N; i++){
		dist[i][i] = 0;
	}
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (dist[i][j]>dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
unsigned turnOn(unsigned int n, int pos){
	return n | 1 << pos;
}
bool getBit(unsigned n, int pos){
	return ((n&(1 << pos)) != 0);
}
unsigned int power(int base, int k){
	unsigned int rv = 1;
	for (int i = 0; i < k; i++)
		rv *= base;
	return rv;
}
int tsp(int N){
	int t[13][8192];
	unsigned int doneMask = power(2, N) - 1;
	for (unsigned int mask = doneMask; mask >= 1; mask--){
		for (int j = 0; j < N; j++){
			if (getBit(mask, j)){
				int minimum = MAXIMUM;
				if (mask == doneMask){
					t[j][mask] = dist[toNode[j]][0] - saving[toNode[j]];
					continue;
				}
				for (int k = 0; k<N; k++){
					if (!getBit(mask, k)){
						if (minimum>dist[toNode[j]][toNode[k]] + t[k][turnOn(mask, k)]){
							minimum = dist[toNode[j]][toNode[k]] + t[k][turnOn(mask, k)];
						}
					}
				}
				//t[j][mask] = min(minimum, dist[toNode[j]][0]);
				t[j][mask] = min(minimum - saving[toNode[j]], dist[toNode[j]][0]-saving[toNode[j]]);
			}
		}
	}
	return t[0][turnOn(0, 0)];
}
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		N++;
		memset(m, 20, sizeof(m));
		memset(saving, 0, sizeof(saving));
		for (int i = 0; i < M; i++){
			cin >> a >> b >> ca >> ch >> cb;
			m[a][b] = m[b][a] = min(m[a][b],makeCost(ca, cb));
		}

		cin >> P;
		nodes.clear();
		toNode.clear();
		sum = 0;
		nodes.push_back(0);
		for (int i = 0; i < P; i++){
			cin >> a >> ca >> ch >> cb;
			nodes.push_back(a);
			saving[a] = makeCost(ca, cb);
		}
		memset(special, false, sizeof(special));
		for (int i = 0; i < nodes.size(); i++){
			toNode[i] = nodes[i];
		}
		floyd_warshall();
		int save = tsp(nodes.size());
		if (save >= 0){
			cout << "Don't leave the house" << endl;
		}
		else{
			cout << "Daniel can save $" << costFormat(0-save) << endl;
		}
	}
	return 0;
}