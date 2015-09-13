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

int n,m,a,b,c;
int color[100001];
bool vis[100001];
vector<pair<int,int> > edge[100001];
vector<int> t;
LL rv=1;
LL MOD=1000000007;
void search(int v,int col){
  vis[v]=true;
  if(color[v]!=-1){
    if(color[v]!=col){
      rv=0;
    }
  }
  else{
    color[v]=col;
  }
  F(i,edge[v].size()){
    int u=edge[v][i].first;
    int u_col=edge[v][i].second;
    if(vis[u]){
      if(u_col){
	if(color[v]!=color[u])rv=0;
      }
      if(!u_col){
	if(color[v]==color[u])rv=0;
      }
    }
    else{
      search(u,u_col?color[v]:1-color[v]);
    }
  }
}
int main(){
  memset(vis,false,sizeof(vis));
  memset(color,-1,sizeof(color));
  cin>>n>>m;
  F(i,m){
    cin>>a>>b>>c;
    if(a==1){
      color[b]=c;
      t.pb(b);
    }
    else if(b==1){
      color[a]=c;
      t.pb(a);
    }
    else{
      edge[a].pb(mp(b,c));
      edge[b].pb(mp(a,c));
    }
  }
  F(k,t.size()){
    int i=t[k];
    if(!vis[i]){
      search(i,color[i]!=-1?color[i]:0);
    }
  }
  for(int i=2;i<=n;i++){
    if(!vis[i]){
      if(color[i]==-1)
	rv=(rv*2)%MOD;
      search(i,color[i]!=-1?color[i]:0);
    }
  }
  cout<<rv<<endl;
   return 0;
}
