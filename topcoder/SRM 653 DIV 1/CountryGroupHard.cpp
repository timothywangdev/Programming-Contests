#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class CountryGroupHard {
    public:
        vector<int> a;
   int ok[101];
   bool check(int from,int to,int v){
      if(from<0)return false;
      for(int i=from+1;i<=to;i++){
	 if(!(a[i-1]==0||a[i-1]==v))return false;
      }
      return true;
   }
        string solve(vector<int> a) {
	        this->a = a;
		memset(ok,false,sizeof(ok));
		ok[0]=true;
		int j;
		for(int i=1;i<=a.size();i++){
		   if(a[i-1]!=0){
		      j=i-a[i-1];
		      if(check(j,i,a[i-1])){
			 ok[i]=ok[j];
		      }
		   }
		   int c=0,c1=0;
		   for(int k=1;k<=100;k++){
		      if(check(i-k,i,k)){
			 if(ok[i-k]==1)c++;
			 if(ok[i-k]==2)c1++;
		      }
		   }
		   if(c==1&&c1==0){
		      ok[i]=1;
		   }
		   else if((c1>0)||(c>1)){
		      ok[i]=2;
		   }
		}
		if(ok[a.size()]==1){
		   return "Sufficient";
		}
		else{
		   return "Insufficient";
		}
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
      { { {0,2,3,0,0} }, {"Sufficient"} },
      { { {0,2,0} }, {"Insufficient"} },
      { { {0,3,0,0,3,0} }, {"Sufficient"} },
      { { {0,0,3,3,0,0} }, {"Insufficient"} },
      { { {2,2,0,2,2} }, {"Sufficient"} },
      { { {0,0,0} }, {"Insufficient"} },
      { { {0} },{"Sufficient"} },
    { { {10, 0, 0, 0, 10, 10, 0, 0, 10, 10, 10, 0, 10, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 10, 0, 0, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 0, 10, 0, 10, 0, 0, 0, 10, 10, 10, 0, 10, 10, 10, 0, 0, 10, 10, 0, 10, 0, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 10, 10, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 10, 10, 0, 10, 10, 10, 0, 10, 10, 0} },{"Insufficient"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        string run(CountryGroupHard* x) {
            return x->solve(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CountryGroupHard>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1426590005, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
