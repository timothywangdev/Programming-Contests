#include <iostream>
#include <cmath>
using namespace std;

int n,k,offset;
int main(){
  while(cin>>n){
    if(!n)break;
    int k=log(n)/log(2);
    if(pow(2,k)==n){
      cout<<n<<endl;
    }
    else{
      offset=n-pow(2,k);
      cout<<offset*2<<endl;
    }
  }
  return 0;
}
