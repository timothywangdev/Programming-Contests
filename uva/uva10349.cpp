#include <iostream>
#include <vector>
#include <string>
#include <map>
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
int mo[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int V;
vector<vector<int> > edge;
vector<int> match, vis;
string m[40];
int T, N, M, gg;
int Aug(int l){
	if (vis[l]) return 0;
	vis[l] = true;
	for (int j = 0; j < edge[l].size(); j++){
		int r = edge[l][j];
		if (match[r] == -1 || Aug(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
int find_MCBM(){
	int MCBM = 0;
	match.assign(N*M, -1);
	for (int i = 0; i < M*N; i++){
		vis.assign(N*M, false);
		//if (m[i / M][i - (i / M)*M] == '*'){
			MCBM += Aug(i);
		//}
	}
	return MCBM;
}
void addEdge(int ar,int ac, int br,int bc){
	edge[ar*M+ac].push_back(br*M+bc);
}
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> M;
		V=0;
		edge = vector<vector<int> >(N*M, vector<int>());
		for (int i = 0; i < N; i++){
			cin >> m[i];
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (m[i][j] == '*'){
					V++;
					for (int k = 0; k < 4; k++){
						int ii = i + mo[k][0];
						int jj = j + mo[k][1];
						if (0 <= ii&&ii < N && 0 <= jj&&jj < M){
							if (m[ii][jj] == '*'){

								int k = i*M + j;
								if (M % 2 == 0){
									if (i % 2 == 1){
										k++;
									}
								}
								if (k % 2 == 0){
									addEdge(i, j, ii, jj);
								}
							}
						}
					}
				}
			}
		}
		match = vector<int>(N*M, -1);
		vis = vector<int>(N*M, false);
		cout << V-find_MCBM() << endl;
	}
	return 0;
}