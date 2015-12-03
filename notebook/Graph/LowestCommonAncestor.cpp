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

/* 
 Binary Raise Method
*/

// largest 2^LG will be used
#define LG 32 

// parent, depth
// par[u][k] 2^k th parent of u
// par[u][0] = parent of u
int par[100000][31],d[100000];
// path computation
// r[u][k] means path from u to *before* u's 2^k parent
// r[u][0] = some info of node u
vector<int> r[100000][31]

// Contructs parents first
void dfs(int u,int p, int depth){
   d[u]=depth;
   par[u][0]=p;

   /*
     path computation

   r[u][0]=c[u];
   */

   for(int i=1;i<=LG-1;i++){
      par[u][i]=par[par[u][i-1]][i-1];
      /*
      	additional stuff if you want to do some calculations on the path

      if((1<<i)<=depth+1)
	 r[u][i]=merge(r[u][i-1],r[par[u][i-1]][i-1]);
      */
   }
   F(i,edge[u].size()){
      int v=edge[u][i];
      if(v!=p){
	 dfs(v,u,depth+1);
      }
   }
}

// get u's kth parent
int get_par(int u,int k){
   for(int i=LG-1;i>=0;i--){
      if(k&(1<<i)){
	 u=par[u][i];
      }
   }
   return u;
}

// additional function to do some calculations on the path from u to u's 2^k parent
// usually we par[u][k] and par[v][k']is lca of (u,v), and then we merge(get(u,k),get(v,k'))
vector<int> get(int u, int k){
   vector<int> rv;
   for(int i=LG-1;i>=0;i--){
      if(k&(1<<i)){
	 rv=merge(rv,r[u][i]);
	 u=par[u][i];
      }
   }
   return rv;
}

// Call this to contruct parents first
dfs(0,0,0);

int lca(int u,int v){
   // d[u] is the depth of u
   if(d[u]>d[v])swap(u,v);
   v=get_par(v,d[v]-d[u]);
   if(u==v)return v;
   for(int i=LG-1;i>=0;i--){
      if(par[u][i]!=par[v][i]){
	 u=par[u][i];
	 v=par[v][i];
      }
   }
   return par[u][0];
}

// path computation usage:
// you may want to consider whether one is the parent of the other

int p=lca(u,v);
vector<int> rv;
//                        +1 means we include the lca it self
rv=merge(get(u,d[u]-d[p]),get(v,d[v]-d[p]+1));
