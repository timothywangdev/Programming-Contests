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
#define MAXN (LL)(1e5)
LL n,s,l,a,f[MAXN],INF=(LL)(1e10);
deque<pair<LL,LL> > s_min,s_max,f_min;
int main(){
   cin>>n>>s>>l;
   int tail=0;
   f_min.push_back(mp(0,-1));
   F(i,n){
      cin>>a;
      while(s_min.size()&&a<=s_min.back().first)s_min.pop_back();
      while(s_max.size()&&a>=s_max.back().first)s_max.pop_back();
      s_min.push_back(mp(a,i));s_max.push_back(mp(a,i));
      while(s_min.size()&&s_max.size()&&s_max.front().first-s_min.front().first>s){
	 tail++;
	 while(s_min.size()&&s_min.front().second<tail)s_min.pop_front();
	 while(s_max.size()&&s_max.front().second<tail)s_max.pop_front();
      }
      if(i-l+1<=0){
	 if(i-l+1==0)
	    f[i]=(tail==0)?1:INF;
	 else{
	    f[i]=INF;
	 }
	 continue;
      }
      while(f_min.size()&&f_min.back().first>=f[i-l])f_min.pop_back();
      f_min.push_back(mp(f[i-l],i-l));
      while(f_min.size()&&f_min.front().second<tail-1)f_min.pop_front();
      f[i]=f_min.size()?f_min.front().first:INF;
      f[i]=(f[i]!=INF)?f[i]+1:INF;
   }
   if(f[n-1]!=INF)
      cout<<f[n-1]<<endl;
   else 
      cout<<"-1"<<endl;
   return 0;
}
