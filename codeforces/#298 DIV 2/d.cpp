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

vector<int> c[200001];
int n,t;
int main(){
   cin>>n;
   memset(c,0,sizeof(c));
   F(i,n){
      cin>>t;
      c[t].pb(i+1);
   }
   int counter=0;
   int cur=0;
   vector<int> rv;
   while(true){
      while(c[cur].size()){
	 rv.pb(c[cur].back());
	 c[cur].pop_back();
	 counter++;
	 cur++;
      }
      while(cur>=0&&!c[cur].size()){
	 cur-=3;
      }
      if(cur<0)break;
   }
   if(counter==n){
      cout<<"Possible"<<endl;
      F(i,rv.size()){
	 cout<<rv[i]<<" ";
      }
   }
   else{
      cout<<"Impossible"<<endl;
   }
   return 0;
}
