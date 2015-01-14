#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;

LL N,M;
int main(){
  while(cin>>N>>M){
    if(!N&&!M)break;
    if(N>M){
      swap(N,M);
    }
    cout<<(2*(N-1)*(3*M-N-1)*N+3*N*M*(M+N-2))/3<<endl;
  }
  return 0;
}
