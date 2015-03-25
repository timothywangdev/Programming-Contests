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
int n,m;


int main(){
   cin>>n>>m;
   if(n>=m){
      cout<<n-m<<endl;
      return 0;
   }
   int sum=0;
   while(m>n){
      if(m%2==0){
	 m/=2;
      }
      else{
	 m++;
      }
      sum++;
   }
   cout<<sum+n-m<<endl;
   return 0;
}
