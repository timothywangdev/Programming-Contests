#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
//
// Running time:
//     O(|V|^3)
//
// INPUT: 
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).
//
// Residual Graph: e.flow!=e.cap
struct Edge {
   int from, to, cap, flow, index;
   Edge(int from, int to, int cap, int flow, int index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct MaxFlow {
   int N;
   vector<vector<Edge> > G;
   vector<LL> excess;
   vector<int> dist, active, count;
   queue<int> Q;

   MaxFlow(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

   void add_edge(int from, int to, int cap) {
      G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
      if (from == to) G[from].back().index++;
      G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
   }

   void enqueue(int v) { 
      if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
   }

   void push(Edge &e) {
      int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
      if (dist[e.from] <= dist[e.to] || amt == 0) return;
      e.flow += amt;
      G[e.to][e.index].flow -= amt;
      excess[e.to] += amt;    
      excess[e.from] -= amt;
      enqueue(e.to);
   }
  
   void gap(int k) {
      for (int v = 0; v < N; v++) {
	 if (dist[v] < k) continue;
	 count[dist[v]]--;
	 dist[v] = max(dist[v], N+1);
	 count[dist[v]]++;
	 enqueue(v);
      }
   }

   void relabel(int v) {
      count[dist[v]]--;
      dist[v] = 2*N;
      for (int i = 0; i < G[v].size(); i++) 
	 if (G[v][i].cap - G[v][i].flow > 0)
	    dist[v] = min(dist[v], dist[G[v][i].to] + 1);
      count[dist[v]]++;
      enqueue(v);
   }

   void discharge(int v) {
      for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) push(G[v][i]);
      if (excess[v] > 0) {
	 if (count[dist[v]] == 1) 
	    gap(dist[v]); 
	 else
	    relabel(v);
      }
   }

   LL get_max_flow(int s, int t) {
      count[0] = N-1;
      count[N] = 1;
      dist[s] = N;
      active[s] = active[t] = true;
      for (int i = 0; i < G[s].size(); i++) {
	 excess[s] += G[s][i].cap;
	 push(G[s][i]);
      }
    
      while (!Q.empty()) {
	 int v = Q.front();
	 Q.pop();
	 active[v] = false;
	 discharge(v);
      }
    
      LL totflow = 0;
      for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
      return totflow;
   }

   void dfs_residual(int u,vector<int> &min_cut,vector<bool> &vis){
      min_cut.push_back(u);
      vis[u]=true;
      for(auto e:G[u]){
	 if((e.flow!=e.cap)&&!vis[e.to]){
	    dfs_residual(e.to,min_cut,vis);
	 }
      }
   }
   /*
     Return the partition that contains s (a.k.a source)
   */
   vector<int> get_min_cut_partition(int s){
      vector<int> min_cut;
      vector<bool> vis(N,false);
      dfs_residual(s,min_cut,vis);
      return min_cut;
   }
};
