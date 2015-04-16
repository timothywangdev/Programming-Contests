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

int n;
int main(){
   cin>>n;
   if(n==1){
      cout<<"1\n1"<<endl;
   }
   else if(n==2){
      cout<<"1\n1"<<endl;
   }
   else if(n==3){
      cout<<"2\n1 3"<<endl;
   }
   else{
      cout<<n<<endl;
      if(n%4==3||n%4==1||n%4==2){
	 if(n%4==1||n%4==2)
	    cout<<n<<" ";
	 else{
	    cout<<n-1<<" ";
	 }
      }
      for(int i=1;i+3<=n;i+=4){
	 cout<<i+2<<" "<<i<<" "<<i+3<<" "<<i+1<<" ";
      }
      if(n%4==3){
	 cout<<n<<" "<<n-2<<" ";
      }
      if(n%4==2){
	 cout<<n-1;
      }
      
   }
   return 0;
}
