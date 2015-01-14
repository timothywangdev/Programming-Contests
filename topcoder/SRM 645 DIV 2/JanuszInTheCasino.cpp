#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class JanuszInTheCasino {
public:
  LL n; 
  int m; 
  int k; 
  map<pair<LL,int>,double> mm;
  double f(LL n,int k){
    double rv;
    map<pair<LL,int>,double>::iterator it=mm.find(make_pair(n,k));
    if(it!=mm.end())return it->second;
    if(k==0||n==0){
      if(n==0){
	rv=0.0;
      }
      else{
	rv= (n>0)?1.0:0.0;
      }
    }
    else{
      if(n<=m){
      	rv=((double)(m-n)/m)*f(n,k-1)+((double)n/m)*f(n-1,k-1);
      }
       else{
	LL t=n/(LL)m;
	LL remain=n%(LL)m;
	rv=((double)(m-remain)/m)*f(n-t,k-1)+((double)remain/m)*f(n-t-1,k-1);
       }
    }
    mm[make_pair(n,k)]=rv;
    return rv;
  }
  double findProbability(LL n, int m, int k) {
    this->n = n; 
    this->m = m; 
    this->k = k;
    return f(n,k);
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
    { { 3, 2, 2 }, {0.75} },
      { { 1, 3, 3 }, {0.2962962962962962} },
	{ { 4, 3, 2 }, {1.0} },
	  { { 5, 4, 5 }, {0.87109375} },
	    { { 1000000000000, 2, 40 }, {0.9094947017729282} },
	      // Your custom test goes here:
	      //{ { , , }, {} },
	      };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
  LL p0;int p1;int p2;

  double run(JanuszInTheCasino* x) {
    return x->findProbability(p0,p1,p2);
  }
  void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
  return Tester::runTests<JanuszInTheCasino>(
					     getTestCases<input, Tester::output<double>>(), disabledTest, 
					     1000, 1421264015, CASE_TIME_OUT, Tester::COMPACT_REPORT
					     );
}
// CUT end
