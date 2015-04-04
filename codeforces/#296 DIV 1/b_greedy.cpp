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
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;


int n;
LL x,w;
vector<pair<LL,LL> > v;
int main(){
   cin>>n;
   F(i,n){
      cin>>x>>w;
      v.pb(mp(x+w,x-w));
   }
   sort(v.begin(),v.end());
   PLL last=v[0];
   int rv=1;
   for(int i=1;i<n;i++){
      if(v[i].second>=last.first){
	 last=v[i];
	 rv++;
      }
   }
   cout<<rv<<endl;
   return 0;
}

