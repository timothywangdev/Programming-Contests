#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class PermutationCountsDiv2 {
    public:
        int N; 
        vector<int> pos; 
  bool mark[201];
  LL f[201][201];
  LL C[201][201];
  bool valid(int pos,int a,int b){
    if(pos==a){
      return !mark[pos];
    }
    if(pos==b){
      return mark[pos-1];
    }
    return mark[pos-1]&&!mark[pos];
  }
        int countPermutations(int N, vector<int> pos) {
	        this->N = N; 
	        this->pos = pos; 
		memset(mark,false,sizeof(mark));
		LL MOD=(LL)((1e9)+7);
		for(int i=0;i<pos.size();i++){
		  mark[pos[i]]=true;
		}
		for(int i=1;i<=N;i++){
		  f[i][1]=1;
		}
		for(int i=2;i<=N;i++){
		  for(int last=1;last<=N;last++){
		    f[i][last]=0;
		    if(mark[i-1]){
		      for(int j=1;j<last;j++){
			f[i][last]=(f[i][last]+f[i-1][j])%MOD;
		      }
		    }
		    else{
		      for(int j=last;j<=i-1;j++){
			f[i][last]=(f[i][last]+f[i-1][j])%MOD;
		      }
		    }
		  }
		}
		LL rv=0;
		for(int i=1;i<=N;i++){
		  rv=(rv+f[N][i])%MOD;
		}
		return rv;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 5, {3} }, {9} },
    { { 13, {12,11,10,9,8,7,6,5,4,3,2,1} }, {1} },
    { { 13, {} }, {1} },
    { { 9, {2,4,5} }, {1421} },
    { { 80, {31,41,59,26,53,58,9,79,32,3,8,46} }, {82650786} },
    // Your custom test goes here:
    //{ { , {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;vector<int> p1;

        int run(PermutationCountsDiv2* x) {
            return x->countPermutations(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<PermutationCountsDiv2>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1429640204, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
