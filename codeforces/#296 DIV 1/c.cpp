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

void getTour(int u,vector<vector<int> > &edge,vector<PII> &edge_list,
 vector<int> &cyc){
   while(edge[u].size()){
      int k=edge[u][edge[u].size()-1];
      edge[u].pop_back();
      if(edge_list[k].first==-1)continue;
      int v=(edge_list[k].first==u)?edge_list[k].second:edge_list[k].first;
      edge_list[k].first=edge_list[k].second=-1;
      getTour(v,edge,edge_list,cyc);
      cyc.pb(u);
   }
}
vector<int> EulerTour(vector<vector<int> > &edge,vector<PII> edge_list){
   vector<int> cyc;
   getTour(0,edge,edge_list,cyc);
   //for(auto i:cyc){
   //    cout<<i<<" ";
   // }
   //cout<<endl;
   return cyc;
}

int n,m;
int a,b;
int num_edges=0;
vector<PII> edge_list;
vector<vector<int> > edge;
int main(){
   //cin>>n>>m;
   scanf("%d%d",&n,&m);
   edge=vector<vector<int> >(n,vector<int>());
   F(i,m){
      // cin>>a>>b;
      scanf("%d%d",&a,&b);
      a--;b--;
      edge[a].push_back(edge_list.size());
      edge[b].push_back(edge_list.size());
      edge_list.pb(mp(a,b));
   }
   vector<int> odd_vertices;
   F(i,n){      
      if(edge[i].size()%2){
	 odd_vertices.pb(i);
      }
   }
   for(int i=1;i<(int)odd_vertices.size();i+=2){
      edge[odd_vertices[i]].push_back(edge_list.size());
      edge[odd_vertices[i-1]].push_back(edge_list.size());
      edge_list.pb(mp(odd_vertices[i],odd_vertices[i-1]));
   }

   vector<int> c=EulerTour(edge,edge_list);
   if(edge_list.size()%2==1){
      c.pb(0);
   }
   vector<PII> rv;
   for(int i=0;i<(int)c.size();i++){
      if(i%2==0){
	 rv.pb(mp(c[i],c[(i+1)%c.size()]));
      }
      else{
	 rv.pb(mp(c[(i+1)%c.size()],c[i]));
      }
   }
   //cout<<rv.size()<<endl;
   printf("%d\n",(int)rv.size());
   for(auto i:rv){
      //cout<<i.first+1<<" "<<i.second+1<<endl;
      printf("%d %d\n",i.first+1,i.second+1);
   }
   return 0;
}
