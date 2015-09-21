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

LL a,b;
int main(){
   cin>>a>>b;
   if(a<b){
      cout<<"-1"<<endl;
      return 0;
   }
   if(a==b){
      cout<<a<<endl;
      return 0;
   }
   // Check if max(k) is an integer
   bool inte=false;
   if(a%b==0){
      if(((a/b)-1)%2==0){
	 inte=true;
      }
   }
   LL k;
   if(inte){
      k=((a/b)-1)/2;
   }
   else{
      k=floor((double(a)/double(b)-1.0)/2.0);
   }
   double rv=min(((double)(a-b))/(2*k),((double)(a+b))/(2+2*k));
   cout<<fixed<<setprecision(10)<<rv<<endl;
   return 0;
}
