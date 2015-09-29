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

int n;
int x,y;
vector<pair<int,PII> > rec[1001];
bool cmp(const pair<int,PII> &a, const pair<int,PII> &b){
   return a.second.second<b.second.second;
}
int main(){
   scanf("%d",&n);
   F(i,n){
      scanf("%d%d",&x,&y);
      rec[x/1000].pb(mp(i+1,mp(x,y)));
   }
   F(i,1001){
      if(rec[i].size()>0){
	 sort(rec[i].begin(),rec[i].end(),cmp);
	 if(i%2==0){
	    F(j,rec[i].size()){
	       printf("%d ",rec[i][j].first);
	    }
	 }
	 else{
	    FR(j,rec[i].size()){
	       printf("%d ",rec[i][j].first);
	    }
	 }
      }
   }
   return 0;
}
