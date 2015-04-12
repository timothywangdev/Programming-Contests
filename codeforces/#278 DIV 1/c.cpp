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
LL inv[100000];
LL MOD;
int n;
int main(){
   cin>>n;
   MOD=n;
   inv[1]=1%MOD;
   for(int i=2;i<n;i++){
      inv[i]=MOD-(inv[MOD%i]*(MOD/i))%MOD;;
   }
   if(n<=4){
      cout<<"YES"<<endl;
      if(n==1){
	 cout<<"1"<<endl;
      }
      else if(n==2){
	 cout<<"1\n2"<<endl;
      }
      else if(n==3){
	 cout<<"1\n2\n3"<<endl;
      }
      else{
	 cout<<"1\n3\n2\n4"<<endl;
      }
      return 0;
   }
   for(int i=2;i*i<=n;i++){
      if(n%i==0){
	 cout<<"NO"<<endl;
	 return 0;
      }
   }
   cout<<"YES"<<endl;
   for(int i=1;i<n;i++){
      if(i==1){
	 cout<<"1"<<endl;
      }
      else{
	 cout<<(i*inv[i-1])%MOD<<endl;
      }
   }
   cout<<n<<endl;
   return 0;
}
