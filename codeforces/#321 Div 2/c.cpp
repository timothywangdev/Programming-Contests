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

int n,m,x,y,rv=0;
bool cat[100001];
vector<int> edge[100001];
bool vis[100001];
void dfs(int u,int c){
   if(!cat[u])c=0;
   c+=cat[u];
   vis[u]=true;
   if(c>m)return;
   if(edge[u].size()==1&&vis[edge[u][0]]){
      rv++;
      return;
   }
   F(i,edge[u].size()){
      int v=edge[u][i];
      if(!vis[v]){
	 dfs(v,c);
      }
   }
}
int main(){
   memset(vis,false,sizeof(vis));
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>cat[i];
   }
   F(i,n-1){
      cin>>x>>y;
      edge[x].pb(y);
      edge[y].pb(x);
   }
   dfs(1,0);
   cout<<rv<<endl;
   return 0;
}
