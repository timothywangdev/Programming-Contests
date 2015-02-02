#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

vector<int> G[MAXN];
vector<int> undirected_G[MAXN];
bool undirected_vis[MAXN];
vector<int> vs;
vector<vector<int> > scc;
int n,m,counter,u,v,sum;

void dfs(int u){
  undirected_vis[u]=true;
  vs.push_back(u);
  for(int i=0;i<undirected_G[u].size();i++){
    int v=undirected_G[u][i];
    if(!undirected_vis[v]){
      dfs(v);
    }
  }
}

int dfs_low[MAXN],dfs_num[MAXN],dfsNumberCounter;
bool visited[MAXN];
stack<int> S;
void tarjanSCC(int u){
  dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
  S.push(u);
  visited[u]=true;
  for(int j=0;j<(int)G[u].size();j++){
    int v=G[u][j];
    if(dfs_num[v]==0){
      tarjanSCC(v);
    }
    if(visited[v]){
      dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
  }
  if(dfs_low[u]==dfs_num[u]){
    vector<int> new_scc;
    while(true){
      int v=S.top();
      S.pop();
      visited[v]=false;
      new_scc.push_back(v);
      if(u==v)break;
    }
    scc.push_back(new_scc);
  }
}

bool cycle(){
  scc.clear();
  dfsNumberCounter=1;
  for(int i=0;i<vs.size();i++){
    if(dfs_num[vs[i]]==0){
      tarjanSCC(vs[i]);
    }
  }
  for(int i=0;i<scc.size();i++){
    if(scc[i].size()>=2){
      return true;
    }
  }
  return false;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v;
    undirected_G[u-1].push_back(v-1);
    undirected_G[v-1].push_back(u-1);
    G[u-1].push_back(v-1);
  }
  memset(undirected_vis,false,sizeof(undirected_vis));
  memset(dfs_num,0,sizeof(dfs_num));
  memset(dfs_low,0,sizeof(dfs_low));
  memset(visited,false,sizeof(visited));
  sum=0;
  for(int i=0;i<n;i++){
    if(!undirected_vis[i]){
      dfs(i);
      if(cycle()){
	sum+=vs.size();
      }
      else{
	sum+=vs.size()-1;
      }
    }
    vs.clear();
  }
  cout<<sum<<endl;
  return 0;
}
