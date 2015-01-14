#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#define INF 842150450

using namespace std;

int dist[50][50],N,M;
int nodeCount;
string a, b;
map<string, int> toID;
map<string, int>::iterator it;
int counter = 0;
void add(string s){
	it = toID.find(s);
	if (it == toID.end()){
		toID[s] = nodeCount;
		nodeCount++;
	}
}
int main(){
	while (cin >> N >> M){
		if (!N&&!M){
			break;
		}
		toID.clear();
		nodeCount = 0;
		counter++;
		memset(dist, 50, sizeof(dist));
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			add(a);
			add(b);
			dist[toID[a]][toID[b]] = dist[toID[b]][toID[a]] = 1;
		}
		for (int k = 0; k < N; k++){
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		bool disconnected = false;
		int maximum = -1;
		for (int i = 0; i < N&&!disconnected; i++){
			for (int j = 0; j < N&&!disconnected; j++){
				if (i != j){
					if (dist[i][j] == INF){
						disconnected = true;
						break;
					}
					maximum = max(maximum, dist[i][j]);
				}
			}
		}
		cout << "Network " << counter << ": ";
		if (!disconnected){
			 cout<< maximum << endl << endl;
		}
		else{
			cout << "DISCONNECTED" << endl << endl;
		}
	}
	return 0;
}