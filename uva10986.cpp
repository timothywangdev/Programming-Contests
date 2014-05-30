#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
#define INF 842150450
using namespace std;
int P, N, M, S,T,a,b,w;
class ii{
public:
	int a;
	int b;
	ii(int a, int b) :a(a), b(b){}
};
vector<ii> edges[20000];
int dist[20000];
struct compare{
	int operator()(const ii &a, const ii &b){
		if (a.a > b.a){
			return true;
		}
		else if(a.a==b.a){
			return a.b > b.b;
		}
		return false;
	}
};
priority_queue<ii, vector<ii>, compare> pq;
int main(){
	cin >> P;
	for (int t = 0; t < P; t++){
		cin >> N >> M >> S >> T;
		memset(dist, 50, sizeof(dist));
		while (pq.size()){
			pq.pop();
		}
		for (int i = 0; i < N; i++){
			edges[i].clear();
		}
		for (int j = 0; j < M; j++){
			cin >> a >> b >> w;
			edges[a].push_back(ii(b, w));
			edges[b].push_back(ii(a, w));
		}
		dist[S] = 0;
		pq.push(ii(S, 0));
		while (!pq.empty()){
			ii v = pq.top();
			pq.pop();
			if (dist[v.a] < v.b) continue;
			for (int i = 0; i < edges[v.a].size(); i++){
				ii v1 = edges[v.a][i];
				if (dist[v1.a]>dist[v.a] + v1.b){
					dist[v1.a]=dist[v.a] + v1.b;
					pq.push(ii(v1.a,dist[v1.a]));
				}
			}
		}
		cout << "Case #" << t + 1 << ": ";
		if (dist[T] == INF){
			cout << "unreachable" << endl;
		}
		else{
			cout << dist[T] << endl;
		}
	}
	return 0;
}