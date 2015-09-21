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

struct Cmp {
  bool operator() (const pair<int,PII>& lhs, const pair<int,PII>& rhs) const
  {return lhs.first>rhs.first;}
};

set<pair<int,PII>,Cmp> s;
bool used[801];
int rv[801];
int n,k;
int main(){
   cin>>n;
   memset(used,false,sizeof(used));
   for(int i=2;i<=2*n;i++){
      for(int j=1;j<i;j++){
	 cin>>k;
	 s.insert(mp(k,mp(i,j)));
      }
   }
   while(!s.empty()){
      set<pair<int,PII>,Cmp>::iterator it=s.begin();
      if(!used[it->second.first]&&!used[it->second.second]){
	 rv[it->second.first]=it->second.second;
	 rv[it->second.second]=it->second.first;
	 used[it->second.first]=used[it->second.second]=true;
      }
      s.erase(it);
   }
   for(int i=1;i<=2*n;i++){
      cout<<rv[i];
      if(i!=2*n){
	 cout<<" ";
      }
   }
   cout<<endl;
   return 0;
}
