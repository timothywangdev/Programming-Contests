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

int n,a[100001];
bool vis[100001];
vector<vector<int> > cycles;
vector<int> tmp;
void search(int i){
   vis[i]=true;
   tmp.pb(i);
   if(!vis[a[i]]){
      search(a[i]);
   }
   else{
      cycles.pb(tmp);
      tmp.clear();
   }
}
int main(){
   memset(vis,false,sizeof(vis));
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      if(!vis[i])search(i);
   }
   F(i,cycles.size()){
      if(cycles[i].size()==1){
	 cout<<"YES"<<endl;
	 for(int j=1;j<=n;j++){
	    if(j!=cycles[i][0]){
	       cout<<cycles[i][0]<<" "<<j<<endl;
	    }
	 }
	 return 0;
      }
   }
   int idx=-1;
   F(i,cycles.size()){
      if(cycles[i].size()%2==1){
	 cout<<"NO"<<endl;
	 return 0;
      }
      if(cycles[i].size()==2){
	 idx=i;
      }
   }
   if(idx==-1){
      cout<<"NO"<<endl;
   }
   else{
      tmp=cycles[idx];
      cout<<"YES"<<endl;
      cout<<tmp[0]<<" "<<tmp[1]<<endl;
      F(j,cycles.size()){
	 if(j!=idx){
	    vector<int> t=cycles[j];
	    F(k,t.size()){
	       if(k%2==0){
		  cout<<tmp[0]<<" "<<t[k]<<endl;
	       }
	       else{
		  cout<<tmp[1]<<" "<<t[k]<<endl;
	       }
	    }
	 }
      }
   }
   return 0;
}
