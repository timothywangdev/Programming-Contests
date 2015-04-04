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

set<pair<LL,LL> > s;
int n;
LL x,w;
LL f[2000000];
vector<pair<LL,pair<LL,LL> > > a;
LL INF=(LL)1e18;
int main(){
   cin>>n;
   F(i,n){
      cin>>x>>w;
      a.push_back(mp(x+w,mp(x,w)));
   }
   sort(a.begin(),a.end());
   s.insert(mp(a[0].first,0));
   memset(f,0,sizeof(f));
   f[0]=1;
   LL rv=1;
   for(int i=1;i<n;i++){
      if(a[i].second.first-a[i].second.second<a[0].first){
	 f[i]=f[i-1];
	 s.insert(mp(a[i].first,i));
	 continue;
      }
      set<pair<LL,LL> >::iterator lower= s.upper_bound(mp(a[i].second.first-a[i].second.second,INF));
      lower--;
      f[i]=max(f[(*lower).second]+1,f[i-1]);
      rv=max(rv,f[i]);
      s.insert(mp(a[i].first,i));
   }
   cout<<rv<<endl;
   return 0;
}
