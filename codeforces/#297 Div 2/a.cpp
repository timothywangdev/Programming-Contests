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
string s;
int c[26];
int rv=0;
int main(){
   cin>>n>>s;
   memset(c,0,sizeof(c));
   for(int i=0;i<s.size();i+=2){
      c[s[i]-'a']++;
      char ch=s[i+1];
      int k=ch-'A';
      if(c[k]>0){
	 c[k]--;
      }
      else{
	 rv++;
      }
   }
   cout<<rv<<endl;
   return 0;
}
