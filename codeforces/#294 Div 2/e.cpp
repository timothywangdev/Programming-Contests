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
#define MAXN 100000
/*
  Static RMQ data structure
  Preprocessing: O(nlogn)
  Query: O(1)
*/

// Comparator
template <class T>
class Cmp{
public:
   bool operator()(const T &a, const T &b){
      return a<b;
   }
};

template <class T,class Cmp>
class SparseTable{
   vector<vector<T> > spt;
   vector<T> _data;
   Cmp cmp;
public:
   SparseTable(){}
   void build(vector<T> data){
      _data=data;
      int n=data.size();
      spt=vector<vector<T> >(n,vector<T>((int)log2((double)n)+1,0));
      for(int i=0;i<n;i++){
	 spt[i][0]=i;
      }
      for(int j=1;(1<<j)<=n;j++){
	 for(int i=0;i+(1<<j)-1<n;i++){
	    if(cmp(_data[spt[i][j-1]],_data[spt[i+(1<<(j-1))][j-1]]))
	       spt[i][j]=spt[i][j-1];
	    else
	       spt[i][j]=spt[i+(1<<(j-1))][j-1];
	 }
      }
   }
   // Returns an index of the 'minimum' element
   int query(int i,int j){
      int k=(int)floor(log((double)j-i+1)/log(2.0));
      if(!cmp(_data[spt[j-(1<<k)+1][k]],_data[spt[i][k]])){
	 return spt[i][k];
      }
      else{
	 return spt[j-(1<<k)+1][k];
      }
   }
};

/*
  Lowest Common Ancestor
  Requirement: SparseTable
  Preprocessing: O(nlogn)
  Query: O(1)
*/
class LCA{
public:
   vector<int> L;
   vector<int> E;
   vector<int> H;
   int idx;
   SparseTable<int,less<int> > st;
   LCA(int n):L(vector<int>(2*n,0)),E(vector<int>(2*n,0)),H(vector<int>(n,-1)),idx(0){}
   void dfs(int cur,int depth,int parent,vector<vector<int> > &edge){
      H[cur]=idx;
      E[idx]=cur;
      L[idx++]=depth;
      for(auto v:edge[cur]){
	 if(v!=parent){
	    dfs(v,depth+1,cur,edge);
	    E[idx]=cur;
	    L[idx++]=depth;
	 }
      }
   }
   void build(int u,vector<vector<int> > &edge){
      dfs(u,0,-1,edge);
      st.build(L);
   }
   int query(int u,int v){
      if(H[u]>H[v])swap(u,v);
      return E[st.query(H[u],H[v])];
   }
};
int n,m,a,b,maxLevel,len;
vector<vector<int> > edge;
int parent[MAXN][17];
int sz[MAXN],dep[MAXN];
void dfs(int u,int depth,int par){
   sz[u]=1;
   dep[u]=depth;
   parent[u][0]=par;
   for(auto v:edge[u]){
      if(v!=par){
	 dfs(v,depth+1,u);
	 sz[u]+=sz[v];
      }
   }
}

void binary_raise(){
   for(int j=1;(1<<j)<=n;j++){
      for(int i=0;i<n;i++){
	 parent[i][j]=parent[parent[i][j-1]][j-1];
      }
      maxLevel=j;
   }
}
int get_parent(int u,int dist){
   for(int j=maxLevel;j>=0;j--){
      if((1<<j)<=dist){
	 u=parent[u][j];
	 dist-=(1<<j);
      }
   }
   return u;
}

int main(){
   cin>>n;
   edge=vector<vector<int> >(n,vector<int>());
   memset(parent,-1,sizeof(parent));
   F(i,n-1){
      cin>>a>>b;
      a--;
      b--;
      edge[a].push_back(b);
      edge[b].push_back(a);
   }
   LCA lca(n);
   lca.build(0,edge);
   dfs(0,0,-1);
   binary_raise();
   cin>>m;
   F(i,m){
      cin>>a>>b;
      a--;
      b--;
      if(a==b){
	 cout<<n<<endl;
	 continue;
      }
      int l=lca.query(a,b);
      if(l!=a&&l!=b){
	 if(dep[a]==dep[b]){
	    cout<<sz[0]-sz[get_parent(a,dep[a]-dep[l]-1)]-sz[get_parent(b,dep[b]-dep[l]-1)]<<endl;
	 }
	 else{
	    len=dep[a]-dep[l]+dep[b]-dep[l];
	    if(len%2==1){
	       cout<<"0"<<endl;
	    }
	    else{
	       if(dep[a]>dep[b]){
		  cout<<sz[get_parent(a,len/2)]-sz[get_parent(a,(len/2)-1)]<<endl;
	       }
	       else{
		  cout<<sz[get_parent(b,len/2)]-sz[get_parent(b,(len/2)-1)]<<endl;
	       }
	    }
	 }
      }
      else{
	 if(l==a){
	    len=dep[b]-dep[a];
	    if(len%2==1){
	       cout<<"0"<<endl;
	       continue;
	    }
	    cout<<sz[get_parent(b,len/2)]-sz[get_parent(b,(len/2)-1)]<<endl;
	 }
	 else{
	    len=dep[a]-dep[b];
	    if(len%2==1){
	       cout<<"0"<<endl;
	       continue;
	    }
	    cout<<sz[get_parent(a,len/2)]-sz[get_parent(a,(len/2)-1)]<<endl;
	 }
      }
   }
   return 0;
}
