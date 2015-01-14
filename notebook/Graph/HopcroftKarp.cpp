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
