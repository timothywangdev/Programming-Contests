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

class TheTips {
    public:
        vector<string> clues; 
        double solve(vector<string> clues, vector<int> p) {
	        this->clues = clues; 
	        double rv=0.0;
		F(k,clues.size()){
		  F(i,clues.size()){
		    F(j,clues.size()){
		      clues[i][j]=(clues[i][j]=='Y')?'Y':(clues[i][k]=='Y'&&clues[k][j]=='Y')?'Y':'N';
		    }
		  }
		}
		F(i,clues.size()){
		  double t=1.0;
		  F(j,clues.size()){
		    if(i!=j&&clues[j][i]=='Y'){
		      t*=(double)(100-p[j])/100.0;
		    }
		  }
		  rv+=1-t*(double)(100-p[i])/100.0;
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
     { { {"Y"}, {50} }, {0.5} },
     { { {"YN","NY"}, {100,50} }, {1.5} },
     { { {"YYY","NYY","NNY"}, {100,0,0} }, {3.0} },
     { { {"NNN","NNN","NNN"}, {0,0,0} }, {0.0} },
       { { {"NYYNYYNNNN","NNNNYNNNYN","YNNYYYYYNN","YYNYNNNNYN","NYNNNNNNNY","YNYYNNYNNY","NYNNYYYYYY","NYYYYNNNNN","YYNYNNYYYN","NNYYNYNYYY"}, {11,66,99,37,64,45,21,67,71,62} }, {9.999891558057332} },
	  { { {"NNY","NNY","NNN"}, {50,50,1} }, {1.7525} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;vector<int> p1;

        double run(TheTips* x) {
            return x->solve(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<TheTips>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            500, 1429979442, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
