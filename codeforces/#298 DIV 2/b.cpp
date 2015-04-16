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

int s,e;
int t,d;
int f[101][2001];
int INF=2147483647;
int main(){
   cin>>s>>e>>t>>d;
   F(i,101){
      F(j,2001){
	 f[i][j]=-INF;
      }
   }
   f[1][s]=s;
   for(int i=2;i<=t;i++){
      for(int j=0;j<=2000;j++){
	 for(int k=0;k<=d;k++){
	    if(j+k<=2000&&f[i-1][j]!=-INF){
	       f[i][j+k]=max(f[i][j+k],f[i-1][j]+j+k);
	    }
	    if(j-k>=0&&f[i-1][j]!=-INF){
	       f[i][j-k]=max(f[i][j-k],f[i-1][j]+j-k);
	    }
	 }
      }
   }
   cout<<f[t][e]<<endl;
   return 0;
}
