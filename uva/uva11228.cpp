#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#define MAXIMUM 100000000000
using namespace std;
#include <fstream>
#include <cmath>
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
class Cor{
public:
	int x;
	int y;
	Cor(int x, int y) :x(x), y(y){}
	Cor(){}
};
class Node{
public:
	double w;
	int id;
	Node(double w, int id) :w(w), id(id){}
};
Cor cors[1000];
bool used[1000];
double m[1000][1000];
int T, N, R, x, y, states;
double roadL, railL;
struct MyCmp{
	bool operator()(const Node &a, const Node &b){
		if (a.w > b.w){
			return true;
		}
		else if (a.w == b.w){
			return a.id < b.id;
		}
		return false;
	}
};

priority_queue<Node, vector<Node>, MyCmp> pq;
void addW(double w){
	if (w <= (double)R){
		roadL += w;
	}
	else{
		railL += w;
	}
}
void process(int index){
	used[index] = true;
	for (int i = 0; i < N; i++){
		if (m[index][i] != MAXIMUM&&!used[i]){
			pq.push(Node(m[index][i], i));
		}
	}
}
void MST(){
	memset(used, false, sizeof(used));
	process(0);
	while (!pq.empty()){
		Node node = pq.top();
		pq.pop();
		if (!used[node.id]){
			addW(node.w);
			process(node.id);
		}
	}
}
double getDist(int i, int j){
	return sqrt((double)((cors[i].x - cors[j].x)*(cors[i].x - cors[j].x) + (cors[i].y - cors[j].y)*(cors[i].y - cors[j].y)));
}
void dfs(int index){
	used[index] = true;
	for (int i = 0; i < N; i++){
		if (m[index][i] != MAXIMUM&&m[index][i]<=R&&!used[i]){
			dfs(i);
		}
	}
}
int rr(double num){
	if ((num + 0.5) >= (int(num) + 1))
		return int(num) + 1;
	else
		return int(num);
}
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N >> R;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				m[i][j] = MAXIMUM;
			}
		}
		roadL = railL = 0;
		for (int i = 0; i < N; i++){
			cin >> x >> y;
			cors[i].x = x;
			cors[i].y = y;
		}
		for (int i = 0; i < N-1; i++){
			for (int j = i+1; j < N; j++){
				m[i][j] = getDist(i, j);
				m[j][i] = m[i][j];
			}
		}
		MST();
		memset(used, false, sizeof(used));
		states=0;
		for (int i = 0; i < N; i++){
			if (!used[i]){
				dfs(i);
				states++;
			}
		}
		cout << "Case #" << t + 1 << ": " << states << " " << rr(roadL) << " " << rr(railL) << endl;
	}
	return 0;
}