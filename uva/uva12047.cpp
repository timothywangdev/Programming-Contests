#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <string.h>
#define INF 2147483647
using namespace std;
typedef vector<long long> vi;
typedef pair<long long, int> ii;
int N, M, s, t, T,a, b;
long long c, P;
vi dist[2];
vector<vector<ii> > edge[2];
void Dijkstra(int s, int t, vector<vector<ii> > &edge, vi &dist){
	priority_queue<ii, vector<ii>, greater<ii> >pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while (pq.size()){
		ii front = pq.top();
		pq.pop();
		long long u = front.second;
		long long d = front.first;
		if (dist[u] < d)continue;
		for (int i = 0; i < edge[u].size(); i++){
			ii v = edge[u][i];
			if (dist[v.second]>d + v.first){
				dist[v.second] = d + v.first;
				pq.push(ii(dist[v.second], v.second));
			}
		}
	}
}
int main(){
	cin >> T;
	for (int tt = 0; tt < T; tt++){
		cin >> N >> M >> s >> t >> P;
		s--; t--;
		edge[0] = vector<vector<ii> >(N, vector<ii>());
		edge[1] = vector<vector<ii> >(N, vector<ii>());
		dist[0] = vi(N, INF);
		dist[1] = vi(N, INF);
		for (int i = 0; i < M; i++){
			cin >> a >> b >> c;
			a--;
			b--;
			edge[0][a].push_back(make_pair(c, b));
			edge[1][b].push_back(make_pair(c, a));
		}

		Dijkstra(s, t, edge[0], dist[0]);
		Dijkstra(t, s, edge[1], dist[1]);
		long long maximum = -1;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < edge[0][i].size(); j++){
				long long k = dist[0][i] + dist[1][edge[0][i][j].second] + edge[0][i][j].first;
				if (k <= P&&edge[0][i][j].first>maximum){
					maximum = edge[0][i][j].first;
				}
			}
		}
		cout << maximum << endl;
	}
	return 0;
}