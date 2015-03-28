#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

class SquareScores {
    public:
        vector<int> p; 
        string s; 
        double calcexpectation(vector<int> p, string s) {
	        this->p = p; 
	        this->s = s; 
		for(int i=p.size()+1;i<=26;i++){
		   p.push_back(0);
		}
		double sum=0.0;
		for(int i=0;i<s.size();i++){
		   for(int c=0;c<26;c++){
		      double t=1.0;
		      for(int j=i;j<s.size();j++){
			 if(s[j]=='?'){
			    t*=(double)p[c]/(double)100;
			 }
			 else if(s[j]!=(char)('a'+c)){
			    t*=0.0;
			    break;
			 }
			 else if(s[j]==(char)('a'+c)){
			    t*=1.0;
			 }
			 sum+=t;
		      }
		   }
		}
	        return sum;
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
    { { {1,99}, "aaaba" }, {8.0} },
    { { {10,20,70}, "aa?bbbb" }, {15.0} },
    { { {10,20,30,40}, "a??c?dc?b" }, {11.117} },
    { { {25,25,21,2,2,25}, "a??b???????ff??e" }, {21.68512690712425} },
    { { {4,4,4,3,4,4,4,4,4,4,3,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4}, "??????????????????????????????" }, {31.16931963781721} },
    { { {4,3,4,3,8,2,4,3,4,4,3,2,4,4,3,4,2,4,7,6,4,4,3,4,4,3}, "makigotapresentfromniko" }, {23.0} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;string p1;

        double run(SquareScores* x) {
            return x->calcexpectation(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SquareScores>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            250, 1427492142, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
