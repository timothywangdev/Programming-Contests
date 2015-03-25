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
#define MOD 1000000007
int s[100001];
int n;
int c[4];
LL f[100001][4],cc[100001][4];
char ch;
int main(){
   memset(c,0,sizeof(c));
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>ch;
      if(ch=='A'){
	 s[i]=0;
      }
      else if(ch=='C'){
	 s[i]=1;
      }
      else if(ch=='G'){
	 s[i]=2;
      }
      else{
	 s[i]=3;
      }
      c[s[i]]++;
   }
   memset(f,0,sizeof(0));
   memset(cc,0,sizeof(0));
   F(j,4){
      cc[0][j]=1;
   }
   for(int i=1;i<=n;i++){
      F(j,4){
	 if(i==1){
	    cc[i][j]=1;
	    f[i][j]=c[j];
	    continue;
	 }
	 F(k,4){
	    if(f[i-1][k]+c[j]==f[i][j]){
	       cc[i][j]=(cc[i][j]+cc[i-1][k])%MOD;
	    }
	    else if(f[i-1][k]+c[j]>f[i][j]){
	       cc[i][j]=cc[i-1][k];
	       f[i][j]=f[i-1][k]+c[j];
	    }
	 }
      }
   }
   LL maximum=0,ccc=0;
   F(j,4){
      if(f[n][j]>maximum){
	 maximum=f[n][j];
	 ccc=cc[n][j];
      }
      else if(f[n][j]==maximum){
	 ccc=(ccc+cc[n][j])%MOD;
      }
   }
   cout<<ccc<<endl;
   return 0;
}
