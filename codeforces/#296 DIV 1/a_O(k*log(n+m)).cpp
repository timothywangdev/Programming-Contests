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

LL w,h,n,k;
set<int> a[2];
set<pair<LL,pair<LL,LL> > > s[2];
int main(){
   cin>>w>>h>>n;
   char ch;
   a[0].insert(0);
   a[0].insert(w);
   a[1].insert(0);
   a[1].insert(h);
   s[0].insert(mp(w,mp(0,w)));
   s[1].insert(mp(h,mp(0,h)));
   F(i,n){
      cin>>ch>>k;
      if(ch=='V'){
	 set<int>::iterator upper=a[0].lower_bound(k);
	 set<int>::iterator lower=upper;
	 lower--;    
 	 a[0].insert(k);
	 set<pair<LL,pair<LL,LL> > >::iterator t=s[0].lower_bound(mp(*upper-*lower,mp(*lower,*upper)));
	 s[0].erase(t);
	 s[0].insert(mp(k-*lower,mp(*lower,k)));
	 s[0].insert(mp(*upper-k,mp(k,*upper)));
	 set<pair<LL,pair<LL,LL> > >::iterator aa,bb;
	 aa=s[0].end();
	 bb=s[1].end();
	 aa--;
	 bb--;
	 cout<<(*aa).first*(*bb).first<<endl;
      }
      else{
	 set<int>::iterator upper=a[1].lower_bound(k);
	 set<int>::iterator lower=upper;
	 lower--;    
	 a[1].insert(k);
	 set<pair<LL,pair<LL,LL> > >::iterator t=s[1].lower_bound(mp(*upper-*lower,mp(*lower,*upper)));
	 s[1].erase(t);
	 s[1].insert(mp(k-*lower,mp(*lower,k)));
	 s[1].insert(mp(*upper-k,mp(k,*upper)));
	 set<pair<LL,pair<LL,LL> > >::iterator aa,bb;
	 aa=s[0].end();
	 bb=s[1].end();
	 aa--;
	 bb--;
	 cout<<(*aa).first*(*bb).first<<endl;
      }
   }
   return 0;
}
