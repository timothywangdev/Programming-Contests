// dfs causes stack overflow, need to use bfs instead
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
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
struct Node{
	int i;
	int j;
	Node(int i, int j) :i(i), j(j){}
};
int H, W;
bool m[202][202];
bool white[202][202];
bool black[202][202];
int mo[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
string s;
vector<char> rv;
int c;
map<int, char> toChar;
map<char, string> toBi;
void generate(string s, int i ){
	int col = 1;
	for (int j = 0; j < s.size(); j++){
		string tmp = toBi[s[j]];
		for (int k = 0; k < 4; k++,col++){
			m[i][col] = (tmp[k] == '1');
		}
	}
}
bool inRange(int i, int j){
	return 0 <= i&&i < H && 0 <= j&&j < W;
}
void dfs_white(int i, int j){
	queue<Node> q;
	int row, col;
	q.push(Node(i, j));
	white[i][j] = true;
	while (q.size()){
		Node tmp = q.front();
		q.pop();
		for (int k = 0; k < 4; k++){
			row = tmp.i + mo[k][0];
			col = tmp.j + mo[k][1];
			if (inRange(row, col) && !m[row][col] && !white[row][col])
			{
				q.push(Node(row, col));
				white[row][col] = true;
			}
		}
	}
	
}
void dfs(int i, int j){
	queue<Node> q;
	int row, col;
	q.push(Node(i, j));
	black[i][j] = true;
	while (q.size()){
		Node tmp = q.front();
		q.pop();
		for (int k = 0; k < 4; k++){
			row = tmp.i + mo[k][0];
			col = tmp.j + mo[k][1];
			if (inRange(row, col)){
				if (!m[row][col] && !white[row][col]){
					dfs_white(row, col);
					c++;
				}
				else if (m[row][col] && !black[row][col]){
					q.push(Node(row, col));
					black[row][col] = true;
				}
			}
		}
	}
}
int counter = 0;
int main(){
	redirect();
	toChar[1] = 'W';
	toChar[2] = 'A';
	toChar[3] = 'K';
	toChar[4] = 'J';
	toChar[5] = 'S';
	toChar[6] = 'D';
	toBi['0'] = "0000";
	toBi['1'] = "0001";
	toBi['2'] = "0010";
	toBi['3'] = "0011";
	toBi['4'] = "0100";
	toBi['5'] = "0101";
	toBi['6'] = "0110";
	toBi['7'] = "0111";
	toBi['8'] = "1000";
	toBi['9'] = "1001";
	toBi['a'] = "1010";
	toBi['b'] = "1011";
	toBi['c'] = "1100";
	toBi['d'] = "1101";
	toBi['e'] = "1110";
	toBi['f'] = "1111";
	while (cin >> H >> W){
		if (!H&&!W){
			break;
		}
		counter++;
		W *= 4;
		rv.clear();
		memset(black, false, sizeof(black));
		for (int i = 1; i <= H; i++){
			cin >> s;
			generate(s, i);
		}
		W +=2;
		H += 2;
		for (int i = 0; i < W; i++){
			m[0][i] = m[H - 1][i] = false;
		}
		for (int i = 0; i < H; i++){
			m[i][0] = m[i][W - 1] = false;
		}

		/*
		if (counter == 3){
			for (int i = 0; i < H; i++){
				for (int j = 0; j < W; j++){
					cout << m[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}
		*/
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (m[i][j]&&!black[i][j]){
					memset(white, false, sizeof(white));
					c = 0;
					dfs(i, j);
					rv.push_back(toChar[c]);
				}
			}
		}
		sort(rv.begin(), rv.end());
		cout << "Case " << counter << ": ";
		for (int i = 0; i < rv.size(); i++){
			cout << rv[i];
		}
		cout << endl;
	}
	return 0;
}
