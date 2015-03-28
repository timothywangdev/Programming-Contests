#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class SuccessiveSubtraction2 {
public:
   vector<int> a; 
   vector<int> p; 
   vector<int> v; 
   vector<int> calc(vector<int> a, vector<int> p, vector<int> v) {
      this->a = a; 
      this->p = p; 
      this->v = v; 
      vector<int> rv;
      LL f[2000][3][3];
      memset(f,-15,sizeof(f));
      for(int i=0;i<p.size();i++){
	 a[p[i]]=v[i];
	 for(int j=a.size()-1;j>=0;j--){
	    for(int open=0;open<=2;open++){
	       for(int used=0;used<=2;used++){
		  int sign=1;
		  if(open%2==1)sign=-1;
		  if((j==0&&used>0)||(used>=j&&used>0)||(open>used)){
		     continue;
		  }
		  if(j==a.size()-1){
		     if(j==0){
			f[j][open][used]=sign*a[j];
			continue;
		     }
		     f[j][open][used]=(-1)*sign*a[j];
		     continue;
		  }
		  f[j][open][used]=f[j+1][open][used];
		  if(open-1>=0){
		     f[j][open][used]=max(f[j][open][used],f[j+1][open-1][used]);
		  }
		  if(open-2>=0){
		     f[j][open][used]=max(f[j][open][used],f[j+1][open-2][used]);
		  }
		  if(open+1<=2&&used<2){
		     f[j][open][used]=max(f[j][open][used],f[j+1][open+1][used+1]);
		  }
		  if(j!=0)
		     f[j][open][used]+=(-1)*sign*a[j];
		  else
		     f[j][open][used]+=sign*a[j];
	       }
	    }
	 }
	 rv.push_back(f[0][0][0]);
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
       { { {1,2,3,4,5}, {1,2,0,4,3}, {3,9,-10,5,1} }, { {10,16,5,5,2} } },
       { { {-100,-100,-100,-100,-100}, {0,1,2,3,4}, {0,0,0,0,0} }, { {400,300,200,100,0} } },
       { { {83,0,25,21}, {0,3,2,1,3,1,2}, {10,-90,33,52,-100,0,45} }, { {56,125,133,81,91,143,155} } },
       { { {1}, {0,0,0,0}, {10,-10,100,-100} }, { {10,-10,100,-100} } },
       { { {-11,-4,28,38,21,-29,-45,11,-58,-39,92,35,-56,-6,29,-2,61,10,-29,-63}, {19,5,3,10,4,18,5,2,0,15}, {-19,21,7,-66,38,-39,-22,24,-32,13} }, { {451,443,412,440,457,467,468,464,443,458} } },
      // Your custom test goes here:
      { { {-24,25}, {0}, {-24} }, { {-49} } },
   };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
   vector<int> p0;vector<int> p1;vector<int> p2;

   vector<int> run(SuccessiveSubtraction2* x) {
      return x->calc(p0,p1,p2);
   }
   void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
   return Tester::runTests<SuccessiveSubtraction2>(
      getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
      450, 1427504639, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
