#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <algorithm>
#define INF 842150450
using namespace std;

bool m[1000][1000];
int dist[1000][1000];
int mo[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int R, C, N, r, c,n,sr,sc,dr,dc;
string s;
class Point{
public:
	int r;
	int c;
	Point(int r, int c) :r(r), c(c){}
};
queue<Point> q;
bool inRange(int r, int c){
	return 0 <= r&&r < R && 0 <= c&&c < C;
}
void bfs(int sr, int sc, int dr, int dc){
	while (q.size()){
		q.pop();
	}
	q.push(Point(sr, sc));
	dist[sr][sc] = 0;
	bool finished = false;
	while (q.size()&&!finished){
		Point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int r = p.r + mo[i][0];
			int c = p.c + mo[i][1];
			if (inRange(r, c) && dist[r][c]==INF && !m[r][c]){
				dist[r][c] = min(dist[r][c], dist[p.r][p.c] + 1);
				q.push(Point(r, c));
				if (r == dr&&c == dc){
					finished = true;
				}
			}
		}
	}
}
void process(string s){
	int r,c;
	istringstream iss(s);
	iss >> r;
	iss >> c;
	while (iss >> c){
		m[r][c] = true;
	}
}
int main(){
	while (cin >> R >> C){
		if (!R&&!C){
			break;
		}
		cin >> N;
		memset(dist, 50, sizeof(dist));
		memset(m, false, sizeof(m));
		getline(cin, s);
		for (int i = 0; i < N; i++){
			getline(cin, s);
			process(s);
		}
		cin >> sr >> sc >> dr >> dc;
		bfs(sr, sc, dr, dc);
		cout << dist[dr][dc] << endl;
	}
	return 0;
}