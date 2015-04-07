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

string s;
int m;
int a[200000];
void reverse2(int ss,int e1,int s2,int e2){
   ss--;
   e1--;
   s2--;
   e2--;
   for(int i=ss;i<=e1;i++){
      swap(s[i],s[s.size()-i-1]);
   }
}
void reverse(int ss,int e){
   ss--;
   e--;
   for(int i=ss;i<s.length()/2;i++){
      swap(s[i],s[s.size()-i-1]);
   }
}
int main(){
   cin>>s>>m;
   F(i,m){
      cin>>a[i];
   }
   sort(a,a+m);
   FR(i,m){
      if((i+1)%2==1){
	 if(i+1<m){
	    reverse2(a[i],a[i+1]-1,s.size()-a[i+1]+2,s.size()-a[i]+1);
	 }
	 else{
	    reverse(a[i],s.size()-a[i]+1);
	 }
      }
   }
   cout<<s<<endl;
   return 0;
}
