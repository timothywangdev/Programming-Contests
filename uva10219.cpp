#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

LL N,K;
double digit;
int main(){
  while(cin>>N>>K){
    digit=0.0;
    if(K>N-K){
      K=N-K;
    }
    for(LL k=1;k<=Ky;k++){
      digit+=log10(N-K+k)-log10(k);
    }
    // cout<<ceil(digit)<<endl;
     cout<<floor(digit)+1<<endl;
  }
  return 0;
}
