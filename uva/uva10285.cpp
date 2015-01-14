#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

string s;
int T, N, M;
int m[100][100];
int len[100][100];
int mo[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
struct Node{
	int r;
	int c;
	int h;
	Node(){}
	Node(int r, int c,int h) :r(r), c(c),h(h){}
};
vector<Node> v;
bool cmp(const Node &a, const Node &b){
	return a.h < b.h;
}
bool inRange(int r, int c){
	return 0 <= r&&r < N && 0 <= c&&c < M;
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> s >> N >> M;
		v.clear();
		for (int i = 0; i < N; i++){
			for (int j = 0; j< M; j++){
				cin >> m[i][j];
				len[i][j] = 1;
				v.push_back(Node(i, j, m[i][j]));
			}
		}
		sort(v.begin(), v.end(), cmp);
		int maximum = 1;
		for (int i = 0; i < v.size(); i++){
			Node u = v[i];
			for (int j = 0; j < 4; j++){
				int rr = u.r + mo[j][0];
				int cc = u.c + mo[j][1];
				if (inRange(rr, cc)&&m[rr][cc]<u.h){
					len[u.r][u.c] = max(len[u.r][u.c], 1 + len[rr][cc]);
					maximum = max(maximum, len[u.r][u.c]);
				}
			}
		}
		cout << s << ": " << maximum << endl;
	}
	return 0;
}