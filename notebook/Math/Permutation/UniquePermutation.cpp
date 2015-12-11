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
class Solution {
public:
   int size;
   vector<vector<int> > rv;
   vector<int> cur;
   vector<LL> state;
   vector<int> mapping;
   void search(int pos){
      if(pos==size){
	 rv.pb(cur);
	 return;
      }
      for(int i=0;i<state.size();i++){
	 if(state[i]>0){
	    cur.pb(mapping[i]);
	    state[i]--;
	    search(pos+1);
	    state[i]++;
	    cur.pop_back();
	 }
      }
   }
    vector<vector<int> > permuteUnique(vector<int> &num) {
       size=num.size();
       sort(num.begin(),num.end());
       state.pb(1);
       mapping.pb(num[0]);
       for(int i=1;i<num.size();i++){
	  if(num[i]==mapping[mapping.size()-1]){
	     state[state.size()-1]++;
	  }
	  else{
	     state.pb(1);
	     mapping.pb(num[i]);
	  }
       }
       search(0);
       return rv;
    }
};
