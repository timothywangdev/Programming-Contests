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
