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

class TheKingsRoadsDiv1 {
public:
   int h; 
   vector<int> a; 
   vector<int> b; 
   vector<vector<int> > edge;
   bool vis[1024];
   bool removed[1024][1024];
   int pow2[11];
   int n;
   vector<PII> rem;
   int search(int u,int depth){
      vis[u]=true;
      int ava=0;
      F(i,edge[u].size()){
	 if(!removed[u][edge[u][i]]&&!vis[edge[u][i]]){
	    ava++;
	 }
      }
      if(depth==h){
	 if(ava!=0){
	    return -1;
	 }
	 return 1;
      }
      if(ava!=2){
	 return -1;
      }
      int sum=0;
      F(i,edge[u].size()){
	 if(!removed[u][edge[u][i]]&&!vis[edge[u][i]]){
	    int k=search(edge[u][i],depth+1);
	    if(k!=pow2[h-depth]-1){
	       return -1;
	    }
	    sum+=k;
	 }
      }
      return sum+1;
   }
   bool check(){
      F(i,n){
	 int deg=0;
	 F(j,edge[i].size()){
	    deg+=!removed[i][edge[i][j]];
	 }
	 if(deg==2){
	    memset(vis,false,sizeof(vis));
	    if(search(i,1)==n){
	       return true;
	    }
	    else{
	       return false;
	    }
	 }
      }
      return false;
   }
   void d(int u,int v,bool s){
      removed[u][v]=removed[v][u]=s;
   }
   bool dfs(int start,int remain){
      if(remain==0){
	 return check();
      }
      for(int i=start;i<rem.size()-remain+1;i++){
	 d(rem[i].first,rem[i].second,true);
	 if(dfs(i+1,remain-1)){
	    return true;
	 }
	 d(rem[i].first,rem[i].second,false);
      }
      return false;
   }
   string getAnswer(int h, vector<int> a, vector<int> b) {
      memset(removed,false,sizeof(removed));
      pow2[0]=1;
      for(int i=1;i<=10;i++){
	 pow2[i]=pow2[i-1]*2;
      }
      this->h = h; 
      this->a = a; 
      this->b = b; 
      this->n=pow2[h]-1;
      int bad_edge=3;
      edge=vector<vector<int> >(a.size(),vector<int>());
      F(i,a.size()){
	 if(a[i]==b[i]){
	    bad_edge--;
	    continue;
	 }
	 bool found=false;
	 F(j,edge[a[i]-1].size()){
	    if(edge[a[i]-1][j]==b[i]-1){
	       bad_edge--;
	       found=true;
	       break;
	    }
	 }
	 if(found)continue;
	 edge[a[i]-1].pb(b[i]-1);
	 edge[b[i]-1].pb(a[i]-1);
      }
      if(bad_edge<0){
	 return "Incorrect";
      }
      queue<int> q;
      
      F(i,a.size()){
	 if(edge[i].size()==1){
	    q.push(i);
	 }
      }
      if ( (int)(q.size()) < ( (1 << (h-1)) - 6 ) ) {
        return "Incorrect";
      }
      while(q.size()){
	 int u=q.front();
	 q.pop();
	 int v=-1;
	 F(i,edge[u].size()){
	    if(!removed[u][edge[u][i]]){
	       v=edge[u][i];
	       break;
	    }
	 }
	 d(u,v,true);
	 int deg=0;
	 F(i,edge[v].size()){
	    deg+=!removed[v][edge[v][i]];
	 }
	 
	 if(deg==1&&edge[v].size()==3){
	    q.push(v);
	 }
      }
      F(u,n){
	 F(j,edge[u].size()){
	    int v=edge[u][j];
	    if(u<=v&&!removed[u][edge[u][j]]){
	       rem.pb(mp(u,v));
	    }
	 }
      }
      

     memset(removed,false,sizeof(removed));

     
     if(dfs(0,bad_edge)){
	return "Correct";
     }
     return "Incorrect";
   }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
   return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
	  // { { 3, {1,3,2,2,3,7,1,5,4}, {6,5,4,7,4,3,3,1,7} }, {"Correct"} },
	  // { { 2, {1,2,1,3,3}, {2,1,2,3,3} }, {"Incorrect"} },
	  // { { 3, {1,3,2,2,6,6,4,4,7}, {2,1,4,5,4,4,7,7,6} }, {"Incorrect"} },
	  //{ { 2, {1,2,2,1,1}, {1,2,2,1,2} }, {"Incorrect"} },
	  // { { 5, {6,15,29,28,7,13,13,23,28,13,30,27,14,4,14,19,27,20,20,19,10,15,7,7,19,29,4,24,10,23,30,6,24}, {9,22,30,20,26,25,8,7,24,21,27,31,4,28,29,6,16,1,17,10,3,12,30,18,14,23,19,21,5,13,15,2,11} }, {"Correct"} },
	  // { { 2, {1,1,1,2,1}, {2,3,1,2,2} }, {"Correct"} },
	      // Your custom test goes here:
	 //{ { , {}, {}}, {} },
	 };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
   int p0;vector<int> p1;vector<int> p2;

   string run(TheKingsRoadsDiv1* x) {
      return x->getAnswer(p0,p1,p2);
   }
   void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
   return Tester::runTests<TheKingsRoadsDiv1>(
      getTestCases<input, Tester::output<string>>(), disabledTest, 
      500, 1427825810, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
