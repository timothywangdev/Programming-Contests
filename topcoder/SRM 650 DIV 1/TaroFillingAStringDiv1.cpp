#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define MAXN 1000000001
#define MOD 1000000007
class TaroFillingAStringDiv1 {
public:
   int N; 
   vector<int> position; 
   string value; 
   int getNumber(int N, vector<int> position, string value) {
      this->N = N; 
      this->position = position; 
      this->value = value; 
      vector<PII> v;
      for(int i=0;i<position.size();i++){
	 v.push_back(make_pair(position[i],value[i]));
      }
      sort(v.begin(),v.end());
      for(auto i:v){
	 cout<<i.first<<" ";
      }
      cout<<endl;
      LL sum=1;
      for(int i=0;i<v.size()-1;i++){
	 if(v[i].second==v[i+1].second){
	    if((v[i+1].first-v[i].first)%2!=0){
	       sum*=v[i+1].first-v[i].first;
	    }
	 }
	 else{
	    if((v[i+1].first-v[i].first)%2==0){
	       sum*=v[i+1].first-v[i].first;
	    }
	 }
	 sum%=MOD;
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
      { { 3, {1,3}, "AB" }, {2} },
      { { 4, {2,1,3,4}, "ABBA" }, {1} },
      { { 25, {23,4,8,1,24,9,16,17,6,2,25,15,14,7,13}, "ABBBBABABBAAABA" }, {1} },
      { { 305, {183,115,250,1,188,193,163,221,144,191,92,192,58,215,157,187,227,177,206,15,272,232,49,11,178,59,189,246}, "ABAABBABBAABABBBBAAAABBABBBA" }, {43068480} },
	 // Your custom test goes here:
	 //{ { , {}, }, {} },
	 };}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
   int p0;vector<int> p1;string p2;

   int run(TaroFillingAStringDiv1* x) {
      return x->getNumber(p0,p1,p2);
   }
   void print() { Tester::printArgs(p0,p1,p2); }
};
    
int main() {
   return Tester::runTests<TaroFillingAStringDiv1>(
      getTestCases<input, Tester::output<int>>(), disabledTest, 
      250, 1427489301, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
