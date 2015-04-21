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
LL A,B,n,l,t,m;

LL sum(LL lo){
   return ((2*A+(lo-1)*B)*lo)/2;
}
LL sum(LL lo,LL hi){
   return sum(hi)-sum(lo-1);
}


int main(){
   cin>>A>>B>>n;
   F(i,n){
      cin>>l>>t>>m;
      LL lo=l,hi=1000000+1414214,mid;
      while(lo<hi){
	 mid=(lo+hi+1)/2;
	 if(sum(l,mid)<=t*m&&(A+(mid-1)*B)<=t){
	    lo=mid;	 }
	 else{
	    hi=mid-1;
	 }
      }
      if(sum(l,hi)<=t*m&&(A+(hi-1)*B)<=t){
	 cout<<hi<<endl;
      }
      else{
	 cout<<"-1"<<endl;
      }
   }
   return 0;
}
