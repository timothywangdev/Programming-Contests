#include <bits/stdc++.h>

using namespace std;

int n,m,u,v,c;
vector<int> g[100][100];
bool reach[100][100][100];
bool vis[100];
int from;
void search(int c,int u){
  vis[u]=reach[c][from][u]=true;
  for(int i=0;i<g[c][u].size();i++){
    int v=g[c][u][i];
    if(!vis[v]){
      search(c,v);
    }
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v>>c;
    u--;
    v--;
    c--;
    g[c][u].push_back(v);
    g[c][v].push_back(u);
  }
  memset(reach,false,sizeof(reach));
  for(c=0;c<m;c++){
    for(int i=0;i<n;i++){
      memset(vis,false,sizeof(vis));
      from=i;
      search(c,i);
    }
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>u>>v;
    u--;v--;
    int sum=0;
    for(int j=0;j<m;j++){
      if(reach[j][u][v]){
	sum++;
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
