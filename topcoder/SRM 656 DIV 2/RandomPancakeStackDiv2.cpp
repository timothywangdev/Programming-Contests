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
 
class RandomPancakeStackDiv2 {
    public:
        vector<int> d; 
   double f[20][20][1001];
   bool vis[20][20][1001];
   double search(int n,int rem,int total){
      if(n==0||rem<0){
   return (double)total;
      }
      if(vis[n][rem][total])return f[n][rem][total];
      vis[n][rem][total]=true;
      double rv=0.0;
      for(int i=0;i<n;i++){
   if(i<=rem)
      rv+=(1/(double)n)*search(n-1,i-1,total+d[i]);
   else
      rv+=(1/(double)n)*total;
      }
      //cout<<n<<" "<<rem<<" "<<total<<" "<<rv<<endl;
      f[n][rem][total]=rv;
      return rv;
   }
   
 
        double expectedDeliciousness(vector<int> d) {
          this->d = d;
    memset(vis,false,sizeof(vis));
          return search(d.size(),d.size()-1,0);
    }
};
