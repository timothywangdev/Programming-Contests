#include <iostream>
#include <map>
#include <cmath>
#define MAXIMUM 2147483647
using namespace std;

int T, sx, sy,x,y;
int R, C,N;

struct Node{
	int x;
	int y;
	Node(int x, int y){
		this->x = x;
		this->y = y;
	}
	Node(){}
};

map<int, Node> toNode;

int dist[10][10];

int getDist(Node &a, Node &b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}
unsigned turnOn(unsigned int n, int pos){
	return n | 1 << pos;
}
bool getBit(unsigned n, int pos){
	return ((n&(1 << pos)) != 0);
}
unsigned int power(int base, int k){
	unsigned int rv = 1;
	for (int i = 0; i<k; i++)
		rv *= base;
	return rv;
}
int tsp(){
	int t[11][2048];
	unsigned int doneMask = power(2, N+1)-1;
	for (unsigned int mask = doneMask; mask >= 1; mask--){
		for (int j = 0; j < N + 1; j++){
			if (getBit(mask, j)){
				int minimum = MAXIMUM;
				if (mask == doneMask){
					t[j][mask] = dist[j][0];
					continue;
				}
				for (int k = 0; k<N + 1; k++){
					if (!getBit(mask, k)){
						if (minimum>dist[j][k] + t[k][turnOn(mask, k)]){
							minimum = dist[j][k] + t[k][turnOn(mask, k)];
						}
					}
				}
				t[j][mask] = minimum;
			}
		}
	}
	return t[0][turnOn(0, 0)];
}
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> R >> C >> sx >> sy;
		cin >> N;
		toNode[0] = Node(sx, sy);
		for (int i = 1; i <= N; i++){
			cin >> x >> y;
			toNode[i] = Node(x, y);
		}
		for (int i = 0; i < N+1; i++){
			for (int j = 0; j < N+1; j++){
				dist[i][j] = getDist(toNode[i], toNode[j]);
			}
		}
		cout << "The shortest path has length "<<tsp() << endl;
	}
	return 0;
}