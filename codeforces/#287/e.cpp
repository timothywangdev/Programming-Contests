#include <bits/stdc++.h>
#define mt make_tuple
#define mp make_pair

using namespace std;
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;


int n,m,u,v,k,total_non_broken=0,dist,broken_roads;
vector<PII> edge[100000];
int pre[100000],broken[100000],d[100000];
vector<TIII> roads;
bool used[100000];
map<TII,int> roads_to_idx;

void visit(int u,int v){
  if(u>v)swap(u,v);
  map<TII,int>::iterator it=roads_to_idx.find(mt(u,v));
  used[it->second]=true;
  if(get<2>(roads[it->second])==0){
    cout<<u+1<<" "<<v+1<<" 1"<<endl;
  }
}
int main(){
  memset(used,false,sizeof(used));
  memset(pre,-1,sizeof(pre));
  memset(broken,-1,sizeof(broken));
  memset(d,-1,sizeof(d));
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v>>k;
    u--;
    v--;
    edge[u].push_back(mp(v,k));
    edge[v].push_back(mp(u,k));
    roads.push_back(mt(u,v,k));
    if(u>v)swap(u,v);
    roads_to_idx[mt(u,v)]=roads.size()-1;
    if(k==1){
      total_non_broken++;
    }
  }
  queue<TIII> q;
  // v dist brokenRoads
  q.push(mt(0,0,0));
  d[0]=0;
  while(!q.empty()){
    TIII front=q.front();
    q.pop();
    u=get<0>(front);
    dist=get<1>(front);
    broken_roads=get<2>(front);
    for(int i=0;i<edge[u].size();i++){
      v=edge[u][i].first;
      k=edge[u][i].second;
      if(d[v]==-1||(d[v]==dist+1&&broken_roads+(1-k)<broken[v])){
	  d[v]=dist+1;
	  broken[v]=broken_roads+(1-k);
	  pre[v]=u;
	  q.push(mt(v,d[v],broken[v]));
      }
    }
  }
  cout<<2*broken[n-1]+total_non_broken-d[n-1]<<endl;
  v=n-1;
  while(pre[v]!=-1){
    visit(pre[v],v);
    v=pre[v];
  }
  for(int i=0;i<roads.size();i++){
  if(!used[i]&&get<2>(roads[i])==1){
     cout<<get<0>(roads[i])+1<<" "<<get<1>(roads[i])+1<<" 0"<<endl;
    }
  }
  return 0;
}
