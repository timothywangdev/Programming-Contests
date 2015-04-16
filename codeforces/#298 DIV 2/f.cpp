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

bool getBit(int n,int pos){
	return (n&(1 << pos)) != 0;
}

int n,m;
int row[6];
int col[21];
bool found=false;

vector<int> state[4];
vector<int> cur,rv;
map<vector<int>,bool> vis[21][32];
void search(int c,int current, vector<int> r_count){
   if(found)return;
   if(vis[c][current].count(r_count))return;
   vis[c][current][r_count]=true;
   if(c==m){
      F(i,n){
	 if(r_count[i]!=row[i+1])return;
      }
      found=true;
      cur.pb(current);
      rv=cur;
      return;
   }
   F(i,n){
      if(r_count[i]>row[i+1])return;
      int k=(m-c)%2==0?(m-c)/2:(m-c)/2+1;
      if(r_count[i]+k<row[i+1])return;
   }
   cur.pb(current);
   vector<int> ne_r_count=vector<int>(n,0);
   F(i,state[col[c+1]].size()){
      int t=state[col[c+1]][i];
      F(j,n){
	 if(!getBit(current,j)&&getBit(t,j)){
	    ne_r_count[j]=r_count[j]+1;
	 }
	 else{
	    ne_r_count[j]=r_count[j];
	 }
      }
      search(c+1,t,ne_r_count);
   }
   cur.pop_back();
}
int main(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>row[i];
   }
   for(int i=1;i<=m;i++){
      cin>>col[i];
   }
   F(i,1<<n){
      bool first=true;
      int counter=0;
      F(j,n){
	 if(getBit(i,j)){
	    if(first){
	       first=false;
	       counter++;
	    }
	    else{
	       if(!getBit(i,j-1)){
		  counter++;
	       }
	    }
	 }
      }
      state[counter].pb(i);
   }

   search(0,0,vector<int>(n,0));

   F(i,n){
      F(j,m){
	 if(getBit(rv[j+1],i)){
	    cout<<"*";
	 }
	 else{
	    cout<<".";
	 }
      }
      cout<<endl;
   }
   return 0;
}
