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
		for(int i=0;i<=N;i++){
		  for(int j=0;j<=i;j++){
		    if(i==0||j==0){
		      C[i][j]=1;
		      continue;
		    }
		    C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		  }
		}
		for(int i=0;i<pos.size();i++){
		  mark[pos[i]]=true;
		}
		for(int L=1;L<=N;L++){
		  for(int a=1;a+L-1<=N;a++){
		    int b=a+L-1;
		    f[a][b]=0;
		    if(L==1){
		      f[a][b]=1;
		      continue;
		    }
		    for(int i=a;i<=b;i++){
		      if(valid(i,a,b)){
			LL t1=(i-1>=a)?f[a][i-1]:1;
			LL t2=(i+1<=b)?f[i+1][b]:1;
			LL t=(((t1*t2)%MOD)*C[b-a][i-a])%MOD;
			f[a][b]=(f[a][b]+t)%MOD;
		      }
		    }
		  }
		}
	        return f[1][N];
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
