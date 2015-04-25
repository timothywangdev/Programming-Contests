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


class TheNicePair {
public:
  vector<int> A; 
  vector<int> primes;
  bitset<10000> bs;
  int count[1001][168];
  int c[168][50][50];
  void sieve(LL upperbound){
    int _sieve_size=upperbound+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(LL i=2;i<=_sieve_size;i++){
      if(bs[i]){
	for(LL j=i*i;j<=_sieve_size;j+=i){
	  bs[j]=0;
	}
	primes.push_back(i);
      }
    }
  }
  int solve(vector<int> A) {
    this->A = A; 
    sieve(1001);
    memset(count,0,sizeof(count));
    for(int i=2;i<=1000;i++){
      for(int j=0;j<primes.size();j++){
        if(i%primes[j]==0){
	  count[i][j]=1;
	}
      }
    }
    for(int k=0;k<primes.size();k++){
      for(int i=0;i<A.size();i++){
	c[k][i][i]=count[A[i]][k];
	for(int j=i+1;j<A.size();j++){
	  c[k][i][j]=c[k][i][j-1]+count[A[j]][k];
	}
      }
    }
    int rv=-1;
    for(int i=0;i<A.size();i++){
      for(int j=i;j<A.size();j++){

	bool found=false;
	for(int k=0;k<primes.size();k++){
	  if((j-i+1)%2==0){
	    if(c[k][i][j]>=(j-i+1)/2){
	      found=true;
	      break;
	    }
	  }
	  else{
	    if(c[k][i][j]>(j-i+1)/2){
	      found=true;
	      break;
	    }
	  }
	}
	if(found&&j-i>rv){
	  rv=j-i;
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
    { { {5,5,5,5,5} }, {4} },
     { { {1,1,1,1} }, {-1} },
    { { {2,3,5,7} }, {1} },
    { { {8,8,5,5,5} }, {4} },
	    { { {1,1000,1000,1,1000,1,999} }, {5} },
	       { { {1000,1,1,1000} }, {3} },
	      	{ { {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1} }, {15} },
		  // Your custom test goes here:
		  //{ { {}}, {} },
		  };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
  vector<int> p0;

  int run(TheNicePair* x) {
    return x->solve(p0);
  }
  void print() { Tester::printArgs(p0); }
};
    
int main() {
  return Tester::runTests<TheNicePair>(
				       getTestCases<input, Tester::output<int>>(), disabledTest, 
				       250, 1429977607, CASE_TIME_OUT, Tester::COMPACT_REPORT
				       );
}
// CUT end
