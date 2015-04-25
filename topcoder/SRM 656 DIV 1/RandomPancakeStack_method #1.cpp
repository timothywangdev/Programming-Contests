#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class RandomPancakeStack {
public:
  double f[251][251];
  double expectedDeliciousness(vector<int> d) {
    double rv=0.0;
    int n=d.size();
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
      for(int j=0;j<=n-i;j++){
	for(int k=1;k<i;k++){
	  f[i][j]+=f[k][j+1]+d[i-1];
	}
	if(n-j-1!=0){
	  f[i][j]/=(double)(n-j-1);
	  f[i][j]+=((double)(n-i-j)/(n-j-1))*d[i-1];
	}
	else{
	  f[i][j]=d[i-1];
	}
	if(j==0){
	  rv+=f[i][j]/n;
	}
      }
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
    { { {1,1,1} }, {1.6666666666666667} },
      { { {3,6,10,9,2} }, {9.891666666666667} },
	{ { {10,9,8,7,6,5,4,3,2,1} }, {10.999999724426809} },
	  { { {1,2,3,4,5,6,7,8,9,10} }, {7.901100088183421} },
	    { { {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1} }, {19.368705050402465} },
	      { { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} }, {1.718281828459045} },
		// Your custom test goes here:
		//{ { {}}, {} },
		};}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
  vector<int> p0;

  double run(RandomPancakeStack* x) {
    return x->expectedDeliciousness(p0);
  }
  void print() { Tester::printArgs(p0); }
};
    
int main() {
  return Tester::runTests<RandomPancakeStack>(
					      getTestCases<input, Tester::output<double>>(), disabledTest, 
					      250, 1429820567, CASE_TIME_OUT, Tester::COMPACT_REPORT
					      );
}
// CUT end
