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
int n;
bool used[26];
int main(){
   cin>>n>>s;
   memset(used,false,sizeof(used));
   F(i,s.length()){
      if(R('a',s[i],'z'))used[s[i]-'a']=true;
      if(R('A',s[i],'Z'))used[s[i]-'A']=true;
   }
   F(i,26){
      if(!used[i]){
	 cout<<"NO"<<endl;
	 return 0;
      }
   }
   cout<<"YES"<<endl;
   return 0;
}
