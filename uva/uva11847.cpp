#include <iostream>
#include <cmath>
using namespace std;

int n;
int main(){
  while(cin>>n){
    if(!n)break;
    cout<<(int)log2(n)<<endl;
  }
  return 0;
}
