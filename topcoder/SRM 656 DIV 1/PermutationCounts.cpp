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
const LL MOD=(LL)(1e9+7);
/*
  Modular Exponentiation
  Computes (base^exp)MOD mod
*/

// O(log2(N))
LL pow_mod_base2(LL base, LL exp, LL mod){
  LL rv=1;
  base=base%mod;
  while(exp>0){
    if(exp&1){
      rv=(rv*base)%mod;
    }
    exp>>=1;
    base=(base*base)%mod;
  }
  return rv;
}
// Requires pow_mod_base2
// O(log(MOD))
LL inv(LL n,LL mod){
   assert(n!=0);
   return pow_mod_base2(n,mod-2,mod);
}
class PermutationCounts {
public:
  int N; 
  vector<int> pos; 
  LL a[2502];
  LL f[2502];
  LL factorial[1000001];
  LL finv[1000001];

  /* 
     C(n,k,mod) (a.k.a C(n,k) MOD mod)
     Assumptions:
     factorial[n]=(n!)MOD mod
     gcd(n!,mod)=1 and mod is a prime (Euler's theorem)
   
     Requires: inv()
     Time Complexity: O(log(mod))
  */
  /*
  LL C(LL n, LL k, LL mod){
    if(n<k)return 0;
    return factorial[n]*inv(factorial[n-k],mod)%mod*inv(factorial[k],mod)%mod;
  }
  */
  LL C(LL n, LL k, LL mod){
    if(n<k)return 0;
    return factorial[n]*finv[n-k]%mod*finv[k]%mod;
  }
  int countPermutations(int N, vector<int> pos) {
	    
    this->N = N; 
    this->pos = pos; 
    factorial[0]=1;
    for(int i=1;i<=1000000;i++){
      factorial[i]=(factorial[i-1]*i)%MOD;
    }
    const int T = 1000000;
    finv[0]=1;
    finv[T] = inv(factorial[T],MOD); //modular multiplicative inverse of 1000000! :/
    for (int i = T - 1; i >= 1; i--) {
        // n! = (n+1)! / n
        // 1/(n!) = n * (1 / (n+1)! ) 
        finv[i] = ( (i + 1) * finv[i+1]) % MOD;
    }
    int K=pos.size()+2;
    a[0]=0;
    for(int i=1;i<K-1;i++){
      a[i]=pos[i-1];
    }
    a[K-1]=N;
    sort(a,a+K);
    f[0]=1;
    for(int i=1;i<K;i++){
      bool positive=true;
      for(int j=i-1;j>=0;j--){
	LL t=(C(a[i],a[j],MOD)*f[j])%MOD;
	if(positive){
	  f[i]=(f[i]+t)%MOD;
	}
	else{
	  f[i]=(f[i]-t+MOD)%MOD;
	}
	positive=1-positive;
      }
    }
    return (int)f[K-1];
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
	      { { 875, {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,865,407,121,477,567,790,127,593,57,674,114,239,599,552,738} }, {169176190} },
		// Your custom test goes here:
		//{ { , {}}, {} },
		};}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
  int p0;vector<int> p1;

  int run(PermutationCounts* x) {
    return x->countPermutations(p0,p1);
  }
  void print() { Tester::printArgs(p0,p1); }
};
    
int main() {
  return Tester::runTests<PermutationCounts>(
					     getTestCases<input, Tester::output<int>>(), disabledTest, 
					     500, 1429927756, CASE_TIME_OUT, Tester::COMPACT_REPORT
					     );
}
// CUT end
