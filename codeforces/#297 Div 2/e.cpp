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
typedef long long LL;
typedef tuple<LL,LL,LL> TLLL;
typedef tuple<LL,LL> TLL;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;


LL N,K,S,a[26];
LL fac[19];
map<LL,LL> cnt[2][26];
void search(LL i,int k,LL sum,int s,int e,int idx){
   if(i>e){
      if(cnt[idx][k].count(sum))
	 cnt[idx][k][sum]+=1;
      else
	 cnt[idx][k][sum]=1;
      return;
   }
   search(i+1,k,sum,s,e,idx);
   if(sum+a[i]<=S)
      search(i+1,k,sum+a[i],s,e,idx);
   if(k+1<=K&&a[i]<=18){
      search(i+1,k+1,sum+fac[a[i]],s,e,idx);
   }
}
int main(){
   fac[0]=1;
   for(LL i=1;i<=18;i++){
      fac[i]=fac[i-1]*i;
   }
   cin>>N>>K>>S;
   F(i,N){
      cin>>a[i+1];
   }
   LL rv=0;
   int m=N/2+1;
   search(1,0,0,1,m,0);
   search(m+1,0,0,m+1,N,1);
   F(k,K+1){
      for(auto j:cnt[0][k]){
	 F(p,K-k+1){
	    if(cnt[1][p].count(S-j.first)){
	       //cout<<k<<" "<<j.first<<" "<<j.second<<endl;
	       rv+=j.second*cnt[1][p][S-j.first];
	    }
	 }
      }
   }
   cout<<rv<<endl;
   return 0;
}
