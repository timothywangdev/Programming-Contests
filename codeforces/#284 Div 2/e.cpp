
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#define INF 2147483647
using namespace std;
typedef long long LL;
class HopcroftKarp{
	vector<int> match;
	vector<int> dist;
	vector<vector<int> > adjEdge;
	vector<bool> leftPart;
	queue<int> Q;
	void clear(queue<int> &q)
	{
		queue<int> empty;
		swap(q, empty);
	}
	bool bfs() {
		int i, u, v;
		clear(Q);
		for (i = 1; i < adjEdge.size(); i++) {
			if (leftPart[i]){
				if (match[i] == 0) {
					dist[i] = 0;
					Q.push(i);
				}
				else dist[i] = INF;
			}
		}
		dist[0] = INF;
		while (!Q.empty()) {
			u = Q.front(); Q.pop();
			if (u != 0) {
				for (i = 0; i<adjEdge[u].size(); i++) {
					v = adjEdge[u][i];
					if (dist[match[v]] == INF) {
						dist[match[v]] = dist[u] + 1;
						Q.push(match[v]);
					}
				}
			}
		}
		return (dist[0] != INF);
	}
	bool dfs(int u) {
		int i, v;
		if (u != 0) {
			for (i = 0; i<adjEdge[u].size(); i++) {
				v = adjEdge[u][i];
				if (dist[match[v]] == dist[u] + 1) {
					if (dfs(match[v])) {
						match[v] = u;
						match[u] = v;
						return true;
					}
				}
			}
			dist[u] = INF;
			return false;
		}
		return true;
	}
public:
	// Reservers 0-index for leftPart and adjEdge
	HopcroftKarp(vector<vector<int> > adjEdge, vector<bool> leftPart) :adjEdge(adjEdge), leftPart(leftPart){
		match = vector<int>(adjEdge.size(), 0);
		dist = vector<int>(adjEdge.size(), INF);
	}
	int MCBM(){
		int matching = 0, i;
		// match[] is assumed NIL for all vertex in G
		while (bfs())
			for (i = 1; i < adjEdge.size(); i++)
				if (leftPart[i] && match[i] == 0 && dfs(i))
					matching++;
		return matching;
	}

};

int a[101], p, q;
vector<int> group[101];
vector<int> fa[101];
vector<vector<int> > adjEdge;
vector<bool> leftPart;
vector<int> primes;
int n, m;
bitset<40002> bs;
void sieve(LL upperbound){
	int _sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (LL i = 2; i <= _sieve_size; i++){
		if (bs[i]){
			for (LL j = i*i; j <= _sieve_size; j += i){
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

vector<int> factors(int n){
	vector<int> rv;
	for (int i = 0; i<primes.size(); i++){
		while (n%primes[i] == 0){
			n /= primes[i];
			rv.push_back(primes[i]);
		}
		if (n == 1)break;
	}
	if(rv.size()==0){
	  rv.push_back(n);
	}
	return rv;
}
int main(){
	sieve(40000);
	adjEdge.push_back(vector<int>());
	leftPart.push_back(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		vector<int> f = factors(a[i]);
		for (int j = 0; j<f.size(); j++){
			group[i].push_back(adjEdge.size());
			fa[i].push_back(f[j]);
			adjEdge.push_back(vector<int>());
			if (i % 2 == 1){
				leftPart.push_back(true);
			}
			else{
				leftPart.push_back(false);
			}
		}
	}
	for (int i = 0; i<m; i++){
		cin >> p >> q;
		for (int j = 0; j<group[p].size(); j++){
			for (int k = 0; k<group[q].size(); k++){
				if (fa[p][j] == fa[q][k]){
					adjEdge[group[p][j]].push_back(group[q][k]);
					adjEdge[group[q][k]].push_back(group[p][j]);
				}
			}
		}
	}
	HopcroftKarp hk(adjEdge, leftPart);
	cout << hk.MCBM() << endl;
	return 0;
}
