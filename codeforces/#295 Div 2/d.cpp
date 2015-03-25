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
#define debug(v) for(auto i:v){cout<<i<<" ";}cout<<endl;
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;
#define MAXN 100000
#define MOD 1000000009
PII a[MAXN];
int up[MAXN][3],down[MAXN][3];
int mo_up[3][2]={{-1,1},{0,1},{1,1}};
map<PII,int> toIndex;
int n;
set<int> s;
bool in_set[MAXN];
bool available(int k){
   int c;
   F(j,3){
      c=0;
      if(up[k][j]!=-1){
	 F(p,3){
	    if(down[up[k][j]][p]!=-1){
	       c++;
	    }
	 }
	 if(c==1)return false;
      }
   }
   return true;
}
void delete_cube(int k){
   F(j,3){
      if(up[k][j]!=-1){
	 down[up[k][j]][2-j]=-1;
      }
      if(down[k][j]!=-1){
	 up[down[k][j]][2-j]=-1;
      }
   }
}
void add_new(int k){
   F(j,3){
      if(down[k][j]!=-1){
	 if(available(down[k][j])&&!in_set[down[k][j]]){
	    s.insert(down[k][j]);
	    in_set[down[k][j]]=true;
	 }
      }
   }
}
int main(){
   memset(in_set,false,sizeof(in_set));
   memset(up,-1,sizeof(up));
   memset(down,-1,sizeof(down));
   cin>>n;
   F(i,n){
      cin>>a[i].first>>a[i].second;
      toIndex[a[i]]=i;
   }
   F(i,n){
      F(j,3){
	 int xx=a[i].first+mo_up[j][0];
	 int yy=a[i].second+mo_up[j][1];
	 map<PII,int>::iterator it=toIndex.find(mp(xx,yy));
	 if(it!=toIndex.end()){
	    up[i][j]=it->second;
	 }
	 xx=a[i].first+mo_up[j][0];
	 yy=a[i].second-mo_up[j][1];
	 it=toIndex.find(mp(xx,yy));
	 if(it!=toIndex.end()){
	    down[i][j]=it->second;
	 }
      }
   }
   F(i,n){
      if(available(i)){
	 s.insert(i);
	 in_set[i]=true;
      }
   }
   set<int>::iterator it;
   vector<int> rv;
   bool found;
   while(s.size()){
      found=false;
      while(s.size()){
	 it=s.end();
	 it--;
	 int v=*it;
	 s.erase(it);
	 in_set[v]=false;
	 if(available(v)){
	    rv.push_back(v);
	    delete_cube(v);
	    add_new(v);
	    found=true;
	 }
	 if(found)break;
      }
      if(!s.size())break;
      found=false;
      while(s.size()){
	 it=s.begin();
	 int v=*it;
	 s.erase(it);
	 in_set[v]=false;
	 if(available(v)){
	    rv.push_back(v);
	    delete_cube(v);
	    add_new(v);
	    found=true;
	 }
	 if(found)break;
      }
   }
   LL sum=0;
   for(auto i:rv){
      sum=((sum*(LL)n)%MOD+(LL)i)%MOD;
   }
   cout<<sum<<endl;
   return 0;
}
