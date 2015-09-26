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

vector<pair<LL,LL> > a;

LL m,s,n,d;
LL su[100000];

struct CMP{
   bool operator()(pair<LL,LL> left,pair<LL,LL> right){
      return left.first<right.first;
   }
   bool operator()(pair<LL,LL> left,LL right){
      return left.first<right;
   }
}cm;

int main(){
   cin>>n>>d;
   F(i,n){
      cin>>m>>s;
      a.pb(mp(m,s));
   }
   sort(a.begin(),a.end(),cm);
   F(i,n){
      if(i==0){
	 su[i]=a[i].second;
      }
      else{
	 su[i]=su[i-1]+a[i].second;
      }
   }
   vector<pair<LL,LL> >::iterator low;
   LL rv=0;
   F(i,n){
      low=lower_bound(a.begin(),a.end(),(LL)(a[i].first+d),cm);
      low--;
      LL pos=distance(a.begin(),low);
      LL k=i>0?su[pos]-su[i-1]:su[pos];
      rv=max(rv,k);
   }
   cout<<rv<<endl;
   return 0;
}
