#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <string>
#define MAXIMUM -1
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
int m[100][100];
bool mst[100][100];
bool used[100];
int C, S, Q,a,b,d,counter=0;
class Node{
public:
	int w;
	int id;
	int pre;
	Node(int w, int id,int pre) :w(w), id(id),pre(pre){}
};
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

void process(int index){
	used[index] = true;
	for (int i = 0; i < C; i++){
		if (m[index][i] != MAXIMUM&&!used[i]){
			pq.push(Node(m[index][i], i,index));
		}
	}
}
void Prim(int index){
	process(index);
	while (!pq.empty()){
		Node node = pq.top();
		pq.pop();
		if (!used[node.id]){
			mst[node.pre][node.id] = mst[node.id][node.pre] = true;
			process(node.id);
		}
	}
}
int getMinMax(int current, int dest,int maximum){
	used[current] = true;
	if (current == dest){
		return maximum;
	}
	bool found = false;
	for (int i = 0; i < C; i++){
		if (mst[current][i]&&!used[i]){
			int k = getMinMax(i, dest, max(maximum, m[current][i]));
			if (k == -1){
				continue;
			}
			maximum = max(maximum, k);
			found = true;
		}
	}
	if (!found){
		return -1;
	}
	return maximum;
}
int main(){
	redirect();
	while (cin >> C >> S >> Q){
		if (!C&&!S &&!Q){
			break;
		}
		if (counter > 0){
			cout << endl;
		}
		counter++;
		cout << "Case #" << counter << endl;
		memset(m, -1, sizeof(m));
		memset(mst, false, sizeof(mst));
		for (int i = 0; i < S; i++){
			cin >> a >> b >> d;
			a--;
			b--;
			m[a][b] = m[b][a] = d;
		}
		memset(used, false, sizeof(used));
		for (int i = 0; i < C; i++){
			if (!used[i]){
				Prim(i);
			}
		}
		
		for (int i = 0; i < Q; i++){
			cin >> a >> b;
			a--;
			b--;
			memset(used, false, sizeof(used));
			int k = getMinMax(a, b, 0);
			if (k != -1){
				cout << k  << endl;
			}
			else{
				cout << "no path" << endl;
			}
		}
	}
	return 0;
}