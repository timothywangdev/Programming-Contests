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
 
class CorruptedMessage {
    public:
        string s; 
        int k; 
        string reconstructMessage(string s, int k) {
          this->s = s; 
          this->k = k; 
    for(char ch='a'; ch<='z';ch++){
       int c=0;
       for(int i=0;i<s.size();i++){
          if(s[i]!=ch){
       c++;
          }
       }
       if(c==k){
          string rv="";
          for(int i=0;i<s.size();i++){
       rv=rv+ch;
          }
          return rv;
       }
    }
          return "";
    }
};
