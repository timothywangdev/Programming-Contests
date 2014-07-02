#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int T,N,x,y,c,total;
int cor[100][4];
double D;
bool inRange(int i,int j){
  double a=cor[i][0]-cor[j][0];
  double b=cor[i][1]-cor[j][1];
  return sqrt(a*a+b*b)<=D;
}

bool check(int dest){
PushRelabel mf(N*2+1);
 for(int i=0;i<N;i++){
   if(i!=dest){
      mf.AddEdge(2*i,2*i+1,cor[i][3]);
   }
   mf.AddEdge(2*N,2*i,cor[i][2]);
 }
 for(int i=0;i<N;i++){
   for(int j=0;j<N;j++){
     if(i!=j&&inRange(i,j)){
       mf.AddEdge(2*i+1,2*j,1000);
     }
   }
 }
 return mf.GetMaxFlow(2*N,2*dest)==total;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N>>D;
    total=0;
    for(int i=0;i<N;i++){
      cin>>cor[i][0]>>cor[i][1]>>cor[i][2]>>cor[i][3];
      total+=cor[i][2];
    }
    bool found=false;
    for(int i=0;i<N;i++){
      if(check(i)){
	if(found)cout<<" ";
	found=true;
	cout<<i;
      }

    }
    if(!found)cout<<"-1"<<endl;
    else cout<<endl;
  }
  return 0;

}
